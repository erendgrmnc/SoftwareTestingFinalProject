#pragma once
#include "UserStock.hpp"
#include "Bank.hpp"
using namespace std;

class Portfolio
{
public:
	Portfolio();
	Portfolio(int lotCount);
	Portfolio(UserStock* userStocks,int lotCount);
	~Portfolio();
	int GetLotCount();
	void SetLotCount(int lotCount);
	UserStock* GetUserStocks();
	void SetUserStocks(UserStock* userStocks);
	UserStock* GetUserStock(string ID);
	void SetUserStock(Stock stock);
	void PrintPortfolio();

private:
	UserStock* UserStocks;
	int lotCount;
};

