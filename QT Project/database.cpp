#include "database.h"
#include <QDebug>

void createDatabase()
{
	QSqlDatabase::addDatabase("QSQLITE");
	QSqlDatabase db;
	db = QSqlDatabase::database();
	// Load database from file
	const QString DB_PATH = QDir::currentPath() + "/resources/database.db";
    qDebug() << "PATH" << DB_PATH;
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

std::vector<Team> queryTeams()
{
	std::vector<Team> teams;
	Team team;
	std::vector<QString> teamNames = queryTeamNames();

// instantiate data for every team
	for (int i = 0; i < teamNames.size(); i++)
	{
		team.setTeamName(teamNames[i]);
		team.setEdges(queryEdges(teamNames[i]));
		team.setLocation(queryLocation(teamNames[i]));
/*
		qDebug() << "Name: " << team.getTeamName()
				 << "\nLocation: " << team.getLocation()
				 << "\nNum edges: " << team.getEdges().size()
                 << "\nEdge 1 start: " << team.getEdges()[0].start
                 << "\nEdge 1 end:" << team.getEdges()[0].end
                 << "\nEdge 1 distance:" << team.getEdges()[0].weight
				 << "\n";
                 */
	}

	return teams;
}

std::vector<QString> queryTeamNames()
{
	std::vector<QString> teamNames;
	QString active("1");

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());
	query.prepare("SELECT teamName FROM teams WHERE active='"+active+"'");

	if(!query.exec())
	{
		qDebug() << "Failed to query from SQL Database";
	}
	while(query.next())
	{
		teamNames.push_back(query.value(0).toString());
	}

	return teamNames;
}


Edge<QString> queryEdge(QString start, QString end)
{
	QSqlQuery query;
    double distance = 0;
    Edge<QString> edge;

	query.prepare("SELECT distance FROM distances WHERE startTeam = :startTeam and endTeam = :endTeam");
	query.bindValue(":startTeam", start);
	query.bindValue(":endTeam", end);
	if(!query.exec())
	{
		qDebug() << "Failed to query from SQL Database";
	}
	while(query.next())
	{
        distance = query.value(0).toDouble();
        edge.weight = distance;
        edge.end = end;
	}
	return edge;
}

std::vector<Edge<QString>> queryEdges(QString startTeam)
{
    std::vector<Edge<QString>> edges;
    Edge<QString> edge;
	std::vector<QString> endTeams;
    std::vector<double> distances;

	QSqlQuery query;

// Query the endTeams for the edges
	query.prepare("SELECT endTeam FROM distances WHERE startTeam = :startTeam");
	query.bindValue(":startTeam", startTeam);
	if(!query.exec())
	{
		qDebug() << "Failed to query from SQL Database";
	}
	while(query.next())
	{
		endTeams.push_back(query.value(0).toString());
	}

// Query the distances for the edges
	query.prepare("SELECT distance FROM distances WHERE startTeam = :startTeam");
	query.bindValue(":startTeam", startTeam);
	if(!query.exec())
	{
		qDebug() << "Failed to query from SQL Database";
	}
	while(query.next())
	{
        distances.push_back(query.value(0).toDouble());
	}

// construct the edges
	for (int i = 0; i < endTeams.size(); i++)
	{
        edge.start = startTeam;
        edge.end = endTeams[i];
        edge.weight = distances[i];
		edges.push_back(edge);
	}

	return edges;
}


std::vector<Souvenir> querySouvenirs(QString teamName)
{
	std::vector<Souvenir> souvenirs;
	std::vector<QString> souvenirNames;
	std::vector<float> souvenirPrices;

	QSqlQuery query;

// Query the souvenir names for the team
	query.prepare("SELECT item FROM souvenirs WHERE teamName = :teamName");
	query.bindValue(":teamName", teamName);
	if(!query.exec())
	{
		qDebug() << "Failed to query from SQL Database";
	}
	while(query.next())
	{
		souvenirNames.push_back(query.value(0).toString());
	}

// Query the souvenir prices for the team
	query.prepare("SELECT price FROM souvenirs WHERE teamName = :teamName");
	query.bindValue(":teamName", teamName);
	if(!query.exec())
	{
		qDebug() << "Failed to query from SQL Database";
	}
	while(query.next())
	{
		souvenirPrices.push_back(query.value(0).toDouble());
	}

// construct the souvenirs
	for (int i = 0; i < souvenirNames.size(); i++)
	{
		Souvenir souvenir(souvenirNames[i], souvenirPrices[i]);
		souvenirs.push_back(souvenir);
	}

	return souvenirs;
}

QString queryLocation(QString teamName)
{
	QSqlQuery query;
	QString location;

// Query the location for the team
	query.prepare("SELECT location FROM teams WHERE teamName = :teamName");
	query.bindValue(":teamName", teamName);
	if(!query.exec())
	{
		qDebug() << "Failed to query from SQL Database";
	}
	else
	{
		query.next();
		location = query.value(0).toString();
	}

	return location;
}
