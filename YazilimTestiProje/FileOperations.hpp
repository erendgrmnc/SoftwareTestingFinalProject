#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "Stock.hpp"
#include "UserStock.hpp"
#include "Order.hpp"
using namespace std;
using json = nlohmann::json;

class FileOperations
{
public:
	FileOperations(string fileName);
	FileOperations();
	~FileOperations();
	void PrintJSON();
	void SetStocks(Stock *stocks,int stockSize);
	void SetUserStocks(UserStock *stocks,int stockSize);
	int ReturnCount();
	void OpenJSON(string fileName);
	string GetFileName();
	string SeperateFileName(string fileName);
	void SetOrders(Order* orders, int orderLength);

private:
	json *j;
	ifstream *i;
	string fileName;

};
