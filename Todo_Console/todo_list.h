#pragma once
#include<vector>
#include<string>

class Todo_List
{
public:
	void print();
	void get_new_item();
	void user_delete_item(int n);

private:
	std::vector<std::string> list = {};

// Temporarily public for the sake of development
public:
	void add_item(std::string item);
	void remove_item(int n);
};