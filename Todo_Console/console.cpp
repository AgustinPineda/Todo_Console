#include "console.h"

void ClearScreen()
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
}

std::string GetUserCommand()
{
    std::string command;
    std::cout << "Enter Command: ";
    std::getline(std::cin, command);
    return(command);
}

void PrintHelp()
{
    std::cout << "Keep track of your tasks in this simple console app \n\n";
    std::cout << "Commands:\n";
    std::cout << "help - See a list of commands and instructions.\n";
    std::cout << "new - Add a new task.\n";
    std::cout << "remove - Remove a finished or unneeded task by number.\n";
    std::cout << "exit - Exit the program.\n";
    std::cout << "\n";
}