#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <vector>
#include <map>
#include "souvenir.h"
#include "matrixgraph.h"
//#include "map.h"

class Team
{
public:
	Team();

	//QString getConference();
	//QString getDivision();
	QString getTeamName();
	QString getLocation();
	//QString getArenaName();
	//int getArenaCap();
	//int getJoinYear();
	//QString getCoach();
    std::vector<Edge<QString>> getEdges();
	std::map<int, Souvenir> getSouvenirs();
	std::vector<int> getKeys();

	//void setConference(QString conference);
	//void setDivision(QString division);
	void setTeamName(QString teamName);
	void setLocation(QString location);
	//void setArenaName(QString arenaName);
	//void setArenaCap(int arenaCap);
	//void setJoinYear(int joinYear);
	//void setCoach(QString coach);
    void setEdges(std::vector<Edge<QString>> edges);
	void setSouvenirs(std::map<int, Souvenir> souvenirs);
	void setKeys(std::vector<int> keys);

	void addSouvenir(Souvenir souvenir);

private:
	//QString conference;
	//QString division;
	QString teamName;
	QString location;
	//QString arenaName;
	//int arenaCap;
	//int joinYear;
	//QString coach;
    std::vector<Edge<QString>> edges;
	std::map<int, Souvenir> souvenirs;
	std::vector<int> keys;
};

#endif // TEAM_H
