#include "pch.h"
#include "UserStockTest.h"

void UserStockTest::SetUpTestCase()
{
	userStock = new UserStock();
}

void UserStockTest::SetUpTestCase(Stock* stock, int amount)
{
	userStock = new UserStock(stock, amount);
}

void UserStockTest::SetUpTestCase(Stock* stock, int amount,float profit)
{
	userStock = new UserStock(stock, amount,profit);
}

void UserStockTest::TearDownTestCase()
{
	userStock = NULL;
}

UserStockTest::UserStockTest()
{
}

UserStockTest::~UserStockTest()
{
	delete userStock;
}

TEST_F(UserStockTest, IsStockTrue) {
	Stock* stock = new Stock("12345", "FROTO", "FORD OTOSAN", 17.00);
	SetUpTestCase(stock, 500);
	ASSERT_EQ(stock, userStock->GetStock());
	delete stock;
}

TEST_F(UserStockTest, IsStockAmountTrue) {
	Stock* stock = new Stock("12345", "FROTO", "FORD OTOSAN", 17.00);
	int amount = 500;
	SetUpTestCase(stock, amount);
	ASSERT_EQ(amount, userStock->GetAmount());
	delete stock;
}

TEST_F(UserStockTest, IsSetStockFunctional) {
	Stock* stock = new Stock("12345", "FROTO", "FORD OTOSAN", 17.00);
	int amount = 500;
	SetUpTestCase(stock, amount);
	Stock* newStock = new Stock("54321", "PAPIL", "PAPILON SAVUNMA", (float)17.6);
	userStock->SetStock(newStock);
	ASSERT_EQ(newStock, userStock->GetStock());
	
	delete stock;
	delete newStock;
}

TEST_F(UserStockTest, IsSetAmountFunctional) {
	Stock* stock = new Stock("12345", "FROTO", "FORD OTOSAN", 17.00);
	int amount = 500;
	SetUpTestCase(stock, amount);
	int newAmount = 100;
	userStock->SetAmount(newAmount);
	ASSERT_EQ(newAmount,userStock->GetAmount());

	delete stock;
}


TEST_F(UserStockTest, IsGetProfitFunctional) {
	Stock* stock = new Stock("12345", "FROTO", "FORD OTOSAN", 17.00);
	int amount = 500;
	float profit = 100.5;
	SetUpTestCase(stock, amount,profit);
	ASSERT_EQ(profit, userStock->GetProfit());

	delete stock;
}

TEST_F(UserStockTest, IsSetProfitFunctional) {
	Stock* stock = new Stock("12345", "FROTO", "FORD OTOSAN", 17.00);
	int amount = 500;
	SetUpTestCase(stock, amount);
	float profit = 100.5;
	userStock->SetProfit(profit);
	ASSERT_EQ(profit, userStock->GetProfit());

	delete stock;
}

TEST_F(UserStockTest, IsTrue) {
	Stock* stock = new Stock("12345", "FROTO", "FORD OTOSAN", 17.00);
	int amount = 500;
	float profit = 100.5;
	SetUpTestCase(stock, amount, profit);

	delete stock;
}