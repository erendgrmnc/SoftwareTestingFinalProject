#pragma once
#include "pch.h"
#include "../YazilimTestiProje/UserStock.hpp"
class UserStockTest : public::testing::Test
{

protected:
	static void SetUpTestCase();
	static void SetUpTestCase(Stock* stock, int amount);
	static void SetUpTestCase(Stock* stock, int amount,float profit);
	static void TearDownTestCase();
	static UserStock* userStock;
public:
	UserStockTest();
	~UserStockTest();

private:

};

UserStock* UserStockTest::userStock = NULL;