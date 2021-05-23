#include "../YazilimTestiProje/Stock.hpp"
using namespace StockNameSpace;


#pragma once
	class StockTest :public::testing::Test
	{
	protected:
		static void SetUpTestCase();
		static void SetUpTestCase(string stockID, string stockName, string stockSymbol, float stockPrice);
		static void TearDownTestCase();
		static Stock* stock;

	public:
		StockTest();
		~StockTest();
	private:


	};

	Stock* StockTest::stock = NULL;

