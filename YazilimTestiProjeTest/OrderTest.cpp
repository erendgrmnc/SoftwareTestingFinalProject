#include "pch.h"
#include "OrderTest.h"

void OrderTest::SetUpTestCase()
{
	order = new Order();
}

void OrderTest::SetUpTestCase(string ID, string orderType, string symbol, int amount)
{
	order = new Order(orderType, ID, symbol, amount);
}

void OrderTest::TearDownTestCase()
{
	order = NULL;
}

OrderTest::OrderTest()
{
}

OrderTest::~OrderTest()
{
	delete order;
}

TEST_F(OrderTest,IsOrderIDTrue) {
	SetUpTestCase("12345","SATIS","AKSA",100);
	ASSERT_EQ("12345",order->GetID());
}

TEST_F(OrderTest,IsOrderIDTypeTrue) {
	SetUpTestCase("12345", "SATIS", "AKSA", 100);
	ASSERT_EQ(typeid(string), typeid(order->GetID()));
}

TEST_F(OrderTest, IsOrderTypeTrue) {
	SetUpTestCase("12345", "SATIS", "AKSA", 100);
	ASSERT_EQ("SATIS", order->GetOrderType());
}

TEST_F(OrderTest, IsTypeOfOrderTypeTrue) {
	SetUpTestCase("12345", "SATIS", "AKSA", 100);
	ASSERT_EQ(typeid(string), typeid(order->GetOrderType()));
}

TEST_F(OrderTest, IsSymbolTrue) {
	SetUpTestCase("12345", "SATIS", "AKSA", 100);
	ASSERT_EQ("AKSA", order->GetSymbol());
}

TEST_F(OrderTest, IsSymbolTypeTrue) {
	SetUpTestCase("12345", "SATIS", "AKSA", 100);
	ASSERT_EQ(typeid(string), typeid(order->GetOrderType()));
}

TEST_F(OrderTest, IsAmountTrue) {
	SetUpTestCase("12345", "SATIS", "AKSA", 100);
	ASSERT_EQ(100, order->GetAmount());
}

TEST_F(OrderTest, IsAmountTypeTrue) {
	SetUpTestCase("12345", "SATIS", "AKSA", 100);
	ASSERT_EQ(typeid(100), typeid(order->GetAmount()));
}

TEST_F(OrderTest, IsSetIDFunctional) {
	SetUpTestCase("12345", "SATIS", "AKSA", 100);
	string testID = "123456";
	order->SetID(testID);
	ASSERT_EQ(testID, order->GetID());
}

TEST_F(OrderTest, IsSetOrderTypeFunctional) {
	SetUpTestCase("12345", "SATIS", "AKSA", 100);
	string testOrderType = "ALIS";
	order->SetOrderType(testOrderType);
	ASSERT_EQ(testOrderType, order->GetOrderType());
}

TEST_F(OrderTest, IsSetOrderSymbolFunctional) {
	SetUpTestCase("12345", "SATIS", "AKSA", 100);
	string testOrderSymbol = "BTCIM";
	order->SetSymbol(testOrderSymbol);
	ASSERT_EQ(testOrderSymbol, order->GetSymbol());
}

TEST_F(OrderTest, IsSetAmountFunctional) {
	SetUpTestCase("12345", "SATIS", "AKSA", 100);
	int testOrderAmount = 31;
	order->SetAmount(testOrderAmount);
	ASSERT_EQ(testOrderAmount, order->GetAmount());
}
