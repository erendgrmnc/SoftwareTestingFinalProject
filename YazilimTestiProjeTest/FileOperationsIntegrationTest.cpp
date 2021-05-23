#include "pch.h"
#include "FileOperationsIntegrationTest.h"

void FileOperationsIntegrationTest::SetUpTestCase()
{
	fop = new FileOperations();
}

void FileOperationsIntegrationTest::TearDownTestCase()
{
	fop = NULL;
}

FileOperationsIntegrationTest::FileOperationsIntegrationTest()
{
	fop = new FileOperations();
}

FileOperationsIntegrationTest::~FileOperationsIntegrationTest()
{
	delete fop;
}

TEST_F(FileOperationsIntegrationTest, IsFileNameTrue)
{
	string fileNameWithoutFileType = "Hisseler";
	fop->OpenJSON("Hisseler.json");

	ASSERT_TRUE(fileNameWithoutFileType == fop->GetFileName());
}

TEST_F(FileOperationsIntegrationTest, IsSeperateFileNameFunctional)
{
	string test = "Hisseler";
	string fileName = "hisseler.json";
	fop->OpenJSON("Hisseler.json");
	string fileNameWithoutFileType = fop->SeperateFileName(fileName);
	ASSERT_TRUE(test == fop->GetFileName());
}

TEST_F(FileOperationsIntegrationTest,IsReturnSizeFromFileTrue )
{
	ifstream* i = new ifstream("hisseler.json");
	json* j = new json();
	i[0] >> j[0];
	fop->OpenJSON("Hisseler.json");
	
	ASSERT_TRUE(j[0]["Hisseler"].size() == fop->ReturnCount());

	delete i, j;
}

TEST_F(FileOperationsIntegrationTest, IsSetStocksFunctional)
{
	ifstream* i = new ifstream("hisseler.json");
	json* j = new json();
	i[0] >> j[0];
	string testID = j[0]["Hisseler"][0]["_id"];

	fop->OpenJSON("Hisseler.json");
	Stock* testStocks = new Stock[fop->ReturnCount()];
	fop->SetStocks(testStocks, fop->ReturnCount());
	ASSERT_EQ(testID, testStocks[0].GetID());

	delete i, j,testStocks;
}

TEST_F(FileOperationsIntegrationTest, IsSetUserStocksFunctional)
{
	ifstream* i = new ifstream("portfoy.json");
	json* j = new json();
	i[0] >> j[0];
	int stockSize = j[0]["Portfoy"].size();

	UserStock* userStocks = new UserStock[stockSize];

	for (int i = 0; i < stockSize; i++)
	{
		Stock* stock = new Stock(j[0]["Portfoy"][i]["_id"], j[0]["Portfoy"][i]["Sembol"], j[0]["Portfoy"][i]["Maliyet"]);
		int testAmount = (int)j[0]["Portfoy"][0]["Adet"];
		userStocks[i].SetStock(stock);
		userStocks[i].SetAmount(testAmount);
	}
	
	fop->OpenJSON("Portfoy.json");
	UserStock* testStocks = new UserStock[fop->ReturnCount()];
	fop->SetUserStocks(testStocks, fop->ReturnCount());
	ASSERT_EQ(userStocks[0].GetStock()->GetID(), testStocks[0].GetStock()->GetID());

	delete i, j, testStocks, userStocks;
}

TEST_F(FileOperationsIntegrationTest, IsSetOrdersFunctional)
{
	ifstream* i = new ifstream("emirler.json");
	json* j = new json();
	i[0] >> j[0];
	int orderSize = j[0]["Emirler"].size();

	Order* orders = new Order[orderSize];

	for (int i = 0; i < orderSize; i++)
	{
		orders[i].SetOrder(j[0]["Emirler"][0]["Islem"], j[0]["Emirler"][0]["_id"], j[0]["Emirler"][0]["Sembol"], j[0]["Emirler"][0]["Adet"]);
	}

	fop->OpenJSON("Emirler.json");
	Order* testOrders = new Order[fop->ReturnCount()];
	fop->SetOrders(testOrders, fop->ReturnCount());
	ASSERT_EQ(orders[0].GetID(), testOrders[0].GetID());

	delete i, j, orders, testOrders;
}
