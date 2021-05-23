#pragma once
#include "pch.h"
#include "../YazilimTestiProje/StockOperations.hpp"

class StockOperationsTest :public::testing::Test
{
protected:
	static void SetUpTestCase();
	static void SetUpTestCase(Bank* bank);
	static void TearDownTestCase();
	static StockOperations* sop;
public:
	StockOperationsTest();
	~StockOperationsTest();

private:

};

StockOperations* StockOperationsTest::sop = NULL;