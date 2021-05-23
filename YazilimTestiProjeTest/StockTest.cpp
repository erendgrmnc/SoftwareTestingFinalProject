#include "pch.h"
#include "StockTest.h"

void StockTest::SetUpTestCase()
{
	stock = new Stock();
}

void StockTest::SetUpTestCase(string stockID, string stockName, string stockSymbol, float stockPrice)
{
	stock = new Stock(stockID, stockName, stockSymbol, stockPrice);
}

void StockTest::TearDownTestCase()
{
	stock = NULL;
}

StockTest::StockTest()
{
}

StockTest::~StockTest()
{
	delete this->stock;
}

TEST_F(StockTest, IsStockPriceCorrect) {
	SetUpTestCase("12345", "BTCIM", "BATI CIMENTO", 17.00);
	ASSERT_EQ(17.00, stock->GetPrice());
}

TEST_F(StockTest, IsStockPriceTypeCorrect) {
	SetUpTestCase("12345", "BTCIM", "BATI CIMENTO", 17.00);
	ASSERT_EQ(typeid(float), typeid(stock->GetPrice()));
}


TEST_F(StockTest, IsStockIDTypeCorrect) {
	SetUpTestCase("12345", "BTCIM", "BATI CIMENTO", 17.00);
	ASSERT_EQ(typeid(string), typeid(stock->GetID()));
}

TEST_F(StockTest, IsStockIDCorrect) {
	SetUpTestCase("12345", "BTCIM", "BATI CIMENTO", 17.00);
	ASSERT_EQ("12345", stock->GetID());
}

TEST_F(StockTest, IsStockSymbolCorrect) {
	SetUpTestCase("12345", "BTCIM", "BATI CIMENTO", 17.00);
	ASSERT_EQ("BTCIM", stock->GetSymbol());
}

TEST_F(StockTest, IsStockSymbolTypeCorrect) {
	SetUpTestCase("12345", "BTCIM", "BATI CIMENTO", 17.00);
	ASSERT_EQ(typeid(string), typeid(stock->GetSymbol()));
}

TEST_F(StockTest, IsStockNameCorrect) {
	SetUpTestCase("12345", "BTCIM", "BATI CIMENTO", 17.00);
	ASSERT_EQ("BATI CIMENTO", stock->GetName());
}

TEST_F(StockTest, IsStockNameTypeCorrect) {
	SetUpTestCase("12345", "BTCIM", "BATI CIMENTO", 17.00);
	ASSERT_EQ(typeid(string), typeid(stock->GetName()));
}

TEST_F(StockTest, IsStockSetIDCorrect) {
	SetUpTestCase("12345", "BTCIM", "BATI CIMENTO", 17.00);
	stock->SetID("123456");
	ASSERT_EQ("123456", stock->GetID());
}

TEST_F(StockTest, IsStockSetSymbolCorrect) {
	SetUpTestCase("12345", "BTCIM", "BATI CIMENTO", 17.00);
	stock->SetSymbol("BTCIM CIM");
	ASSERT_EQ("BTCIM CIM", stock->GetSymbol());
}

TEST_F(StockTest, IsStockSetNameCorrect) {
	SetUpTestCase("12345", "BTCIM", "BATI CIMENTO", 17.00);
	stock->SetName("BATI CIMENTO CIMENTO");
	ASSERT_EQ("BATI CIMENTO CIMENTO", stock->GetName());
}

TEST_F(StockTest, IsStockSetPriceCorrect) {
	SetUpTestCase("12345", "BTCIM", "BATI CIMENTO", 17.00);
	stock->SetPrice(18.5);
	ASSERT_EQ(18.5, stock->GetPrice());
}


