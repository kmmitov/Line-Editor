#include "EditorUI.h"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

EditorUI::EditorUI(istream& is)
	:in(is)
{
}


void EditorUI::run()
{
	char* buffer = new char[MAX_LINE_SIZE+1];
	do
	{
		in >> buffer;
		if(strncmp(buffer,"IN",2)==0) {
			//премахваме остатъчния ред
			in.getline(buffer,MAX_LINE_SIZE);

			std::vector<char*> lines;
			char line[MAX_LINE_SIZE+1];
			in.getline(line,MAX_LINE_SIZE);

			while(strncmp(line,"//",2)!=0) {
				char* tmp = new char[strlen(line)+1];
				strcpy(tmp,line);
				lines.push_back(tmp);

				in.getline(line,MAX_LINE_SIZE);
			}

			editor.insert(lines);
			clean(lines);

		} else if(strncmp(buffer,"DE",2)==0) {
			editor.remove();

		} else if(strncmp(buffer,"MO",2)==0) {
			int offset;
			in >> offset;
			editor.move(offset);
		} else if(strncmp(buffer,"LA",2)==0) {
			editor.listAll();
		} else if(strncmp(buffer,"OP",2)==0) {
			string fileName;
			in >> fileName;
			editor.open(fileName);
		}
	}
	while(strncmp(buffer,"EX",2)!=0);
	delete buffer;
	editor.saveData();
	exit(0);
}

void EditorUI::clean(std::vector<char*>& vect)
{
	for(int i=0; i < vect.size(); i++)
		delete vect[i];
}