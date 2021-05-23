#pragma once
#include <string>
#include <iostream>
using namespace std;
namespace StockNameSpace {


	class Stock
	{
	public:
		Stock();
		Stock(string ID, string Symbol, string Name, float Price);
		Stock(string ID, string Symbol, float Price);
		~Stock();
		string GetID();
		void SetID(string ID);
		string GetSymbol();
		void SetSymbol(string Symbol);
		string GetName();
		void SetName(string Name);
		float GetPrice();
		void SetPrice(float Price);
		void SetStock(string ID, string Symbol, string Name, float Price);
		void PrintStock();


	private:
		string ID;
		string Symbol;
		string Name;
		float Price;
	};
}