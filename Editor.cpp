#		include "Editor.h"


Editor::Editor()
	:currentPosition(0),
	iterator(list.begin())
{
}

void Editor::open(std::string name)
{
	fileName = name;
}

void Editor::insert(std::vector<char*>& lines)
{
	list.insertBefore(iterator,lines);
	currentPosition += lines.size();
	saveData();
}

void Editor::remove() 
{
	list.removeAt(iterator);
	saveData();
}

void Editor::move(int steps)
{
	if(steps < 0)
	{
		currentPosition = std::max(currentPosition+steps,0);
		iterator = list.findPosition(currentPosition);
	} else {
		currentPosition = std::min(currentPosition+steps,list.getLineCount());
		iterator = list.findPosition(currentPosition);
	}
	std::cout << (*iterator) << std::endl;
}

void Editor::listAll()
{
	list.printFrom(iterator);
}

void Editor::saveData()
{
	if(fileName.length() > 0)
	{
		out.open(fileName,std::ios::out|std::ios::trunc);
		LineIterator it = list.begin();
		while(it != list.end())
		{
			out << (*it) << std::endl;
			++it;
		}
		out.close();
	}
}