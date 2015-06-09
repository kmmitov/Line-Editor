#include "EditorUI.h"

int main()
{
	ifstream in("example.txt");
	EditorUI app(in);
	app.run();
	return 0;
}