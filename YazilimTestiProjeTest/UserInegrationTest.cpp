#include "pch.h"
#include "UserInegrationTest.h"

void UserIntegrationTest::SetUpTestCase()
{
	user = new User();
}

void UserIntegrationTest::TearDownTestCase()
{
	user = NULL;
}

UserIntegrationTest::UserIntegrationTest()
{
	i = new ifstream("portfoy.json");
	j = new json();
	i[0] >> j[0];
}

UserIntegrationTest::~UserIntegrationTest()
{
	delete i, j, user;
}

TEST_F(UserIntegrationTest, IsPortfolioFromFileAdressTrue)
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
	Portfolio* portfolio = new Portfolio(userStocks, stockSize);

	user = new User(portfolio, stockSize);

	ASSERT_EQ(portfolio, user->GetPortfolio());
}

TEST_F(UserIntegrationTest, IsUserOrdersFromFileAdressTrue)
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
	Portfolio* portfolio = new Portfolio(userStocks, stockSize);

	i = new ifstream("emirler.json");
	j = new json();
	i[0] >> j[0];

	int orderCount = j[0]["Emirler"].size();

	Order* userOrders = new Order[orderCount];
	for (int i = 0; i < orderCount; i++)
	{

		userOrders[i].SetOrder(j[0]["Emirler"][0]["Islem"], j[0]["Emirler"][0]["_id"], j[0]["Emirler"][0]["Sembol"], j[0]["Emirler"][0]["Adet"]);
	}

	user = new User("13245","ErenDegirmenci",portfolio, stockSize, userOrders,orderCount);
	ASSERT_TRUE(userOrders,user->GetOrders());
}

TEST_F(UserIntegrationTest, IsOrderCountFromFileTrue)
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
	Portfolio* portfolio = new Portfolio(userStocks, stockSize);

	i = new ifstream("emirler.json");
	j = new json();
	i[0] >> j[0];

	int orderCount = j[0]["Emirler"].size();

	Order* userOrders = new Order[orderCount];
	for (int i = 0; i < orderCount; i++)
	{

		userOrders[i].SetOrder(j[0]["Emirler"][0]["Islem"], j[0]["Emirler"][0]["_id"], j[0]["Emirler"][0]["Sembol"], j[0]["Emirler"][0]["Adet"]);
	}

	user = new User("13245", "ErenDegirmenci", portfolio, stockSize, userOrders, orderCount);
	ASSERT_TRUE(orderCount, user->GetOrderCount());
}

TEST_F(UserIntegrationTest, IsSetOrderFromFileFunctional)
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
	Portfolio* portfolio = new Portfolio(userStocks, stockSize);

	i = new ifstream("emirler.json");
	j = new json();
	i[0] >> j[0];

	int orderCount = j[0]["Emirler"].size();
	Order* testOrders = nullptr;
	user = new User("13245", "ErenDegirmenci", portfolio, stockSize, testOrders, orderCount);
	

	Order* userOrders = new Order[orderCount];
	for (int i = 0; i < orderCount; i++)
	{

		userOrders[i].SetOrder(j[0]["Emirler"][0]["Islem"], j[0]["Emirler"][0]["_id"], j[0]["Emirler"][0]["Sembol"], j[0]["Emirler"][0]["Adet"]);
	}
	user->SetOrders(userOrders);

	ASSERT_TRUE(userOrders, user->GetOrders());
}

TEST_F(UserIntegrationTest, IsSetOrderCountFromFileFunctional)
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
	Portfolio* portfolio = new Portfolio(userStocks, stockSize);

	i = new ifstream("emirler.json");
	j = new json();
	i[0] >> j[0];

	int orderCount = j[0]["Emirler"].size();
	


	Order* userOrders = new Order[orderCount];
	for (int i = 0; i < orderCount; i++)
	{

		userOrders[i].SetOrder(j[0]["Emirler"][0]["Islem"], j[0]["Emirler"][0]["_id"], j[0]["Emirler"][0]["Sembol"], j[0]["Emirler"][0]["Adet"]);
	}
	int testOrderCount = 0;

	user = new User("13245", "ErenDegirmenci", portfolio, stockSize, userOrders, testOrderCount);
	user->SetOrderCount(orderCount);

	ASSERT_TRUE(orderCount, user->GetOrderCount());
}