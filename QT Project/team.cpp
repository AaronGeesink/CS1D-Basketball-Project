#include "team.h"

Team::Team() : teamName{""}, location{""}
{	}

QString Team::getTeamName()
{
	return teamName;
}

QString Team::getLocation()
{
	return location;
}

std::vector<Edge> Team::getEdges()
{
	return edges;
}

void Team::setTeamName(QString teamName)
{
	this->teamName = teamName;
}

void Team::setLocation(QString location)
{
	this->location = location;
}

void Team::setEdges(std::vector<Edge> edges)
{
	this->edges = edges;
}
