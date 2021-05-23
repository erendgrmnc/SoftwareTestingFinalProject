#include "pch.h";
#include "Stock.hpp"

using namespace StockNameSpace;
Stock::Stock()
{
	this->ID = "";
	this->Name = "";
	this->Price = 0;
	this->Symbol = "";
}
Stock::~Stock()
{

}
Stock::Stock(string ID, string Symbol, string Name, float Price)
{
	this->ID = ID;
	this->Symbol = Symbol;
	this->Name = Name;
	this->Price = Price;
}
StockNameSpace::Stock::Stock(string ID, string Symbol, float Price)
{
	this->ID = ID;
	this->Symbol = Symbol;
	this->Name = "";
	this->Price = Price;
}
string Stock::GetID()
{
	return this->ID;

}
void Stock::SetID(string ID)
{
	this->ID = ID;
}

string Stock::GetName()
{
	return this->Name;
}

void Stock::SetName(string Name)
{
	this->Name = Name;
}
string Stock::GetSymbol()
{
	return this->Symbol;
}

void Stock::SetSymbol(string Symbol)
{
	this->Symbol = Symbol;
}

float Stock::GetPrice() 
{
	return this->Price;
}

void Stock::SetPrice(float Price)
{
	this->Price = Price;
}

void Stock::SetStock(string ID, string Symbol, string Name, float Price)
{
	this->ID = ID;
	this->Name = Name;
	this->Symbol = Symbol;
	this->Price = Price;
}

void Stock::PrintStock()
{
	cout << this->ID << " - " << this->Symbol << " - " << this->Name << " - " << this->Price << endl;
}