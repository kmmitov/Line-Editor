#include "LineList.h"
#include <iostream>

LineList::LineList()
	:size(0)
{
	sentinel = new Line("<<END>>");
	beginning = sentinel;
}

LineList::LineList(LineList const& other)
	:size(0)
{
	sentinel = new Line("<<END>>");
	beginning = sentinel;
	copy(other);
}

LineList& LineList::operator=(LineList const& other)
{
	if(this!=&other)
	{
		clean();
		copy(other);
	}
	return *this;
}

LineList::~LineList()
{
	clean();
}


LineIterator LineList::findPosition(int position) const
{
	if(position <= 0)
		return LineIterator(beginning);
	if(position >= size)
		return LineIterator(sentinel);
	Line* curr = beginning;
	for(int i=0; i < position; i++)
	{
		curr = curr->nextLine;
	}
	return LineIterator(curr);
}

void LineList::removeAt(LineIterator& it)
{
	if(!it || size == 0 || it == this->end()) {
		std::cerr << "Invalid position: " << std::endl;
		return;
	}
	if(it == this->begin())
	{
		Line* toDelete  = beginning;
		beginning = beginning->nextLine;
		++it;
		delete toDelete;
		
		size--;
		return;
	}
	Line* prev = previous(it);
	Line* toDelete = it.currentLine;
	++it;
	prev->nextLine = toDelete->nextLine;
	delete toDelete;
	size--;
}

void LineList::printFrom(LineIterator& it) const
{
	Line* curr = it.currentLine;
	while(curr!=NULL)
	{
		std::cout << curr->text << std::endl;
		curr = curr->nextLine;
	}
}

void LineList::insertBefore(LineIterator& it,
							std::vector<char*>& lines)
{
	if(!it || lines.size() == 0) {
		std::cerr << "Error - Invalid position or 0 new lines: " << std::endl;
		return;
	}
	if(it == this->begin())
	{
		Line* next = beginning;
		beginning = new Line(lines[0]);
		Line* curr = beginning;
		for(int i=1; i < lines.size(); i++)
		{
			Line* tmp = new Line(lines[i]);
			curr->nextLine = tmp;
			curr = tmp;
		}
		curr->nextLine = next;
		size += lines.size();
		return;
	} 
	Line* prev = previous(it);
	for(int i=0; i < lines.size(); i++)
	{
		Line* tmp = new Line(lines[i]);
		prev->nextLine = tmp;
		prev = tmp;
	}
	prev->nextLine = it.currentLine;
	size += lines.size();

}

Line* LineList::previous(LineIterator& it) const
{
	Line* curr = beginning;
	while(curr && curr->nextLine!=it.currentLine)
		curr = curr->nextLine;
	return curr;
}


void LineList::clean()
{
	Line* curr = beginning;
	Line* next;
	while(curr!=NULL)
	{
		next = curr->nextLine;
		delete curr;
		curr = next;
	}
}

void LineList::copy(LineList const& other)
{
	beginning = other.beginning;
	Line* curr = beginning;
	Line* toCopy = other.beginning->nextLine;
	while(toCopy!=NULL)
	{
		Line* tmp = new Line(toCopy->text);
		curr->nextLine = tmp;
		curr = tmp;
		toCopy = toCopy->nextLine;
	}
	sentinel = curr;
	size = other.size;
}