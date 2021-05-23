#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include "../YazilimTestiProje/json.hpp"
#include "../YazilimTestiProje/Order.hpp"
using json = nlohmann::json;

class OrderIntegrationTest : public::testing::Test
{
protected:
	static void SetUpTestCase();
	static void TearDownTestCase();

	static Order* order;
	static json* j;
	static ifstream* i;
public:
	OrderIntegrationTest();
	~OrderIntegrationTest();

private:

};
Order* OrderIntegrationTest::order = NULL;
json* OrderIntegrationTest::j = NULL;
ifstream* OrderIntegrationTest::i = NULL;