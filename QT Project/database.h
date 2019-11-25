#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QFile>
#include <QDir>
#include "team.h"

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

/**
 * @author Aaron Geesink
 * @brief queryTeams()
 * Queries the SQL database for the information of every team
 * @return std::vector<Team>
 */
std::vector<Team> queryTeams();

#endif // DATABASE_H
