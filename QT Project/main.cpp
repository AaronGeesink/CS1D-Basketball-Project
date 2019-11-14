#include "mainwindow.h"
#include "database.h"

#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
	// Initial setup
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	createDatabase();
	checkConnection();

    return a.exec();
}
