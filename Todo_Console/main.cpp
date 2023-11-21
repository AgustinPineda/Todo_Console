// Todo_Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>

#include "console.h"
#include "todo_list.h"

int main()
{
    Todo_List my_list;

    my_list.add_item("Buy Groceries");
    my_list.add_item("Take out trash");
    my_list.add_item("Go Outside");

    my_list.init();

    //TODO: See if I can convert command to an enum to allow switch-case statement
    while (true)
    {
        std::string command = GetUserCommand();
        
        if (command == "help") { my_list.init(); PrintHelp(); }

        else if (command == "new") my_list.get_new_item();

        else if (command == "remove") my_list.user_remove_item();

        else if (command == "exit") { ClearScreen(); break; }

        // Trying to take care of the case where user types nothing and presses enter.
        else if (command == "")
        {
            my_list.init();
        }

        else
        {
            my_list.init();
            std::cout << "Please Enter a Valid Command.\n";
            std::cout << "Use \'help\' for a list of commands\n";
            std::cout << "or use \'exit\' to exit the app.\n";
        }
    }
    //TODO: Add save/load functionality
}

