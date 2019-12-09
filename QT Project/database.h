#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QFile>
#include <QDir>
#include <QDebug>
#include "team.h"
//#include "map.h"

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

Team queryTeam(QString teamName);

/**
 * @author Aaron Geesink
 * @brief queryTeams()
 * Queries the SQL database for the trip information of every team
 * @return std::vector<Team>
 */
std::vector<Team> queryTeams();

/**
 * @author Aaron Geesink
 * @brief queryTeamNames()
 * Queries the SQL database for the names of all teams
 * @return std::vector<QString>
 */
std::vector<QString> queryTeamNames();

/**
 * @author Aaron Geesink
 * @brief queryEdge(QString start, QString end)
 * Queries the SQL database for the edge from start team to end team
 * @param QString start, QString end
 * @return Edge
 */
Edge<QString> queryEdge(QString start, QString end);

/**
 * @author Aaron Geesink
 * @brief queryEdges(QString teamName)
 * Queries the SQL database for the edges of a given team
 * @param QString teamName
 * @return Edge
 */
std::vector<Edge<QString>> queryEdges(QString startTeam);

/**
 * @author Aaron Geesink
 * @brief querySouvenirs(QString teamName)
 * Queries the SQL database for a team's souvenirs.
 * @param QString teamName
 * @return std::vector<Souvenir>
 */
std::map<int, Souvenir> querySouvenirs(QString teamName);

std::vector<int> queryKeys(QString teamName);

/**
 * @author Aaron Geesink
 * @brief queryLocation(QString teamName)
 * Queries the SQL database for the city a team is located in
 * @param QString teamName
 * @return QString
 */
QString queryLocation(QString teamName);

#endif // DATABASE_H
