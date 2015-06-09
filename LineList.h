#pragma once
#include <cstring>
#include <cstddef>
#include <vector>
#include "Line.h"
#include "LineIterator.h"

class LineList
{
	Line* beginning;
	Line* sentinel;
	int size;
	//friend LineIterator;
public:
	LineList();
	LineList(LineList const&);
	LineList& operator=(LineList const&);
	~LineList();
	
	LineIterator begin() const { return LineIterator(beginning); }
	LineIterator end() const { return LineIterator(sentinel); }

	LineIterator findPosition(int) const;
	void insertBefore(LineIterator& , 
					std::vector<char*>&);
	void removeAt(LineIterator&);
	void printFrom(LineIterator&) const;

	int getLineCount() const { return size; }
private:
	void copy(LineList const&);
	void clean();
	Line* previous(LineIterator& it) const;
};

/*
*/