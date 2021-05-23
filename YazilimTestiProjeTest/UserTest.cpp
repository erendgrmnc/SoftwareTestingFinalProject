#include "pch.h"
#include "UserTest.h"

void UserTest::SetUpTestCase()
{
	user = new User();
}

void UserTest::SetUpTestCase(float currency, int lotCount)
{
	user = new User(currency, lotCount);
}

void UserTest::SetUpTestCase(Portfolio* portfolio, float currency)
{
	user = new User(portfolio, currency);
}

void UserTest::SetUpTestCase(string userID, string name, Portfolio* portfolio, float currency)
{
	user = new User(userID, name, portfolio, currency);
}

void UserTest::SetUpTestCase(string userID, string name, Portfolio* portfolio, float currency, Order* order, int orderCount)
{
	user = new User(userID, name, portfolio, currency, order, orderCount);
}

void UserTest::TearDownTestCase()
{
	user = NULL;
}

UserTest::UserTest()
{

}

UserTest::~UserTest()
{
	delete user;
}


TEST_F(UserTest, IsPortfolioTrueAdressTest) {
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock, testAmount);
	Portfolio* userPortfolio = new Portfolio(userStock, testAmount);
	float userCurrency = 500.0;

	SetUpTestCase(userPortfolio, userCurrency);

	ASSERT_EQ(userPortfolio, user->GetPortfolio());
	delete testStock, userStock, userPortfolio;
}

TEST_F(UserTest, IsSetPortfolioFunctionalAdressTest) {
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock, testAmount);
	Portfolio* userPortfolio = new Portfolio(userStock, testAmount);
	float userCurrency = 500.0;

	SetUpTestCase(userPortfolio, userCurrency);

	Stock* newTestStock = new Stock("123456", "AKBNK", "AKBANK", (float)5.1);
	int newTestAmount = 150;
	UserStock* newUserStock = new UserStock(testStock, testAmount);
	Portfolio* newUserPortfolio = new Portfolio(userStock, testAmount);


	user->SetPortfolio(newUserPortfolio);

	ASSERT_EQ(newUserPortfolio, user->GetPortfolio());
	delete testStock, userStock, userPortfolio, newTestStock, newUserStock, newUserPortfolio;
}

TEST_F(UserTest, IsSetPortfolioFunctionalUserStockAdressTest) {
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock, testAmount);
	Portfolio* userPortfolio = new Portfolio(userStock, testAmount);
	float userCurrency = 500.0;

	SetUpTestCase(userPortfolio, userCurrency);

	Stock* newTestStock = new Stock("123456", "AKBNK", "AKBANK", (float)5.1);
	int newTestAmount = 150;
	UserStock* newUserStock = new UserStock(testStock, testAmount);
	Portfolio* newUserPortfolio = new Portfolio(userStock, testAmount);


	user->SetPortfolio(newUserPortfolio);

	ASSERT_EQ(userPortfolio->GetUserStocks(), user->GetPortfolio()->GetUserStocks());
	delete testStock, userStock, userPortfolio;
}

TEST_F(UserTest, IsPortfolioNameValueTrueTest) {
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock, testAmount);
	Portfolio* userPortfolio = new Portfolio(userStock, testAmount);
	float userCurrency = 500.0;

	string testID = "123456789";
	string testName = "Eren Degirmenci";
	SetUpTestCase(testID, testName, userPortfolio, userCurrency);

	ASSERT_EQ(testName, user->GetName());

	delete testStock, userStock, userPortfolio;
}

TEST_F(UserTest, IsPortfolioIDValueTrueTest) {
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock, testAmount);
	Portfolio* userPortfolio = new Portfolio(userStock, testAmount);
	float userCurrency = 500.0;

	string testID = "123456789";
	string testName = "Eren Degirmenci";
	SetUpTestCase(testID, testName, userPortfolio, userCurrency);

	ASSERT_EQ(testID, user->GetUserID());

	delete testStock, userStock, userPortfolio;
}

TEST_F(UserTest, IsPortfolioSetNameFunctional) {
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock, testAmount);
	Portfolio* userPortfolio = new Portfolio(userStock, testAmount);
	float userCurrency = 500.0;

	string testID = "123456789";
	string testName = "Eren Degirmenci";
	SetUpTestCase(testID, testName, userPortfolio, userCurrency);

	user->SetName(testName);
	ASSERT_EQ(testName, user->GetName());

	delete testStock, userStock, userPortfolio;
}

TEST_F(UserTest, IsUserOrderAdressTrue)
{
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock, testAmount);
	Portfolio* userPortfolio = new Portfolio(userStock, testAmount);
	float userCurrency = 500.0;

	string testID = "123456789";
	string testName = "Eren Degirmenci";
	int orderCount = 100;
	Order* order = new Order("12345", "SATIS", "AKSA", orderCount);
	SetUpTestCase(testID, testName, userPortfolio, userCurrency,order,orderCount);

	ASSERT_EQ(order,user->GetOrders());
	delete testStock, userStock, userPortfolio,order;
}

TEST_F(UserTest, IsUserSetOrderFunctional)
{
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock, testAmount);
	Portfolio* userPortfolio = new Portfolio(userStock, testAmount);
	float userCurrency = 500.0;

	string testID = "123456789";
	string testName = "Eren Degirmenci";
	int orderCount = 100;
	Order* order = new Order("12345", "SATIS", "AKSA", orderCount);
	SetUpTestCase(testID, testName, userPortfolio, userCurrency, order, orderCount);

	int newOrderCount = 250;
	Order* newOrder = new Order("2345678", "ALIS", "AKBNK", orderCount);
	user->SetOrders(newOrder);
	ASSERT_EQ(newOrder, user->GetOrders());
	delete testStock, userStock, userPortfolio, order,newOrder;
}

TEST_F(UserTest,IsUserCurrencyValueTrue)
{
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock, testAmount);
	Portfolio* userPortfolio = new Portfolio(userStock, testAmount);
	float userCurrency = 500.0;

	string testID = "123456789";
	string testName = "Eren Degirmenci";
	int orderCount = 100;
	Order* order = new Order("12345", "SATIS", "AKSA", orderCount);
	SetUpTestCase(testID, testName, userPortfolio, userCurrency, order, orderCount);

	ASSERT_EQ(userCurrency, user->GetCurrency());
	delete testStock, userStock, userPortfolio, order;
}

TEST_F(UserTest, IsSetCurrencyFunctional)
{
	Stock* testStock = new Stock("12345", "PAPIL", "PAPILION SAVUNMA", (float)12.4);
	int testAmount = 150;
	UserStock* userStock = new UserStock(testStock, testAmount);
	Portfolio* userPortfolio = new Portfolio(userStock, testAmount);
	float userCurrency = 500.0;

	string testID = "123456789";
	string testName = "Eren Degirmenci";
	int orderCount = 100;
	Order* order = new Order("12345", "SATIS", "AKSA", orderCount);
	SetUpTestCase(testID, testName, userPortfolio, userCurrency, order, orderCount);

	float newCurrency = 245.0;
	user->SetCurrency(newCurrency);
	ASSERT_EQ(newCurrency, user->GetCurrency());
	delete testStock, userStock, userPortfolio, order;
}