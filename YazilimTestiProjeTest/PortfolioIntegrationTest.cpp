#include "pch.h"
#include "PortfolioIntegrationTest.h"

void PortfolioIntegrationTest::SetUpTestCase()
{
	portfolio = new Portfolio();
}

void PortfolioIntegrationTest::TearDownTestCase()
{
	portfolio = NULL;
}

PortfolioIntegrationTest::PortfolioIntegrationTest()
{
	i = new ifstream("portfoy.json");
	j = new json();
	i[0] >> j[0];
}

PortfolioIntegrationTest::~PortfolioIntegrationTest()
{
	delete i, j, portfolio;
}

TEST_F(PortfolioIntegrationTest, IsGetUserStocksFromFileAdressTrue)
{
	int stockSize = j[0]["Portfoy"].size();

	UserStock* userStocks = new UserStock[stockSize];

	for (int i = 0; i < stockSize; i++)
	{
		Stock* stock = new Stock(j[0]["Portfoy"][i]["_id"], j[0]["Portfoy"][i]["Sembol"], j[0]["Portfoy"][i]["Maliyet"]);
		int testAmount = (int)j[0]["Portfoy"][0]["Adet"];
		userStocks[i].SetStock(stock);
		userStocks[i].SetAmount(testAmount);
	}
	portfolio = new Portfolio(userStocks,stockSize);

	ASSERT_TRUE(userStocks == portfolio->GetUserStocks());
}


TEST_F(PortfolioIntegrationTest, IsGetLotCountFromFileAdressTrue)
{
	int stockSize = j[0]["Portfoy"].size();

	UserStock* userStocks = new UserStock[stockSize];

	for (int i = 0; i < stockSize; i++)
	{
		Stock* stock = new Stock(j[0]["Portfoy"][i]["_id"], j[0]["Portfoy"][i]["Sembol"], j[0]["Portfoy"][i]["Maliyet"]);
		int testAmount = (int)j[0]["Portfoy"][0]["Adet"];
		userStocks[i].SetStock(stock);
		userStocks[i].SetAmount(testAmount);
	}
	portfolio = new Portfolio(userStocks, stockSize);
	ASSERT_TRUE(stockSize == portfolio->GetLotCount());
}

TEST_F(PortfolioIntegrationTest, IsSetLotCountFromFileFunctional)
{
	int stockSize = j[0]["Portfoy"].size();

	UserStock* userStocks = new UserStock[stockSize];

	for (int i = 0; i < stockSize; i++)
	{
		Stock* stock = new Stock(j[0]["Portfoy"][i]["_id"], j[0]["Portfoy"][i]["Sembol"], j[0]["Portfoy"][i]["Maliyet"]);
		int testAmount = (int)j[0]["Portfoy"][0]["Adet"];
		userStocks[i].SetStock(stock);
		userStocks[i].SetAmount(testAmount);
	}
	portfolio = new Portfolio(userStocks, 0);
	portfolio->SetLotCount(stockSize);
	ASSERT_TRUE(stockSize == portfolio->GetLotCount());
}

TEST_F(PortfolioIntegrationTest, IsSetUserStocksFromFileAdressTrue)
{
	portfolio = new Portfolio(nullptr, 0);

	int stockSize = j[0]["Portfoy"].size();

	UserStock* userStocks = new UserStock[stockSize];

	for (int i = 0; i < stockSize; i++)
	{
		Stock* stock = new Stock(j[0]["Portfoy"][i]["_id"], j[0]["Portfoy"][i]["Sembol"], j[0]["Portfoy"][i]["Maliyet"]);
		int testAmount = (int)j[0]["Portfoy"][0]["Adet"];
		userStocks[i].SetStock(stock);
		userStocks[i].SetAmount(testAmount);
	}

	portfolio->SetUserStocks(userStocks);
	
	ASSERT_TRUE(userStocks == portfolio->GetUserStocks());
}


TEST_F(PortfolioIntegrationTest, IsGetStockWithSymbolParamFromFileAdressTrue)
{
	string testID = j[0]["Portfoy"][0]["_id"];
	string testSymbol = j[0]["Portfoy"][0]["Sembol"];
	int stockSize = j[0]["Portfoy"].size();

	UserStock* userStocks = new UserStock[stockSize];

	for (int i = 0; i < stockSize; i++)
	{
		Stock* stock = new Stock(j[0]["Portfoy"][i]["_id"], j[0]["Portfoy"][i]["Sembol"], j[0]["Portfoy"][i]["Maliyet"]);
		int testAmount = (int)j[0]["Portfoy"][0]["Adet"];
		userStocks[i].SetStock(stock);
		userStocks[i].SetAmount(testAmount);
	}
	portfolio = new Portfolio(userStocks, stockSize);
	ASSERT_TRUE(testID == portfolio->GetUserStock(testSymbol)->GetStock()->GetID());
}