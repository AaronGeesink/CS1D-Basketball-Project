#include "database.h"

void createDatabase()
{
	QSqlDatabase::addDatabase("QSQLITE");
	QSqlDatabase db;
	db = QSqlDatabase::database();
	// Load database from file
    QString path = qApp->applicationDirPath();

    const QString DB_PATH = path + "/resources/database.db";
	db.setDatabaseName(DB_PATH);
}

bool checkConnection()
{
	// Initialize a database object and assign it to  our open database
	QSqlDatabase db;
	db = QSqlDatabase::database();

	// Check if database loaded
	if(!db.open())
	{
		qDebug("Failed to load SQL Database");
		return false;
	}
	else
	{
		qDebug("Connected to SQL database");
		return true;
	}
}
