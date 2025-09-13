#include <iostream>
#include <unistd.h>   // fork, getpid, getppid
#include <sys/wait.h> // waitpid
using namespace std;

int global = 1; // Global variable

int main()
{
    int var = 1; // Local variable
    pid_t pid = fork();

    if (pid < 0)
    {
        cerr << "fork failed!" << endl;
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        global++;
        var++;
        cout << "This is the Child Process." << endl;
        cout << "PID: " << getpid() << " (PPID: " << getppid() << ")"<< ", global: " << global << ", var: " << var << endl;
        _exit(0); // child exits safely
    }
    else
    {
        // Parent process
        waitpid(pid, nullptr, 0); // Wait for child waitpid(pid, &status, 0);  0 means block until child exits
        cout << "This is the Parent Process." << endl;
        cout << "PID: " << getpid() << ", global: " << global << ", var: " << var << endl;
    }

    return 0;
}
