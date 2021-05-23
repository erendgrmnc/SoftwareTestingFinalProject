#pragma once
#include "pch.h"
#include "../YazilimTestiProje/Order.hpp"

class OrderTest : public::testing::Test
{

protected:
	static void SetUpTestCase();
	static void SetUpTestCase(string ID, string orderType, string symbol, int amount);
	static void TearDownTestCase();
	static Order* order;

public:
	OrderTest();
	~OrderTest();

private:

};

Order* OrderTest::order = NULL;