#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include "../YazilimTestiProje/json.hpp"
#include "../YazilimTestiProje/UserStock.hpp"

using json = nlohmann::json;

class UserStockIntegrationTest :public::testing::Test
{
protected:
	static void SetUpTestCase();
	static void TearDownTestCase();

	static UserStock* userStock;
	static json* j;
	static ifstream* i;
public:
	UserStockIntegrationTest();
	~UserStockIntegrationTest();

private:

};
UserStock* UserStockIntegrationTest::userStock = NULL;
json* UserStockIntegrationTest::j = NULL;
ifstream* UserStockIntegrationTest::i = NULL;