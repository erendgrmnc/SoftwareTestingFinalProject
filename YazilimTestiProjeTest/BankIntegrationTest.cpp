#include "pch.h"
#include "BankIntegrationTest.h"

void BankIntegrationTest::SetUpTestCase()
{
	bank = new Bank();
}

void BankIntegrationTest::TearDownTestCase()
{
	bank = NULL;
}

BankIntegrationTest::BankIntegrationTest()
{
	i = new ifstream("hisseler.json");
	j = new json();
	i[0] >> j[0];
}

BankIntegrationTest::~BankIntegrationTest()
{
	delete i, j, bank;
}

TEST_F(BankIntegrationTest, IsGetStocksFromFileAdressTrue)
{
	int testStocksSize = j[0]["Hisseler"].size();
	Stock* stocks = new Stock[testStocksSize];

	for (int i = 0; i < testStocksSize; i++)
	{
		stocks[i].SetStock(j[0]["Hisseler"][0]["_id"], j[0]["Hisseler"][0]["Sembol"], j[0]["Hisseler"][0]["Ad"], j[0]["Hisseler"][0]["Fiyat"]);
	}
	bank = new Bank(stocks, testStocksSize);

	ASSERT_TRUE(stocks == bank->GetStocks());
}

TEST_F(BankIntegrationTest, IsGetStockWithSymbolFromFileValueTrue)
{
	int testStocksSize = j[0]["Hisseler"].size();
	Stock* stocks = new Stock[testStocksSize];

	for (int i = 0; i < testStocksSize; i++)
	{
		stocks[i].SetStock(j[0]["Hisseler"][0]["_id"], j[0]["Hisseler"][0]["Sembol"], j[0]["Hisseler"][0]["Ad"], j[0]["Hisseler"][0]["Fiyat"]);
	}
	bank = new Bank(stocks, testStocksSize);

	string firstStockSymbol = stocks[0].GetSymbol();
	ASSERT_TRUE(stocks[0].GetSymbol() == bank->GetStock(firstStockSymbol)->GetSymbol());
}

TEST_F(BankIntegrationTest, IsGetStockCountFromFileTrue)
{
	int testStocksSize = j[0]["Hisseler"].size();
	Stock* stocks = new Stock[testStocksSize];

	for (int i = 0; i < testStocksSize; i++)
	{
		stocks[i].SetStock(j[0]["Hisseler"][0]["_id"], j[0]["Hisseler"][0]["Sembol"], j[0]["Hisseler"][0]["Ad"], j[0]["Hisseler"][0]["Fiyat"]);
	}
	bank = new Bank(stocks, testStocksSize);

	ASSERT_EQ(testStocksSize, bank->GetStockCount());
}

TEST_F(BankIntegrationTest, IsSetStockFromFileFunctional)
{


	Stock* testStocks = nullptr;
	bank = new Bank(testStocks, 0);

	int testStocksSize = j[0]["Hisseler"].size();
	Stock* stocks = new Stock[testStocksSize];

	for (int i = 0; i < testStocksSize; i++)
	{
		stocks[i].SetStock(j[0]["Hisseler"][0]["_id"], j[0]["Hisseler"][0]["Sembol"], j[0]["Hisseler"][0]["Ad"], j[0]["Hisseler"][0]["Fiyat"]);
	}

	bank->SetStockCount(testStocksSize);
	bank->SetStocks(stocks);
	ASSERT_TRUE(stocks == bank->GetStocks());
}

TEST_F(BankIntegrationTest, IsSetStockSizeFromFileFunctional)
{

	Stock* testStocks = nullptr;
	bank = new Bank(testStocks, 0);

	int testStocksSize = j[0]["Hisseler"].size();
	Stock* stocks = new Stock[testStocksSize];

	for (int i = 0; i < testStocksSize; i++)
	{
		stocks[i].SetStock(j[0]["Hisseler"][0]["_id"], j[0]["Hisseler"][0]["Sembol"], j[0]["Hisseler"][0]["Ad"], j[0]["Hisseler"][0]["Fiyat"]);
	}

	bank->SetStockCount(testStocksSize);
	bank->SetStocks(stocks);
	ASSERT_TRUE(testStocksSize == bank->GetStockCount());
}

