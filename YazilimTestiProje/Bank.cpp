#include "pch.h";
#include "Bank.hpp"
Bank::Bank()
{
	this->stocks = new Stock();
	this->stockCount = 0;
}
Bank::~Bank()
{

}
Bank::Bank(int stockCount)
{
	this->stockCount = stockCount;
	this->stocks = new Stock[stockCount];

}
Bank::Bank(Stock* stocks, int stockCount)
{
	this->stocks = stocks;
	this->stockCount = stockCount;
}
void Bank::SetStocks(Stock *stocks)
{
	this->stocks = stocks;
}
Stock* Bank::GetStocks()
{
	return this->stocks;
}

void Bank::SetStockCount(int stockCount)
{
	this->stockCount = stockCount;
}

int Bank::GetStockCount()
{
	return this->stockCount;
}

Stock* Bank::GetStock(string symbol)
{
	Stock* returnStock = new Stock();
	for (int i = 0; i < this->stockCount; i++)
	{
		string _symbol = stocks[i].GetSymbol();
		if (_symbol == symbol)
		{
			returnStock = &stocks[i];
		}
	}
	return returnStock;
}