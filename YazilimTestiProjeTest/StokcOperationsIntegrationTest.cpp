#include "pch.h"
#include "StokcOperationsIntegrationTest.h"

void StockOperationIntegrationTest::SetUpTestCase()
{
}

void StockOperationIntegrationTest::TearDownTestCase()
{
}

StockOperationIntegrationTest::StockOperationIntegrationTest()
{
	
	fop = new FileOperations("Hisseler.json");
	bank = new Bank(fop->ReturnCount());
	fop->SetStocks(bank->GetStocks(), fop->ReturnCount());

	sop = new StockOperations(bank);
}

StockOperationIntegrationTest::~StockOperationIntegrationTest()
{
	delete fop, sop, bank;
}

TEST_F(StockOperationIntegrationTest, IsExecuteOrderFromFileFunctional)
{
	fop->OpenJSON("Portfoy.json");
	User* user = new User(1000.00, fop->ReturnCount());
	fop->SetUserStocks(user->GetPortfolio()->GetUserStocks(), user->GetPortfolio()->GetLotCount());

	fop->OpenJSON("Emirler.json");
	user->SetOrderCount(fop->ReturnCount());
	fop->SetOrders(user->GetOrders(), user->GetOrderCount());
	
	

	string symbol = user->GetOrders()[0].GetSymbol();

	string orderType = user->GetOrders()[0].GetOrderType();
	int testAmount = 0;
	if (orderType == "SATIS")
	{
		testAmount = user->GetPortfolio()->GetUserStock(symbol)->GetAmount() - user->GetOrders()[0].GetAmount();
	}
	else
	{
		testAmount = user->GetPortfolio()->GetUserStock(symbol)->GetAmount() + user->GetOrders()[0].GetAmount();
	}
	sop->ExecuteOrder(user);

	ASSERT_EQ(testAmount , user->GetPortfolio()->GetUserStock(symbol)[0].GetAmount());
	delete user;
}

TEST_F(StockOperationIntegrationTest, IsCalculateProfitFromFileFunctional)
{
	fop->OpenJSON("Portfoy.json");
	User* user = new User(1000.00, fop->ReturnCount());
	fop->SetUserStocks(user->GetPortfolio()->GetUserStocks(), user->GetPortfolio()->GetLotCount());

	fop->OpenJSON("Emirler.json");
	user->SetOrderCount(fop->ReturnCount());
	fop->SetOrders(user->GetOrders(), user->GetOrderCount());



	string symbol = user->GetOrders()[0].GetSymbol();

	string orderType = user->GetOrders()[0].GetOrderType();
	int testAmount = 0;
	if (orderType == "SATIS")
	{
		testAmount = user->GetPortfolio()->GetUserStock(symbol)->GetAmount() - user->GetOrders()[0].GetAmount();
	}
	else
	{
		testAmount = user->GetPortfolio()->GetUserStock(symbol)->GetAmount() + user->GetOrders()[0].GetAmount();
	}

	UserStock* userStock = user->GetPortfolio()->GetUserStock(symbol);

	Stock* stock = bank->GetStock(symbol);
	Order order;
	for (int i = 0; i < user->GetOrderCount(); i++)
	{
		if (user->GetOrders()[i].GetSymbol() == symbol)
		{
			order = user->GetOrders()[i];
			break;
		}
	}
	
	float testProfit = (stock->GetPrice() * order.GetAmount()) - (userStock->GetStock()->GetPrice()* userStock->GetAmount());

	
	ASSERT_EQ(testProfit, sop->CalculateProfit(userStock->GetStock()->GetPrice(), userStock->GetAmount(), stock->GetPrice(), order.GetAmount()));

	delete user;
}