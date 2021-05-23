#include "pch.h";
#include "Portfolio.hpp"


Portfolio::Portfolio(int lotCount)
{
	this->lotCount = lotCount;
	this->UserStocks = new UserStock[lotCount];
}

Portfolio::Portfolio(UserStock* userStocks, int lotCount)
{
	this->UserStocks = userStocks;
	this->lotCount = lotCount;
}

Portfolio::Portfolio()
{
	this->lotCount = 0;
	this->UserStocks = new UserStock();
}
Portfolio::~Portfolio()
{

}

void Portfolio::SetLotCount(int lotCount)
{
	this->lotCount = lotCount;
}

int Portfolio::GetLotCount()
{
	return this->lotCount;
}

UserStock* Portfolio::GetUserStocks()
{
	return this->UserStocks;
}

void Portfolio::SetUserStocks(UserStock* userStocks)
{
	this->UserStocks = userStocks;
}

UserStock* Portfolio::GetUserStock(string symbol)
{
	UserStock* returnStock = new UserStock();
	for (int i = 0; i < this->lotCount; i++)
	{
		string _symbol = this->UserStocks[i].GetStock()->GetSymbol();
		if (_symbol == symbol)
		{
			returnStock = &this->UserStocks[i];
		}
	}
	return returnStock;
}

void Portfolio::SetUserStock(Stock stock)
{
	for (int i = 0; i < this->lotCount; i++)
	{
		if (this->UserStocks[i].GetStock()->GetID() == stock.GetID())
		{
			if (this->UserStocks[i].GetAmount() == 0)
			{
				delete(&this->UserStocks[i]);
			}
			else
			{
				this->UserStocks[i].SetStock(&stock);
			}
		}
	}
}

void Portfolio::PrintPortfolio()
{
	cout << "********* PORTFOYUM ***********" << endl;
	for (int i = 0; i < this->lotCount; i++)
	{
		cout << UserStocks[i].GetStock()->GetSymbol() << " - " << UserStocks[i].GetStock()->GetName() << endl;
		cout << "ADET: " << UserStocks[i].GetAmount() << endl;
		cout << "KAR: " << UserStocks[i].GetProfit() << endl;
	}
}