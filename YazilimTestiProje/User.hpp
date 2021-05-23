#pragma once
#include <string>
#include "Portfolio.hpp"
#include "Order.hpp"
using namespace std;
class User
{
public:
	User();
	User(float currency,int lotCount);
	User(Portfolio* portfolio,float currency);
	User(string userID,string name,Portfolio* portfolio,float currency);
	User(string userID,string name,Portfolio* portfolio,float currency ,Order* orders, int orderCount);
	~User();
	string GetName();
	void SetName(string name);
	string GetUserID();
	void SetUserID(string userID);
	float GetCurrency();
	void SetCurrency(float currency);
	Portfolio *GetPortfolio();
	void SetPortfolio(Portfolio* portfolio);
	Order* GetOrders();
	void SetOrders(Order* orders);
	int GetOrderCount();
	void SetOrderCount(int orderCount);

private:
	string name;
	string userID;
	float currency;
	Portfolio* portfolio;
	Order* orders;
	int orderCount;
};