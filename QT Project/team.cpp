#include "team.h"

Team::Team() : teamName{""}, location{""}, souvenirs{ }
{	}

QString Team::getTeamName()
{
	return teamName;
}

QString Team::getLocation()
{
	return location;
}

std::vector<Edge<QString>> Team::getEdges()
{
	return edges;
}

std::map<int, Souvenir>& Team::getSouvenirs()
{
	return souvenirs;
}

std::vector<int> Team::getKeys()
{
	return keys;
}

void Team::setTeamName(QString teamName)
{
	this->teamName = teamName;
}

void Team::setLocation(QString location)
{
	this->location = location;
}

void Team::setEdges(std::vector<Edge<QString>> edges)
{
	this->edges = edges;
}

void Team::setSouvenirs(std::map<int, Souvenir> souvenirs)
{
	this->souvenirs = souvenirs;
}

void Team::setKeys(std::vector<int> keys)
{
	this->keys = keys;
}

void Team::addSouvenir(Souvenir souvenir)
{
	souvenirs.insert({souvenir.getID(), souvenir});
}
