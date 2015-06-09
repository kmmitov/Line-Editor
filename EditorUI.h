#pragma once
#include "Editor.h"
#include <fstream>
#include <iostream>
using namespace std;
class EditorUI
{
	Editor editor;
	istream& in;
public:
	EditorUI(istream& =cin);
	void run();

private:
	void clean(std::vector<char*>&);
};

