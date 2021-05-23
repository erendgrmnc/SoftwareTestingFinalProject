#include "pch.h";
#include "FileOperations.hpp"

FileOperations::FileOperations(string fileName) {
	this->i = new ifstream(fileName);
	this->fileName = SeperateFileName(fileName);
	this->j = new json();
	this->i[0] >> this->j[0];
}
FileOperations::FileOperations()
{
	this->j = new json();
	this->i = new ifstream();
}
FileOperations::~FileOperations() {

	delete i, j;
}

void FileOperations::PrintJSON() {
	for (int i = 0; i < this->j[0][fileName].size(); i++)
	{
		cout << j[0][fileName][i]["Sembol"] << " : " << j[0][fileName][i]["Fiyat"] << endl;
	}
}

int FileOperations::ReturnCount()
{
	return this->j[0][fileName].size();
}


void FileOperations::SetStocks(Stock* stocks,int stockSize) {
	
	for (int i = 0; i < stockSize; i++)
	{
		stocks[i].SetStock(j[0][fileName][i]["_id"], j[0][fileName][i]["Sembol"], j[0][fileName][i]["Ad"], j[0][fileName][i]["Fiyat"]);
		//cout << stocks[i].GetID() << " - " << stocks[i].GetSymbol() << " - " << stocks[i].GetName() << " - " << stocks[i].GetPrice() << endl;
	}
}
void FileOperations::OpenJSON(string fileName)
{
	this->i = new ifstream(fileName);
	this->fileName = SeperateFileName(fileName);
	this->j = new json();
	this->i[0] >> this->j[0];
	cout << "Boyut:" << j[0][fileName].size() << endl;
}

void FileOperations::SetUserStocks(UserStock* userStocks,int stockSize)
{
	for (int i = 0; i <stockSize; i++)
	{
		Stock* stock = new Stock();
		stock->SetStock(j[0][fileName][i]["_id"], j[0][fileName][i]["Sembol"], "", j[0][fileName][i]["Maliyet"]);
		userStocks[i].SetStock(stock);
		userStocks[i].SetAmount(j[0][fileName][i]["Adet"]);
	    //userStocks[i].GetStock()->PrintStock();
	}
}

string FileOperations::GetFileName()
{
	return this->fileName;
}

string FileOperations::SeperateFileName(string fileName)
{
	string a = "";
	string returnValue = "";
	for (int i = 0; i <fileName.size(); i++)
	{
		if (fileName[i] == '.')
		{
			break;
		}
		else
		{
			returnValue += fileName[i];
		}

	
	}

	cout << "Ayristirilan Dosya Ismi: " << returnValue << endl;

	return returnValue;

}

void FileOperations::SetOrders(Order* orders, int orderLength)
{
	for (int i = 0; i < orderLength; i++)
	{
		orders[i].SetOrder(j[0][fileName][i]["Islem"], j[0][fileName][i]["_id"], j[0][fileName][i]["Sembol"], j[0][fileName][i]["Adet"]);
		orders[i].PrintOrder();
	}
}

