#include "pch.h"
#include "BankTest.h"



void BankTest::SetUpTestCase()
{
	bank = new Bank();
}

void BankTest::SetUpTestCase(Stock* stock, int stockCount)
{
	bank = new Bank(stock, stockCount); 
}

void BankTest::TearDownTestCase()
{
	bank = NULL;
}

BankTest::BankTest()
{
}

BankTest::~BankTest()
{
	delete bank;
}

TEST_F(BankTest, IsBankStockTrue)
{
	Stock* testBankStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)10.4);
	int testStockCount = 100;
	SetUpTestCase(testBankStock,testStockCount);
	ASSERT_EQ(testBankStock,bank->GetStocks());
	delete testBankStock;
}

TEST_F(BankTest, IsBankStockTypeCorrect)
{
	Stock* testBankStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)10.4);
	int testStockCount = 100;
	SetUpTestCase(testBankStock, testStockCount);
	ASSERT_EQ(typeid(testBankStock), typeid(bank->GetStocks()));
	delete testBankStock;
}

TEST_F(BankTest, ISBankStokcCountTrue)
{
	Stock* testBankStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)10.4);
	int testStockCount = 100;
	SetUpTestCase(testBankStock, testStockCount);
	ASSERT_EQ(testStockCount, bank->GetStockCount());
	delete testBankStock;
}

TEST_F(BankTest, IsBankStockCountTypeTrue)
{
	Stock* testBankStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)10.4);
	int testStockCount = 100;
	SetUpTestCase(testBankStock, testStockCount);
	ASSERT_EQ(typeid(testStockCount), typeid(bank->GetStockCount()));
	delete testBankStock;
}

TEST_F(BankTest, IsBankSetStockFunctional)
{
	Stock* testBankStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)10.4);
	int testStockCount = 100;
	SetUpTestCase(testBankStock, testStockCount);
	Stock* newTestStock = new Stock("123456789", "AKSA", "AKSA", (float)25.9);
	bank->SetStocks(newTestStock);
	ASSERT_EQ(newTestStock, bank->GetStocks());
	delete testBankStock,newTestStock;
}

TEST_F(BankTest, IsBankSetStockCountFunctional)
{
	Stock* testBankStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)10.4);
	int testStockCount = 100;
	SetUpTestCase(testBankStock, testStockCount);
	Stock* newTestStock = new Stock("123456789", "AKSA", "AKSA", (float)25.9);
	int newStockCount = 134;
	bank->SetStockCount(newStockCount);
	ASSERT_EQ(newStockCount, bank->GetStockCount());
	delete testBankStock, newTestStock;
}
