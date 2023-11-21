
#include<iostream>

#include "todo_list.h"
#include "console.h"

void Todo_List::print()
{
	std::cout << "ToDo List:\n";
	std::cout << "------------\n";
	for (int i=0; i < list.size(); i++)
	{
		std::cout << i + 1 << ". " << list[i] << "\n";
	}
}

void Todo_List::get_new_item()
{
	std::string item;
	std::cout << "New Task: ";
	std::cin >> item;
	add_item(item);
	ClearScreen();
	print();
}

void Todo_List::user_delete_item(int n)
{
	remove_item(n - 1);
}

void Todo_List::add_item(std::string item)
{
	list.push_back(item);
}

void Todo_List::remove_item(int n)
{
	list.pop_back();
}