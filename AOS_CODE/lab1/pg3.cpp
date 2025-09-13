#include <iostream>
#include <csignal>  // signal
#include <unistd.h> // sleep, getpid
using namespace std;

void sigHandler(int signo)
{
    cout << "\nI received a signal " << signo
         << " (SIGINT). Next Ctrl+C will terminate.\n";
    // Restore default action
    signal(SIGINT, SIG_DFL);
}

int main()
{
    // Register handler for SIGINT
    signal(SIGINT, sigHandler);

    while (true)
    {
        cout << "Hello to BITS! (PID = " << getpid() << ")\n";
        sleep(1);
    }

    return 0;
}
