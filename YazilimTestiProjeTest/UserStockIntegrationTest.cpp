#include "pch.h"
#include "UserStockIntegrationTest.h"

void UserStockIntegrationTest::SetUpTestCase()
{
	userStock = new UserStock();
}

void UserStockIntegrationTest::TearDownTestCase()
{
	userStock = NULL;
}

UserStockIntegrationTest::UserStockIntegrationTest()
{
	i = new ifstream("portfoy.json");
	j = new json();
	i[0] >> j[0];
}

UserStockIntegrationTest::~UserStockIntegrationTest()
{
	delete i, j, userStock;
}


TEST_F(UserStockIntegrationTest, IsUserStockGetStockFromFileAdressTrue)
{

	Stock* stock = new Stock(j[0]["Portfoy"][0]["_id"], j[0]["Portfoy"][0]["Sembol"], j[0]["Portfoy"][0]["Maliyet"]);

	userStock = new UserStock(stock, j[0]["Portfoy"][0]["Adet"]);

	ASSERT_EQ(stock, userStock->GetStock());
}

TEST_F(UserStockIntegrationTest, IsUserStockGetAmountFromFileAdressTrue)
{
	int testAmount = (int)j[0]["Portfoy"][0]["Adet"];

	Stock* stock = new Stock(j[0]["Portfoy"][0]["_id"], j[0]["Portfoy"][0]["Sembol"], j[0]["Portfoy"][0]["Maliyet"]);

	userStock = new UserStock(stock, j[0]["Portfoy"][0]["Adet"]);

	ASSERT_EQ(testAmount, (int)userStock->GetAmount());
}

TEST_F(UserStockIntegrationTest, IsUserStockSetStockFromFileFunctional)
{
	Stock* stock = new Stock(j[0]["Portfoy"][0]["_id"], j[0]["Portfoy"][0]["Sembol"], j[0]["Portfoy"][0]["Maliyet"]);

	userStock = new UserStock(nullptr, j[0]["Portfoy"][0]["Adet"]);

	userStock->SetStock(stock);

	ASSERT_EQ(stock, userStock->GetStock());
}

TEST_F(UserStockIntegrationTest, IsUserStockSetAmountFromFileFunctional)
{
	int testAmount = j[0]["Portfoy"][0]["Adet"];

	Stock* stock = new Stock(j[0]["Portfoy"][0]["_id"], j[0]["Portfoy"][0]["Sembol"], j[0]["Portfoy"][0]["Maliyet"]);

	userStock = new UserStock(stock, 0);

	userStock->SetAmount(testAmount);

	ASSERT_EQ(testAmount,(int) userStock->GetAmount());
}