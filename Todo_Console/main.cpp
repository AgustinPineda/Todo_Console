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

    my_list.init();

    //TODO: Fix user input to allow spaces for tasks
    //TODO: See if I can convert command to an enum to allow switch-case statement
    while (true)
    {
        std::string command = GetUserCommand();
        
        if (command == "new") my_list.get_new_item();

        else if (command == "remove") my_list.user_remove_item();

        else if (command == "exit") break;
    }
    //TODO: Add save/load functionality
}

