#pragma once
#include <iostream>
#include <iostream>
#include <unordered_map>
#include <string>
#include "CustomersDatabase.h"
#include "Customer.h"
#include "Operator.h"
#include "OperatorDatabase.h"
#include "getDatafromFile.h"
#include "Credential.h"

using namespace std;

class ProcessingClass
{

public:
	ProcessingClass() = default;

	bool processingFun(OperatorsDatabase& OpDb, CustomersDatabase& cDb);
private:
	bool processCustomerbill(CustomersDatabase& cDb);
	bool processInterOperatorbill(OperatorsDatabase& cDb);
	bool printCustomerBillToscreen(string msisdn,  Customer& c);
	bool printCustomerBillFile(CustomersDatabase& cDb);

};