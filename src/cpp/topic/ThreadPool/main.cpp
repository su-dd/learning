// #include <QCoreApplication>
// #include <QDebug>
#include "threadpool.h"
#include <random>
#include <chrono>
#include <iostream>

std::random_device rd;                                // 真实随机数产生器
std::mt19937 mt(rd());                                // 生成计算随机数mt
std::uniform_int_distribution<int> dist(-1000, 1000); // 生成-1000到1000之间的离散均匀分布数
auto rnd = std::bind(dist, mt);
void simulate_hard_computation() // 设置线程睡眠时间
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000 + rnd()));
}

// 结果返回
int multiply_return(const int a, const int b)
{
    simulate_hard_computation();
    const int res = a * b;
    std::cout << a << " * " << b << " = " << res << std::endl;
    return res;
}

int main(int argc, char *argv[])
{
    ThreadPool pool;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "add task to thread pool" << std::endl;
    for (int i = 1; i < 2; i++)
    {
        auto future = pool.addTask(multiply_return, i, i + 1);
    }
    pool.wait();
    return 0;
}
