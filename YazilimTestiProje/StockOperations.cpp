#include "pch.h";
#include "StockOperations.hpp"


StockOperations::StockOperations(Bank* bank)
{
	this->bank = bank;
}

StockOperations::StockOperations()
{
	this->bank = new Bank();
}

StockOperations::~StockOperations()
{
	delete bank;
}

void StockOperations::ExecuteOrder(User* user)
{
	Portfolio* portfolio = user->GetPortfolio();
	Order* orders = user->GetOrders();

	for (int i = 0; i < user->GetOrderCount(); i++)
	{
		if (orders[i].GetOrderType() == "SATIS")
		{
			Stock* stock = bank->GetStock(orders[i].GetSymbol());
			UserStock* userStock = portfolio->GetUserStock(orders[i].GetSymbol());

			if (&userStock != NULL)
			{
				cout << "---------- SATIS ISLEMI BASLADI ----------" << endl;
				cout << "HISSE: " << userStock->GetStock()->GetSymbol() << endl;
				cout << "ALIS FIYATI: " << userStock->GetStock()->GetPrice() << endl;
				cout << "SATIS FIYATI: " << stock->GetPrice() << endl;
				cout << "SATIS ADEDI: " << orders[i].GetAmount() << endl;
				cout << "KAR: " << (orders[i].GetAmount() * stock->GetPrice()) - (userStock->GetStock()->GetPrice() * userStock->GetAmount()) << endl;

				userStock->SetProfit(CalculateProfit(userStock->GetStock()->GetPrice(),userStock->GetAmount(),stock->GetPrice(),orders[i].GetAmount()));

				userStock->SetAmount(userStock->GetAmount() - orders[i].GetAmount());
				cout <<userStock->GetStock()->GetSymbol() << ": " << userStock->GetAmount() << endl;
				user->GetPortfolio()->PrintPortfolio();
			}
		}
		else if (orders[i].GetOrderType() == "ALIS")
		{
			cout << "---------- ALIS ISLEMI BASLADI ----------" << endl;
			Stock* stock = bank->GetStock(orders[i].GetID());
			UserStock* userStock = portfolio->GetUserStock(orders[i].GetSymbol());
		
			if (userStock == NULL)
			{
				int newSize = user->GetPortfolio()->GetLotCount() + 1;
				UserStock* newUserStocks = new UserStock[newSize];
				UserStock* oldUserStocks = user->GetPortfolio()->GetUserStocks();

				cout << "HISSE: " << stock->GetSymbol() << endl;
				cout << "ALIS FIYATI: " << stock->GetPrice() << endl;
				cout << "ALIS ADEDI: " << orders[i].GetAmount() << endl;


				for (int i = 0; i < user->GetPortfolio()->GetLotCount(); i++)
				{
					newUserStocks[i] = oldUserStocks[i];
				}
				newUserStocks[newSize].SetAmount(orders[i].GetAmount());
				newUserStocks[newSize].SetStock(stock);

				user->GetPortfolio()->SetLotCount(newSize);
				user->GetPortfolio()->SetUserStocks(newUserStocks);
			}
			else 
			{
				userStock->SetAmount(userStock->GetAmount() + orders[i].GetAmount());
			}

			

		}
	}
}

Bank* StockOperations::GetBank()
{
	return this->bank;
}

void StockOperations::SetBank(Bank* bank)
{
	this->bank = bank;
}

float StockOperations::CalculateProfit(float buyPrice,int buyAmount ,float sellPrice,int sellAmount)
{
	float buy = buyPrice * buyAmount;
	float sell = sellPrice * sellAmount;

	return sell - buy;
}