#pragma once
#include "pch.h"
#include "../YazilimTestiProje/Portfolio.hpp"
class PortfolioTest :public::testing::Test
{
protected:
	static void SetUpTestCase();
	static void SetUpTestCase(UserStock* userStock, int lotCount);
	static void TearDownTestCase();
	static Portfolio* portfolio;
public:
	PortfolioTest();
	~PortfolioTest();

private:

};

Portfolio* PortfolioTest::portfolio = NULL;
