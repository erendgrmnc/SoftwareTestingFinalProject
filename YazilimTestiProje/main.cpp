#include <iostream>
#include <fstream>
#include <locale.h>
#include "json.hpp"
#include "FileOperations.hpp"
#include "Bank.hpp"
#include "User.hpp"
#include "StockOperations.hpp"
using json = nlohmann::json;
using namespace std;

int main() {
	setlocale(LC_ALL, "tr_TR.UTF-8");
	
	FileOperations* fo = new FileOperations("Hisseler.json");
	Bank* bank = new Bank(fo->ReturnCount());
	fo->SetStocks(bank->GetStocks(), bank->GetStockCount());
	
	fo->OpenJSON("Portfoy.json");
	User* user = new User(1000.00,fo->ReturnCount());
	fo->SetUserStocks(user->GetPortfolio()->GetUserStocks(), user->GetPortfolio()->GetLotCount());

	fo->OpenJSON("Emirler.json");
	user->SetOrderCount(fo->ReturnCount());
	fo->SetOrders(user->GetOrders(), user->GetOrderCount());

	StockOperations* so = new StockOperations(bank);
	user->GetPortfolio()->PrintPortfolio();
	so->ExecuteOrder(user);
	user->GetPortfolio()->PrintPortfolio();


	return 0;
}