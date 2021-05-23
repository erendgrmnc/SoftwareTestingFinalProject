#include "pch.h";
#include "UserStock.hpp"
#include "Stock.hpp"

UserStock::UserStock()
{
	this->Stock = new StockNameSpace::Stock();
	this->amount = 0;
	this->profit = 0;
}
UserStock::UserStock(StockNameSpace::Stock* stock, int amount)
{
	this->Stock = stock;
	this->amount = amount;
	this->profit = 0;
}

UserStock::UserStock(StockNameSpace::Stock* stock, int amount, float profit)
{
	this->Stock = stock;
	this->amount = amount;
	this->profit = profit;
}

UserStock::~UserStock()
{

}

Stock* UserStock::GetStock()
{
	return this->Stock;
}

void UserStock::SetStock(StockNameSpace::Stock *stock)
{
	this->Stock = stock;
}

long UserStock::GetAmount()
{
	return this->amount;
}

void UserStock::SetAmount(int amount)
{
	this->amount = amount;
}

float UserStock::GetProfit()
{
	return this->profit;
}

void UserStock::SetProfit(float profit)
{
	this->profit = profit;
}