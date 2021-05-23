#include "pch.h"
#include "PortfolioTest.h"

void PortfolioTest::SetUpTestCase()
{
	portfolio = new Portfolio();
}

void PortfolioTest::SetUpTestCase(UserStock* userStock, int lotCount)
{
	portfolio = new Portfolio(userStock, lotCount);
}

void PortfolioTest::TearDownTestCase()
{
	portfolio = NULL;
}

PortfolioTest::PortfolioTest()
{
	portfolio = NULL;
}

PortfolioTest::~PortfolioTest()
{
	delete portfolio;
}

TEST_F(PortfolioTest, IsPortfolioUserStockTrue) {
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock,testAmount);
	SetUpTestCase(userStock,testAmount);
	
	ASSERT_EQ(userStock, portfolio->GetUserStocks());

	delete testStock, userStock;
}

TEST_F(PortfolioTest, IsPortfolioLotCountTrue) {
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock, testAmount);
	SetUpTestCase(userStock, testAmount);

	ASSERT_EQ(testAmount, portfolio->GetLotCount());
	delete testStock, userStock;
}

TEST_F(PortfolioTest, IsPortfolioUserStockTypeTrue) {
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock, testAmount);
	SetUpTestCase(userStock, testAmount);

	ASSERT_EQ(typeid(userStock), typeid(portfolio->GetUserStocks()));
	delete testStock, userStock;
}

TEST_F(PortfolioTest, IsPortfolioLotCountTypeTrue) {
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock, testAmount);
	SetUpTestCase(userStock, testAmount);

	ASSERT_EQ(typeid(testAmount), typeid(portfolio->GetLotCount()));
	delete testStock, userStock;
}

TEST_F(PortfolioTest, IsPortfolioSetLotCountFunctional) {
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock, testAmount);
	SetUpTestCase(userStock, testAmount);
	int newTestAmount = 200;
	portfolio->SetLotCount(newTestAmount);
	ASSERT_EQ(newTestAmount, portfolio->GetLotCount());
	delete testStock, userStock;
}

TEST_F(PortfolioTest, IsPortfolioSetUserStocksFunctional) {
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock, testAmount);
	SetUpTestCase(userStock, testAmount);
	Stock* testStock2 = new Stock("1234587", "AKBANK", "AKBNK", (float)13.0);
	int testAmount2 = 190;
	UserStock* userStock2 = new UserStock(testStock2, testAmount2);
	portfolio->SetUserStocks(userStock2);
	ASSERT_EQ(userStock2, portfolio->GetUserStocks());

	delete testStock, userStock,testStock2,userStock2;
}


