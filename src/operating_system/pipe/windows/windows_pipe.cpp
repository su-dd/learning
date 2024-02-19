#include <iostream>
#include <windows.h>
#include <string>

int main()
{
    std::cout << "Hello, server" << std::endl;

    HANDLE pipe_read, pipe_write;
    DWORD bytes_written, bytes_read;
    // 创建无名管道
    bool success = CreatePipe(&pipe_read, &pipe_write, NULL, 0);
    if (!success)
    {
        std::cout << "Failed to create pipe" << std::endl;
        return 1;
    }
    std::cout << "Pipe created successfully" << std::endl;

    // 写入数据到管道
    std::string message = "Hello from parent process";

    success = WriteFile(pipe_write, message.c_str(), message.size(), &bytes_written, NULL);
    if (!success)
    {
        std::cout << "Failed to write to pipe" << std::endl;
    }

    char buffer[10];
    // 从管道读取数据
    success = ReadFile(pipe_read, buffer, sizeof(buffer), &bytes_read, NULL);
    if (success)
    {
        std::cout << "Received message: " << buffer << std::endl;
    }
    else
    {
        std::cout << "Failed to read from pipe" << std::endl;
    }
    // 关闭管道
    CloseHandle(pipe_read);
    CloseHandle(pipe_write);
    return 0;
}