#include <iostream>
#include <string>
#include <unistd.h>

int main()
{
    std::string message = "Hello, World!";
    int pipe_fd[2];
    pipe(pipe_fd);

    // Writing to the pipe
    write(pipe_fd[1], message.c_str(), message.size() + 1);

    // Reading from the pipe
    char buffer[1024];
    read(pipe_fd[0], buffer, 1024);
    std::cout << "Received message: " << buffer << std::endl;

    // Closing the pipe
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    return 0;
}