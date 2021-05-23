#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include "../YazilimTestiProje/json.hpp"
#include "../YazilimTestiProje/User.hpp"
using json = nlohmann::json;
class UserIntegrationTest:public::testing::Test
{
protected:
	static void SetUpTestCase();
	static void TearDownTestCase();
	static json* j;
	static ifstream* i;
	static User* user;
public:
	UserIntegrationTest();
	~UserIntegrationTest();

private:

};


User* UserIntegrationTest::user = NULL;
json* UserIntegrationTest::j = NULL;
ifstream* UserIntegrationTest::i = NULL;