#pragma once
#include <string>
#include <iostream>
using namespace std;

class Order
{
public:
	Order();
	Order(string orderType,string ID,string symbol,int amount);
	~Order();
	string GetOrderType();
	void SetOrderType(string orderType);
	string GetSymbol();
	void SetSymbol(string symbol);
	string GetID();
	void SetID(string ID);
	int GetAmount();
	void SetAmount(int amount);
	void SetOrder(string orderType, string ID, string symbol, int amount);
	void PrintOrder();

private:
	string orderType;
	string ID;
	string symbol;
	int amount;
};


