#pragma once
#include <cstring>
#include <cstddef>

const int MAX_LINE_SIZE = 80;

struct Line 
{
	char text[MAX_LINE_SIZE];
	Line* nextLine;

	Line(const char _text[], Line* _next = NULL)
		:nextLine(_next)
	{
		strcpy(text,_text);
	}
};
