#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include "../YazilimTestiProje/json.hpp"
#include "../YazilimTestiProje/Portfolio.hpp"
using json = nlohmann::json;

class PortfolioIntegrationTest : public::testing::Test
{
protected:
	static void SetUpTestCase();
	static void TearDownTestCase();
	static Portfolio* portfolio;
	static json* j;
	static ifstream* i;
public:
	PortfolioIntegrationTest();
	~PortfolioIntegrationTest();

private:

};
Portfolio* PortfolioIntegrationTest::portfolio = NULL;
json* PortfolioIntegrationTest::j = NULL;
ifstream* PortfolioIntegrationTest::i = NULL;