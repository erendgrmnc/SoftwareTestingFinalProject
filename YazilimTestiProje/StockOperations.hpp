#pragma once
#include "User.hpp"
#include "Bank.hpp"
class StockOperations
{
public:
	StockOperations(Bank* bank);
	StockOperations();
	~StockOperations();
	void ExecuteOrder(User* user);
	Bank* GetBank();
	void SetBank(Bank* bank);
	float CalculateProfit(float buyPrice,int buyAmount,float sellPrice,int sellAmount);
private:
	Bank* bank;

};