#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <sys/ioctl.h>

using namespace std;

int getTerminalWidth()
{
    struct winsize;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

int main()
{
    int rows = 30;
    printPattern();
    return 0;
}