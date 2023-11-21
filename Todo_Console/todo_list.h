#pragma once
#include<vector>
#include<string>

class Todo_List
{
public:
	void init();
	void get_new_item();
	void user_remove_item();

private:
	std::vector<std::string> list = {};

	void print();

// Not sure if I need these functions but I'm keeping them for now
public:
	void add_item(std::string item);
	void remove_item(int n);
};