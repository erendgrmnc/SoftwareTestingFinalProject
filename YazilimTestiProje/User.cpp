#include "pch.h"
#include "User.hpp"
User::User()
{
	this->portfolio = new Portfolio();
	this->currency = 0;
	this->name = "";
	this->orderCount = 0;
	this->orders = new Order();
	this->userID = "";
}

User::User(float currency, int lotCount)
{
	this->portfolio = new Portfolio(lotCount);
	this->currency = currency;
	this->name = "";
	this->orderCount = 0;
	this->orders = new Order();
	this->userID = "";
}

User::User(Portfolio* portfolio, float currency)
{
	this->portfolio = portfolio;
	this->currency = currency;
	this->name = "";
	this->orderCount = 0;
	this->orders = new Order();
	this->userID = "";
}

User::User(string userID, string name, Portfolio* portfolio, float currency)
{
	this->userID = userID;
	this->name = name;
	this->portfolio = portfolio;
	this->currency;
}

User::User(string userID, string name, Portfolio* portfolio, float currency, Order* orders, int orderCount)
{
	this->userID = userID;
	this->name = name;
	this->portfolio = portfolio;
	this->currency = currency;
	this->orders = orders;
	this->orderCount = orderCount;
}

User::~User()
{

}

string User::GetUserID()
{
	return this->userID;
}

void User::SetUserID(string userID)
{
	this->userID = userID;
}

string User::GetName()
{
	return this->name;
}

void User::SetName(string name)
{
	this->name = name;
}

Portfolio* User::GetPortfolio()
{
	return this->portfolio;
}

void User::SetPortfolio(Portfolio* portfolio)
{
	this->portfolio = portfolio;
}

float User::GetCurrency()
{
	return this->currency;
}

void User::SetCurrency(float currency)
{
	this->currency = currency;
}

Order* User::GetOrders()
{
	return this->orders;
}
void User::SetOrders(Order* orders)
{
	this->orders = orders;
}

int User::GetOrderCount()
{
	return this->orderCount;
}

void User::SetOrderCount(int orderCount)
{
	this->orderCount = orderCount;
	this->orders = new Order[orderCount];
}