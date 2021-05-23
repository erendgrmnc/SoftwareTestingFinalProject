#include "pch.h"
#include "FileOperationsTest.h"

void FileOperationsTest::SetUpTestCase()
{
	fop = new FileOperations();
}

void FileOperationsTest::SetUpTestCase(string fileName)
{
	fop = new FileOperations(fileName);
}

void FileOperationsTest::TearDownTestCase()
{
	fop = NULL;
}

FileOperationsTest::FileOperationsTest()
{
}

FileOperationsTest::~FileOperationsTest()
{
	delete fop;
}


TEST_F(FileOperationsTest,IsSeperateFileNameFunctional)
{
	string fileName = "yazilimTesti.txt";
	string returnValue = fop->SeperateFileName(fileName);
	ASSERT_TRUE("yazilimTesti" == returnValue);
}
