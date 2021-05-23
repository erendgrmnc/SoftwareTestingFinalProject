#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include "../YazilimTestiProje/json.hpp"
#include "../YazilimTestiProje/FileOperations.hpp"
using json = nlohmann::json;

class FileOperationsIntegrationTest : public::testing::Test
{
protected:
	static void SetUpTestCase();
	static void TearDownTestCase();
	static FileOperations* fop;
public:
	FileOperationsIntegrationTest();
	~FileOperationsIntegrationTest();

private:

};

FileOperations* FileOperationsIntegrationTest::fop = NULL;
