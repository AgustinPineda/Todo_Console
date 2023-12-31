
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
	init();
	std::string item;
	std::cout << "New Task: ";
	//std::cin.get();
	std::getline(std::cin, item);
	add_item(item);
	init();
}

void Todo_List::user_remove_item()
{
	init();
	int n;
	std::cout << "# of item to remove: ";
	std::cin >> n;
	if ( n < 1 || list.size() < n )
	{
		init();
		std::cout << "That task doesn't exist!\n";
		return;
	}
	remove_item(n - 1);
	init();
}

void Todo_List::init()
{
	ClearScreen();
	print();
	std::cout << "\n";
}

void Todo_List::add_item(std::string item)
{
	list.push_back(item);
}

void Todo_List::remove_item(int n)
{
	list.erase(list.begin() + n);
}