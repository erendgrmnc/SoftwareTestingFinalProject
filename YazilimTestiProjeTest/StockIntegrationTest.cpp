#include "pch.h"
#include "StockIntegrationTest.h"

void StockIntegrationTest::SetUpTestCase()
{
	stock = new Stock();
}

void StockIntegrationTest::TearDownTestCase()
{
	stock = NULL;
}

StockIntegrationTest::StockIntegrationTest()
{
	i = new ifstream("hisseler.json");
	j = new json();
	i[0] >> j[0];
}

StockIntegrationTest::~StockIntegrationTest()
{
	delete j,i,stock;
}

TEST_F(StockIntegrationTest,IsFirstStockIDFromFileTrue)
{
	string testID = j[0]["Hisseler"][0]["_id"];
	
	stock = new Stock(j[0]["Hisseler"][0]["_id"], j[0]["Hisseler"][0]["Sembol"], j[0]["Hisseler"][0]["Ad"], j[0]["Hisseler"][0]["Fiyat"]);

	ASSERT_TRUE(testID == stock[0].GetID());
}

TEST_F(StockIntegrationTest, IsFirsStockNameFromFileTrue)
{
	string name = j[0]["Hisseler"][0]["Ad"];

	stock = new Stock(j[0]["Hisseler"][0]["_id"], j[0]["Hisseler"][0]["Sembol"], j[0]["Hisseler"][0]["Ad"], j[0]["Hisseler"][0]["Fiyat"]);

	ASSERT_TRUE(name == stock[0].GetName());
}

TEST_F(StockIntegrationTest, IsFirstStockSymbolFromFileTrue)
{
	string name = j[0]["Hisseler"][0]["Sembol"];

	stock = new Stock(j[0]["Hisseler"][0]["_id"], j[0]["Hisseler"][0]["Sembol"], j[0]["Hisseler"][0]["Ad"], j[0]["Hisseler"][0]["Fiyat"]);

	ASSERT_TRUE(name == stock[0].GetSymbol());
}

TEST_F(StockIntegrationTest, IsFirstPriceSymbolFromFileTrue)
{
	float price = j[0]["Hisseler"][0]["Fiyat"];

	stock = new Stock(j[0]["Hisseler"][0]["_id"], j[0]["Hisseler"][0]["Sembol"], j[0]["Hisseler"][0]["Ad"], j[0]["Hisseler"][0]["Fiyat"]);

	ASSERT_TRUE(price == stock[0].GetPrice());
}

TEST_F(StockIntegrationTest, IsSetStockFromFileTrue)
{
	stock = new Stock();
	stock->SetStock(j[0]["Hisseler"][0]["_id"], j[0]["Hisseler"][0]["Sembol"], j[0]["Hisseler"][0]["Ad"], j[0]["Hisseler"][0]["Fiyat"]);

	ASSERT_EQ(j[0]["Hisseler"][0]["_id"], stock->GetID());
	ASSERT_EQ(j[0]["Hisseler"][0]["Sembol"], stock->GetSymbol());
	ASSERT_EQ(j[0]["Hisseler"][0]["Ad"], stock->GetName());
	ASSERT_EQ((float)j[0]["Hisseler"][0]["Fiyat"], stock->GetPrice());
}

TEST_F(StockIntegrationTest, IsSetIDFromFileFunctional)
{
	string testID = j[0]["Hisseler"][0]["_id"];

	stock = new Stock("", j[0]["Hisseler"][0]["Sembol"], j[0]["Hisseler"][0]["Ad"], j[0]["Hisseler"][0]["Fiyat"]);

	stock->SetID(testID);

	ASSERT_TRUE(testID == stock[0].GetID());
}

TEST_F(StockIntegrationTest, IsSetNameFromFileFunctional)
{
	string testName = j[0]["Hisseler"][0]["Ad"];

	stock = new Stock(j[0]["Hisseler"][0]["_id"], j[0]["Hisseler"][0]["Sembol"], "", j[0]["Hisseler"][0]["Fiyat"]);

	stock->SetName(testName);

	ASSERT_TRUE(testName == stock[0].GetName());
}

TEST_F(StockIntegrationTest, IsSetSymbolFromFileFunctional)
{
	string testSymbol = j[0]["Hisseler"][0]["Sembol"];

	stock = new Stock(j[0]["Hisseler"][0]["_id"], "", j[0]["Hisseler"][0]["Ad"], j[0]["Hisseler"][0]["Fiyat"]);

	stock->SetSymbol(testSymbol);

	ASSERT_TRUE(testSymbol == stock[0].GetSymbol());
}

TEST_F(StockIntegrationTest, IsSetPriceFromFileFunctional)
{
	float testPrice = (float)j[0]["Hisseler"][0]["Fiyat"];

	stock = new Stock(j[0]["Hisseler"][0]["_id"], j[0]["Hisseler"][0]["Sembol"], j[0]["Hisseler"][0]["Ad"],(float)0.0);

	stock->SetPrice((float)testPrice);

	ASSERT_TRUE((float)testPrice == stock[0].GetPrice());
}