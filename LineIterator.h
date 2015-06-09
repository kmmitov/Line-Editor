#pragma once

#include "Line.h"
#include "LineList.h"


class LineList;

class LineIterator 
{
	Line* currentLine;
	friend LineList;
public:
	LineIterator(Line* curr)
		:currentLine(curr)
	{
	}

	operator bool() const
	{
		return currentLine != NULL;
	}

	LineIterator& operator++()
	{
		if(currentLine!=NULL)
		{
			currentLine = currentLine->nextLine;
		}
		return *this;
	}

	LineIterator operator++(int)
	{
		LineIterator result = *this;
		++(*this);
		return result;
	}

	bool operator==(LineIterator const& other)
	{
		return this->currentLine == other.currentLine;
	}

	bool operator!=(LineIterator const& other)
	{
		return !(this->operator==(other));
	}

	void moveForward(int steps)
	{
		for(int i=1; i <= steps; i++)
		{
			this->operator++();
		}
	}

	char* operator*() const
	{
		return currentLine->text;
	}
};

