#include <iostream>
#include <string>
#include <unistd.h> // for pipe() and close()

// This program demonstrates how to use a pipe in Linux.

int main()
{
    int pipe_fd[2];

    // 创建管道
    if (pipe(pipe_fd) == -1)
    {
        std::cerr << "Failed to create pipe" << std::endl;
        return 1;
    }

    std::cout << "before fork" << std::endl;
    // 创建子进程
    pid_t pid = fork();
    std::cout << "after fork" << pid << std::endl;

    if (pid == -1)
    {
        std::cerr << "Failed to fork process" << std::endl;
        return 1;
    }

    if (pid == 0)
    {
        // 子进程
        close(pipe_fd[1]); // 关闭写端
        char buffer[256];

        std::cout << "before read" << pid << std::endl;
        // 从管道读取数据
        read(pipe_fd[0], buffer, sizeof(buffer));
        std::cout << "after read" << pid << std::endl;

        std::cout << "Child process received: " << buffer << std::endl;
        close(pipe_fd[0]); // 关闭读端
    }
    else
    {
        // 父进程
        close(pipe_fd[0]); // 关闭读端
        std::string message = "Hello from parent process";

        // 向管道写入数据
        std::cout << "before write" << pid << std::endl;
        write(pipe_fd[1], message.c_str(), message.size());
        std::cout << "after write" << pid << std::endl;
        close(pipe_fd[1]); // 关闭写端
    }

    return 0;
}