#pragma once
#include <fstream>
#include <iostream>
#include "LineList.h"
class Editor
{
	std::string fileName;
	LineList list;

	int currentPosition;
	LineIterator iterator;
	std::ofstream out;
public:
	Editor();

	void open(std::string);
	void insert(std::vector<char*>&);
	void remove();
	void move(int);
	void listAll();

	void saveData();
private:
	
};

