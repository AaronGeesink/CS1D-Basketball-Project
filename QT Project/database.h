#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QFile>
#include <QDir>

/**
 * @author Garrett Geesink
 * @brief createDatabase()
 * Finds the SQL database file and loads it
 */
void createDatabase();

/**
 * @author Garrett Geesink
 * @brief checkConnection()
 * Checks the connection to the SQL database
 * @return bool
 */
bool checkConnection();

#endif // DATABASE_H
