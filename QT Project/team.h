#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <vector>
#include <map>
#include "souvenir.h"
#include "matrixgraph.h"
#include "HashMap.h"
//#include "map.h"

/**
 *@author Aaron Geesink
 *@brief Team class
 * This is the Team class used to instantiate, store, and perform calculations on teams
 *@date December 2019
 */
class Team
{
public:
	/**
	 * @brief Team()
	 * Default Constructor
	 */
	Team();

	/**
	 * @author Aaron Geesink
	 * @brief getTeamName()
	 * This method returns a QString containing the name of the Team
	 * @return QString
	 */
	QString getTeamName();

	/**
	 * @author Aaron Geesink
	 * @brief getLocation()
	 * This method returns a QString containing the location of the Team
	 * @return QString
	 */
	QString getLocation();

	/**
	 * @author Aaron Geesink
	 * @brief getEdges()
	 * This method returns a vector of Edges containing the edges surrounding a team
	 * @return vector<Edge<QString>>
	 */
    std::vector<Edge<QString>> getEdges();

	/**
	 * @author Aaron Geesink
	 * @brief getSouvenirs()
	 * This method returns a map of souvenirs for a team
	 * @return map<int, Souvenir>&
	 */
	HashMap<int, Souvenir, 30, MyKeyHash> * getSouvenirs();

	/**
	 * @author Aaron Geesink
	 * @brief getKeys()
	 * This method returns a vector of keys for  a team's souvenir map
	 * @return vector<int>
	 */
	std::vector<int> getKeys();

	/**
	 * @author Aaron Geesink
	 * @brief getNumNonZeroSouvenirs()
	 * This method returns the number of souvenirs purchased for this team
	 * @return int
	 */
	int getNumNonZeroSouvenirs();

	/**
	 * @author Aaron Geesink
	 * @brief setTeamName(QString teamName)
	 * Sets the teamName of a Team object to QString teamName
	 * @param Qstring teamName
	 */
	void setTeamName(QString teamName);

	/**
	 * @author Aaron Geesink
	 * @brief setLocation(QString location)
	 * Sets the location of a Team object to QString location
	 * @param Qstring location
	 */
	void setLocation(QString location);

	/**
	 * @author Aaron Geesink
	 * @brief setEdges(std::vector<Edge<QString>> edges)
	 * Sets the edges surrounding a team to a vector of Edge objects
	 * @param std::vector<Edge<QString>> edges
	 */
    void setEdges(std::vector<Edge<QString>> edges);

	/**
	 * @author Aaron Geesink
     * @brief setSouvenirs(HashMap<int, Souvenir, MyKeyHash> souvenirs)
	 * Sets the souvenirs for a team to a map of Souvenir objects
     * @param HashMap<int, Souvenir, MyKeyHash> souvenirs
	 */
    void setSouvenirs(HashMap<int, Souvenir, 30, MyKeyHash> * souvenirs);

	/**
	 * @author Aaron Geesink
	 * @brief setKeys(std::vector<int> keys)
	 * Sets the keys for a team to a vector of keys
	 * @param std::vector<int> keys
	 */
	void setKeys(std::vector<int> keys);

	/**
	 * @author Aaron Geesink
	 * @brief addSouvenir(Souvenir souvenir)
	 * Adds a souvenir to a Team's souvenir map
	 * @param Souvenir souvenir
	 */
	void addSouvenir(Souvenir souvenir);

private:
	QString teamName;		/// The name of a Team
	QString location;		/// The location of a team
	std::vector<Edge<QString>> edges;	/// The edges surrounding a team
    HashMap<int, Souvenir, 30, MyKeyHash> *souvenirs;	/// The souvenirs for a team
	std::vector<int> keys;				/// Keys for a team's souvenir vector
};

#endif // TEAM_H
