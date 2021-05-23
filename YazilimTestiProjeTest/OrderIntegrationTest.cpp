#include "pch.h"
#include "OrderIntegrationTest.h"

void OrderIntegrationTest::SetUpTestCase()
{
	order = new Order();
}

void OrderIntegrationTest::TearDownTestCase()
{
	order = NULL;
}

OrderIntegrationTest::OrderIntegrationTest()
{
	i = new ifstream("emirler.json");
	j = new json();
	i[0] >> j[0];
}

OrderIntegrationTest::~OrderIntegrationTest()
{
	delete i, j, order;
}

TEST_F(OrderIntegrationTest,IsGetOrderTypeFromFileTrue)
{
	string orderType = j[0]["Emirler"][0]["Islem"];
	order = new Order(j[0]["Emirler"][0]["Islem"],j[0]["Emirler"][0]["_id"], j[0]["Emirler"][0]["Sembol"], j[0]["Emirler"][0]["Adet"]);

	ASSERT_EQ(orderType, order->GetOrderType());
}

TEST_F(OrderIntegrationTest, IsGetOrderIDFromFileTrue)
{
	string orderID = j[0]["Emirler"][0]["_id"];
	order = new Order(j[0]["Emirler"][0]["Islem"], j[0]["Emirler"][0]["_id"], j[0]["Emirler"][0]["Sembol"], j[0]["Emirler"][0]["Adet"]);

	ASSERT_EQ(orderID, order->GetID());
}

TEST_F(OrderIntegrationTest, IsGetOrderSymbolFromFileTrue)
{
	string orderSymbol = j[0]["Emirler"][0]["Sembol"];
	order = new Order(j[0]["Emirler"][0]["Islem"], j[0]["Emirler"][0]["_id"], j[0]["Emirler"][0]["Sembol"], j[0]["Emirler"][0]["Adet"]);

	ASSERT_EQ(orderSymbol, order->GetSymbol());
}

TEST_F(OrderIntegrationTest, IsGetOrderAmountFromFileTrue)
{
	int orderAmount = j[0]["Emirler"][0]["Adet"];
	order = new Order(j[0]["Emirler"][0]["Islem"], j[0]["Emirler"][0]["_id"], j[0]["Emirler"][0]["Sembol"], j[0]["Emirler"][0]["Adet"]);

	ASSERT_EQ(orderAmount, order->GetAmount());
}

TEST_F(OrderIntegrationTest, IsSetOrderAmountFromFileFunctional)
{
	int testOrderAmount = j[0]["Emirler"][0]["Adet"];
	order = new Order(j[0]["Emirler"][0]["Islem"], j[0]["Emirler"][0]["_id"], j[0]["Emirler"][0]["Sembol"], 0);
	order->SetAmount(testOrderAmount);

	ASSERT_EQ(testOrderAmount, order->GetAmount());
}

TEST_F(OrderIntegrationTest, IsSetOrderIDFromFileFunctional)
{
	string testOrderID = j[0]["Emirler"][0]["_id"];
	order = new Order(j[0]["Emirler"][0]["Islem"], "", j[0]["Emirler"][0]["Sembol"], 0);
	order->SetID(testOrderID);

	ASSERT_EQ(testOrderID, order->GetID());
}

TEST_F(OrderIntegrationTest, IsSetOrderTypeFromFileFunctional)
{
	string testOrderType = j[0]["Emirler"][0]["Islem"];
	order = new Order("", j[0]["Emirler"][0]["_id"], j[0]["Emirler"][0]["Sembol"], 0);
	order->SetOrderType(testOrderType);

	ASSERT_EQ(testOrderType, order->GetOrderType());
}

TEST_F(OrderIntegrationTest, IsSetOrderSymbolFromFileFunctional)
{
	string testOrderSymbol = j[0]["Emirler"][0]["Sembol"];
	order = new Order("", j[0]["Emirler"][0]["_id"], "", 0);
	order->SetSymbol(testOrderSymbol);

	ASSERT_EQ(testOrderSymbol, order->GetSymbol());
}