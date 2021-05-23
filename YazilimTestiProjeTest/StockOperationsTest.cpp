#include "pch.h"
#include "StockOperationsTest.h"

void StockOperationsTest::SetUpTestCase()
{
	Bank* bank = new Bank();
	sop = new StockOperations(bank);
}

void StockOperationsTest::SetUpTestCase(Bank* bank)
{
	sop = new StockOperations(bank);
}

void StockOperationsTest::TearDownTestCase()
{
	sop = NULL;
}

StockOperationsTest::StockOperationsTest()
{
}

StockOperationsTest::~StockOperationsTest()
{
	delete sop;
}

TEST_F(StockOperationsTest, IsBankAdressTrue)
{
	int stockCount = 2;
	Stock* stocks = new Stock[stockCount];
	stocks[0].SetStock("132456", "AKSA", "AKSA", (float)12.4);
	stocks[1].SetStock("132457", "AKBNK", "AKBANK", (float)9.3);
	Bank* bank = new Bank(stocks, stockCount);

	int lotCount = 2;
	Stock* firstStock = new Stock("132456", "AKSA", "AKSA", (float)15.0);
	Stock* secondStock = new Stock("132457", "AKBNK", "AKBANK", (float)6.3);

	UserStock* userStock = new UserStock[lotCount];
	userStock[0].SetStock(firstStock);
	userStock[0].SetAmount(100);

	userStock[1].SetStock(secondStock);
	userStock[1].SetAmount(150);


	Portfolio* portfolio = new Portfolio(userStock, lotCount);

	int orderCount = 2;
	Order* orders = new Order[orderCount];
	orders[0].SetOrder("SATIS", "12645", "AKSA", 100);
	orders[1].SetOrder("SATIS", "12645", "AKBNK", 150);


	User* user = new User(portfolio, 1000.0);
	user->SetOrders(orders);
	SetUpTestCase(bank);

	sop->ExecuteOrder(user);

	ASSERT_EQ(bank, sop->GetBank());

	delete firstStock,secondStock,portfolio,bank,userStock,stocks,orders,user;
}

TEST_F(StockOperationsTest, IsSetBankFunctional)
{
	int stockCount = 2;
	Stock* stocks = new Stock[stockCount];
	stocks[0].SetStock("132456", "AKSA", "AKSA", (float)12.4);
	stocks[1].SetStock("132457", "AKBNK", "AKBANK", (float)9.3);
	Bank* bank = new Bank(stocks, stockCount);

	int lotCount = 2;
	Stock* firstStock = new Stock("132456", "AKSA", "AKSA", (float)15.0);
	Stock* secondStock = new Stock("132457", "AKBNK", "AKBANK", (float)6.3);

	UserStock* userStock = new UserStock[lotCount];
	userStock[0].SetStock(firstStock);
	userStock[0].SetAmount(100);

	userStock[1].SetStock(secondStock);
	userStock[1].SetAmount(150);


	Portfolio* portfolio = new Portfolio(userStock, lotCount);

	int orderCount = 2;
	Order* orders = new Order[orderCount];
	orders[0].SetOrder("SATIS", "12645", "AKSA", 100);
	orders[1].SetOrder("SATIS", "12645", "AKBNK", 150);


	User* user = new User(portfolio, 1000.0);
	user->SetOrders(orders);
	SetUpTestCase(bank);
	
	int newStockCount = 3;
	Stock* newStocks = new Stock[newStockCount];
	newStocks[0].SetStock("314578", "ORGE", "ORGE Elektrik Taahhüt", (float)12.4);
	newStocks[1].SetStock("698563", "BTCIM", "Bati Cimento", (float)9.3);
	newStocks[2].SetStock("447852", "TTRAK", "Turk Traktor", (float)47.3);
	
	Bank* testBank = new Bank(newStocks, newStockCount);
	
	sop->SetBank(testBank);
	ASSERT_EQ(testBank, sop->GetBank());
	delete firstStock, secondStock, portfolio, bank, userStock, stocks, orders,user;
}

TEST_F(StockOperationsTest, IsOrderExecuteFunctional)
{
	int stockCount = 2;
	Stock* stocks = new Stock[stockCount];
	stocks[0].SetStock("132456", "AKSA", "AKSA", (float)12.4);
	stocks[1].SetStock("132457", "AKBNK", "AKBANK", (float)9.3);
	Bank* bank = new Bank(stocks, stockCount);

	int lotCount = 2;
	Stock* firstStock = new Stock("132456", "AKSA", "AKSA", (float)15.0);
	Stock* secondStock = new Stock("132457", "AKBNK", "AKBANK", (float)6.3);

	UserStock* userStock = new UserStock[lotCount];
	userStock[0].SetStock(firstStock);
	userStock[0].SetAmount(100);

	userStock[1].SetStock(secondStock);
	userStock[1].SetAmount(150);


	Portfolio* portfolio = new Portfolio(userStock, lotCount);

	int orderCount = 2;
	Order* orders = new Order[orderCount];
	orders[0].SetOrder("SATIS", "12645", "AKSA", 100);
	orders[1].SetOrder("SATIS", "12645", "AKBNK", 150);

	
	User* user = new User(portfolio, 1000.0);
	user->SetOrderCount(orderCount);
	user->SetOrders(orders);
	SetUpTestCase(bank);

	user->GetPortfolio()->PrintPortfolio();
	sop->ExecuteOrder(user);
	user->GetPortfolio()->PrintPortfolio();
	int result = user->GetPortfolio()->GetUserStocks()[0].GetAmount();

	ASSERT_EQ(result, 0);
	delete firstStock, secondStock, portfolio, bank, userStock, stocks, orders,user;

}


TEST_F(StockOperationsTest, IsCalculateProfitFunctional)
{
	int stockCount = 2;
	Stock* stocks = new Stock[stockCount];
	stocks[0].SetStock("132456", "AKSA", "AKSA", (float)12.4);
	stocks[1].SetStock("132457", "AKBNK", "AKBANK", (float)9.3);
	Bank* bank = new Bank(stocks, stockCount);

	int lotCount = 2;
	Stock* firstStock = new Stock("132456", "AKSA", "AKSA", (float)15.0);
	Stock* secondStock = new Stock("132457", "AKBNK", "AKBANK", (float)6.3);

	UserStock* userStock = new UserStock[lotCount];
	userStock[0].SetStock(firstStock);
	userStock[0].SetAmount(100);

	userStock[1].SetStock(secondStock);
	userStock[1].SetAmount(150);


	Portfolio* portfolio = new Portfolio(userStock, lotCount);

	int orderCount = 2;
	Order* orders = new Order[orderCount];
	orders[0].SetOrder("SATIS", "12645", "AKSA", 100);
	orders[1].SetOrder("SATIS", "12645", "AKBNK", 150);


	User* user = new User(portfolio, 1000.0);
	user->SetOrders(orders);
	SetUpTestCase(bank);

	

	float buyPrice = user->GetPortfolio()[0].GetUserStocks()[0].GetStock()[0].GetPrice();
	int buyAmount = user->GetPortfolio()[0].GetUserStocks()[0].GetAmount();

	float sellPrice = bank->GetStocks()[0].GetPrice();
	int sellAmount = user->GetOrders()[0].GetAmount();
	ASSERT_EQ(-260.0, sop->CalculateProfit(buyPrice, buyAmount, sellPrice, sellAmount));
	delete firstStock, secondStock, portfolio, bank, userStock, stocks, orders,user;


}
