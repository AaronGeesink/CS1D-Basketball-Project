#ifndef SOUVENIR_H
#define SOUVENIR_H

#include <QString>
#include <QDebug>

/**
 *@author Aaron Geesink
 *@brief Souvenir class
 * This is the Souvenir class used to instantiate, store, and perform calculations on souvenirs
 *@date December 2019
 */
class Souvenir
{
public:
	/**
	 *@author Aaron Geesink
	 *@brief Souvenir()
	 * Default constructor
	 */
	Souvenir();

	/**
	 *@author Aaron Geesink
	 *@brief Souvenir(QString name, double price, int quantity = 0)
	 * Overloaded constructor
	 */
	Souvenir(QString name, double price, int id, int quantity = 0);

	/**
	 *@author Aaron Geesink
	 *@brief ~Souvenir()
	 * Destructor
	 */
	~Souvenir();

	/**
	 *@author Aaron Geesink
	 *@brief setQuantity(int quantity)
	 * Sets the quantity of Souvenir the user purchases
	 * @param int quantity
	 */
	void setQuantity(int quantity);

	/**
	 *@author Aaron Geesink
	 *@brief getPrice()
	 * Returns the price of a Souvenir item
	 * @return double
	 */
	double getPrice();

	/**
	 *@author Aaron Geesink
	 *@brief getPrice() const
	 * Returns the price of a Souvenir item
	 * @return const double
	 */
	 double getPrice() const;

	/**
	 *@author Aaron Geesink
	 *@brief getName()
	 * Returns the name of a Souvenir item
	 * @return Qstring
	 */
	QString getName();

	/**
	 *@author Aaron Geesink
	 *@brief getName() const
	 * Returns the name of a Souvenir item
	 * @return const Qstring
	 */
	const QString getName() const;

	int getID();

	void setID(int id);

	/**
	 *@author Aaron Geesink
	 *@brief calculateTotal()
	 * Returns the total price of all purchased Souvenir items
	 * @return double
	 */
	double calculateTotal();

	/**
	 *@author Aaron Geesink
	 *@brief getQuantity()
	 * Returns the quantity of Souvenir purchased of a given Souvenir item
	 * @return int
	 */
	int getQuantity();

	/**
	 *@author Aaron Geesink
	 *@brief operator=(Souvenir other)
	 * An copy assignment for Souvenir items
	 * @return Souvenir &
	 */
	Souvenir& operator=(Souvenir other);

	/**
	 *@author Aaron Geesink
	 *@brief operator=(Souvenir&& other)
	 * A move assignment for Souvenir items
	 * @return Souvenir&
	 */
	Souvenir& operator=(Souvenir&& other);

	/**
	 *@author Aaron Geesink
	 *@brief Souvenir(const Souvenir& other);
	 * A copy constructor for Souvenir items
	 */
	Souvenir(const Souvenir& other);

	/**
	 *@author Aaron Geesink
	 *@brief Souvenir(const Souvenir& other);
	 * A copy assignment for Souvenir items
	 */
	Souvenir(Souvenir&& other);

private:
	QString name;	/// The name of the Souvenir item
	double price;	/// The price of a Souvenir item
	int quantity;	/// The quantity of Souvenir purchased
	int id;			/// the database id of the souvenir
};

#endif // SOUVENIR_H
