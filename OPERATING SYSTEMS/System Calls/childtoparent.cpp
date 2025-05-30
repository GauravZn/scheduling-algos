// File: child_to_parent.cpp
#include <iostream>
#include <unistd.h>
#include <cstring>
using namespace std;

int main() {
    int fd[2];
    pipe(fd);

    pid_t pid = fork();
    if (pid == 0) {  // Child
        close(fd[0]);
        const char* msg = "Message from Child";
        write(fd[1], msg, strlen(msg) + 1);
        close(fd[1]);
    } else if (pid > 0) {  // Parent
        close(fd[1]);
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        cout << "Parent received: " << buffer << endl;
        close(fd[0]);
    } else {
        perror("fork");
        return 1;
    }
    return 0;
}
