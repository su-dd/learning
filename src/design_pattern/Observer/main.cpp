#include <iostream>
#include "MarketingDepartment.h"
#include "ProductDepartment.h"
using namespace std;

int main(int argc, char* argv[])
{
	MarketingDepartment oMarketingDepartment;
	ProductDepartment oProductDepartment;

	oMarketingDepartment.addObServer(&oProductDepartment);

	oMarketingDepartment.sell(2);
	return 0;
}