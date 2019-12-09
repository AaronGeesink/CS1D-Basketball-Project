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

int Team::getNumNonZeroSouvenirs()
{
	int numNonZeroSouvenirs = 0;
	for (unsigned int i = 0; i < keys.size(); i++)
	{
		int key = keys[i];

		//qDebug() << key;
		//qDebug() << souvenirs.at(key).getQuantity();

		if (souvenirs.at(key).getQuantity() > 0)
		{
			//qDebug() << key;
			++numNonZeroSouvenirs;
		}
	}
	return numNonZeroSouvenirs;
}

std::vector<Souvenir>& Team::getNonZeroSouvenirs()
{
	std::vector<Souvenir> nonZeroSouvenirs;
	for (unsigned int i = 0; i < keys.size(); i++)
	{
		int key = keys[i];
		if (souvenirs[key].getQuantity() > 0)
		{
			nonZeroSouvenirs.push_back(souvenirs[key]);
		}
	}
	return nonZeroSouvenirs;
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
