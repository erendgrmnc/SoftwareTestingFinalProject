#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include "../YazilimTestiProje/json.hpp"
#include "../YazilimTestiProje/Bank.hpp"

using json = nlohmann::json;

class BankIntegrationTest : public::testing::Test
{
protected:
	static void SetUpTestCase();
	static void TearDownTestCase();
	static Bank* bank;
	static json* j;
	static ifstream* i;
public:
	BankIntegrationTest();
	~BankIntegrationTest();

private:

};
Bank* BankIntegrationTest::bank = NULL;
json* BankIntegrationTest::j = NULL;
ifstream* BankIntegrationTest::i = NULL;