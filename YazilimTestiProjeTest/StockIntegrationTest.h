#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include "../YazilimTestiProje/json.hpp"
#include "../YazilimTestiProje/Stock.hpp"

using namespace std;
using json = nlohmann::json;
using namespace StockNameSpace;

class StockIntegrationTest : public::testing::Test
{
protected:
	static void SetUpTestCase();
	static void TearDownTestCase();
	static Stock* stock;
	static json* j;
	static ifstream* i;
public:
	StockIntegrationTest();
	~StockIntegrationTest();

private:
	
};

Stock* StockIntegrationTest::stock = NULL;
json* StockIntegrationTest::j = NULL;
ifstream* StockIntegrationTest::i = NULL;