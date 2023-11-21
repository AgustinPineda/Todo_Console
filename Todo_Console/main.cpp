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

    my_list.print();

    std::string command = GetUserCommand();

    if (command == "add")
    {
        my_list.get_new_item();
    }
}

