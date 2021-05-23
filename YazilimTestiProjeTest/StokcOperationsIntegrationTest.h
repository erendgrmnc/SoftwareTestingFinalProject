#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include "../YazilimTestiProje/json.hpp"
#include "../YazilimTestiProje/StockOperations.hpp"
#include "../YazilimTestiProje/FileOperations.hpp"
using json = nlohmann::json;

class StockOperationIntegrationTest : public::testing::Test
{
protected:
	static void SetUpTestCase();
	static void TearDownTestCase();
	static StockOperations* sop;
	static json* j;
	static ifstream* i;
public:
	StockOperationIntegrationTest();
	~StockOperationIntegrationTest();
	FileOperations* fop;
	Bank* bank;

private:
	


};

StockOperations* StockOperationIntegrationTest::sop = NULL;
json* StockOperationIntegrationTest::j = NULL;
ifstream* StockOperationIntegrationTest::i = NULL;