#pragma once
#include "pch.h"
#include "Stock.hpp"
using namespace StockNameSpace;
class UserStock
{
public:
	UserStock();
	UserStock(Stock* stock, int amount);
	UserStock(Stock* stock, int amount,float profit);
	~UserStock();
	Stock* GetStock();
	void SetStock(Stock *stock);
	long GetAmount();
	void SetAmount(int amount);
	float GetProfit();
	void SetProfit(float profit);
private:
	Stock *Stock;
	int amount;
	float profit;
};

