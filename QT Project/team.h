#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <vector>
#include "souvenir.h"

/*
enum Conferences
{
	Eastern, Western
};

enum Divisions
{
	Atlantic, Central, Southeast, Northwest, Pacific, Southwest
};
*/

struct Edge
{
	QString start;
	QString end;
	int distance;
};

class Team
{
public:
	Team();

	QString getConference();
	QString getDivision();
	QString getTeamName();
	QString getLocation();
	QString getArenaName();
	int getArenaCap();
	int getJoinYear();
	QString getCoach();
	std::vector<Edge> getEdges();
	//Map<float, Souvenir> getSouvenirs();

	void setConference(QString conference);
	void setDivision(QString division);
	void setTeamName(QString teamName);
	void setLocation(QString location);
	void setArenaName(QString arenaName);
	void setArenaCap(int arenaCap);
	void setJoinYear(int joinYear);
	void setCoach(QString coach);
	void setEdges(std::vector<Edge>);
	//void setSouvenirs(Map<float, Souvenir>);
	//void addSouvenir(Souvenir souvenir);

private:
	QString conference;
	QString division;
	QString teamName;
	QString location;
	QString arenaName;
	int arenaCap;
	int joinYear;
	QString coach;
	std::vector<Edge> edges;
	//Map<float, Souvenir> souvenirs;

};

#endif // TEAM_H
