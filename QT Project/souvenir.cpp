#include "souvenir.h"

Souvenir::Souvenir() : name {""}, price{0}, quantity{0}
{	}

Souvenir::Souvenir(QString name, double price, int id, int quantity)
	: name {name}, price{price}, id{id}, quantity{quantity}
{	}

Souvenir::~Souvenir()
{	}

void Souvenir::setQuantity(int quantity)
{
	this->quantity = quantity;
	//qDebug() << this->quantity;
}

double Souvenir::getPrice()
{
	return price;
}

double Souvenir::getPrice() const
{
	return price;
}

QString Souvenir::getName()
{
	return name;
}

const QString Souvenir::getName() const
{
	return name;
}

int Souvenir::getID()
{
	return id;
}

void Souvenir::setID(int id)
{
	this->id = id;
}

int Souvenir::getQuantity()
{
	return quantity;
}

double Souvenir::calculateTotal()
{
	return price * quantity;
}

Souvenir &Souvenir::operator=(Souvenir other)
{
	std::swap(name, other.name);
	std::swap(price, other.price);
	std::swap(quantity, other.quantity);
	return *this;
}

Souvenir &Souvenir::operator=(Souvenir &&other)
{
	name = std::move(other.name);
	price = std::move(other.price);
	quantity = std::move(other.quantity);
	return *this;
}

Souvenir::Souvenir(const Souvenir &other)
{
	name = other.name;
	price = other.price;
	quantity = other.quantity;
}

Souvenir::Souvenir(Souvenir &&other)
{
	name = other.name;
	price = other.price;
	quantity = other.quantity;

	other.name = nullptr;
	other.price = 0;
	other.quantity = 0;
}
