#pragma once
#include "pch.h"
#include "../YazilimTestiProje/Bank.hpp"

class BankTest: public::testing::Test
{
protected:
	static void SetUpTestCase();
	static void SetUpTestCase(Stock* stock, int stockCount);
	static void TearDownTestCase();
	static Bank* bank;
public:
	BankTest();
	~BankTest();

private:

};

Bank* BankTest::bank = NULL;

