#pragma once
#include "pch.h"
#include "../YazilimTestiProje/FileOperations.hpp"

class FileOperationsTest : public::testing::Test
{

protected:
	static void SetUpTestCase();
	static void SetUpTestCase(string fileName);
	static void TearDownTestCase();
	static FileOperations* fop;
public:
	FileOperationsTest();
	~FileOperationsTest();

private:

};

FileOperations* FileOperationsTest::fop = NULL;