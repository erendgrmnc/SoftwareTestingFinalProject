#pragma once
#include "pch.h"
#include "../YazilimTestiProje/User.hpp"
class UserTest :public::testing::Test
{

protected:
	static void SetUpTestCase();
	static void SetUpTestCase(float currency, int lotCount);
	static void SetUpTestCase(Portfolio* portfolio,float currency);
	static void SetUpTestCase(string userID,string name,Portfolio* portfolio,float currency);
	static void SetUpTestCase(string userID,string name,Portfolio* portfolio,float currency,Order* order,int orderCount);
	static void TearDownTestCase();
	static User* user;
public:
	UserTest();
	~UserTest();

private:

};

User* UserTest::user = NULL; 