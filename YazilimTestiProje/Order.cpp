#include "pch.h";
#include "Order.hpp"


Order::Order()
{
	this->orderType = "";
	this->amount = 0;
	this->ID = "";
	this->symbol = "";
}
Order::~Order() 
{

}
Order::Order(string orderType, string ID, string symbol, int amount)
{
	this->orderType = orderType;
	this->ID = ID;
	this->symbol = symbol;
	this->amount = amount;
}
string Order::GetOrderType()
{
	return this->orderType;
}
void Order::SetOrderType(string orderType)
{
	if (orderType == "SATIS" || orderType == "ALIS")
	{
		this->orderType = orderType;
	}
	else
	{
		this->orderType == "";
	}
}
string Order::GetSymbol()
{
	return this->symbol;
}
void Order::SetSymbol(string symbol)
{
	this->symbol = symbol;
}
string Order::GetID()
{
	return this->ID;
}
void Order::SetID(string ID)
{
	this->ID = ID;
}
int Order::GetAmount()
{
	return this->amount;
}
void Order::SetAmount(int amount)
{
	this->amount = amount;
}
void Order::SetOrder(string orderType, string ID, string symbol, int amount)
{
	this->orderType = orderType;
	this->ID = ID;
	this->symbol = symbol;
	this->amount = amount;
}

void Order::PrintOrder()
{
	cout << this->ID << " - " << this->symbol << " - " << this->orderType << " - " << this->amount << endl;
}