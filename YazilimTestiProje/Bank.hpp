#pragma once
#include "Stock.hpp"
using namespace StockNameSpace;
class Bank
{
public:
	Bank();
	Bank(int stockCount);
	Bank(Stock* stocks, int stockCount);
	~Bank();
	Stock* GetStocks();
	void SetStocks(Stock *stocks);
	int GetStockCount();
	void SetStockCount(int stockCount);
	Stock* GetStock(string ID);
private:
	Stock* stocks;
	int stockCount;
};

