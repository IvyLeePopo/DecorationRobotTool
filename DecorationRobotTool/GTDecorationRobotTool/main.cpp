#include "gtdecorationrobottool.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GTDecorationRobotTool w;
	w.show();
	return a.exec();
}
