#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "CustomersDatabase.h"
#include "Customer.h"
#include "Operator.h"
#include "OperatorDatabase.h"
#include "getDatafromFile.h"
#include "Credential.h"
#include "ProcessingClass.h"
#include <fstream>

using namespace std;


bool ProcessingClass::processingFun(OperatorsDatabase& OpDb, CustomersDatabase& cDb) {
	char opt;
	
	do
	{
		std::cout << "1. customerBill\n2. InterOperatorBill\n3. Exit\n";

		cin >> opt;
		switch (opt)
		{
		case '1':
			processCustomerbill(cDb);
			break;
		case '2':
			processInterOperatorbill(OpDb);
			break;
		case '3':
			break;
		}
	} while (opt != '3');
	return true; 
}

bool processInterOperatorbill(OperatorsDatabase& OpDb) {
	auto data = OpDb.getDb();

	fstream file("Operators.cdr", ios::out);

	cout << "# Operator Data Base:\n";
	

	for (auto it : data)
	{
		auto it2 = it.second;
		
		file << "------------------------\n";
		file << "Operator Brand: " << it.first << " (" << it2.getId() << ")";
		file << " * Services within the mobile operator *";
		auto data = it2.getData();
		file << "Incoming voice call durations : " << data["MTC"] << endl;
		file << "Outgoing voice call durations : " << data["MOC"] << endl;
		file << "Incoming SMS messages : " << data["SMS-O"] << endl;
		file << "Outgoing SMS messages : " << data["SMS-MT"] << endl;
		file << "MB downloaded : " << data["GPRSD"] << " | MB uploaded : "
			<< data["GPRSU"] << endl;
		file << "------------------------\n";

		
	}
	file.close();
}



bool ProcessingClass::printCustomerBillToscreen(  string msisdn ,  Customer& c)
{
	auto data1 = c.getData("1");
	cout << "Customer ID : " << msisdn; // << " (" << JIO << ")\n";
	cout << " * Services within the mobile operator *";
	cout << "Incoming voice call durations : " << data1["MTC"] << endl;
	cout << "Outgoing voice call durations : " << data1["MOC"] << endl;
	cout << "Incoming SMS messages : " << data1["SMS-MO"] << endl;
	cout << "Outgoing SMS messages : " << data1["SMS-MT"] << endl;
		auto data2 = c.getData("2");
		cout << "* Services outside the mobile operator * ";
		cout << "Incoming voice call durations : " << data2["MTC"] << endl;
		cout << "Outgoing voice call durations : " << data2["MOC"] << endl;
		cout << "Incoming SMS messages : " << data2["SMS-MO"] << endl;
		cout << "Outgoing SMS messages : " << data2["SMS-MT"] << endl;
		cout << "* Internet use *" << endl;
		auto data3 = c.getData("3");
		cout << "MB downloaded : " << data3["GPRSD"] <<  " | MB uploaded : "
			<<data3["GPRSU"] << endl;
		
		return true;
}

bool ProcessingClass::processCustomerbill( CustomersDatabase& cDb)
{
	string msisdn;
	char opt ;
	do
	{
		cout << "1. Bill for MSISDN\n2. All Bills to file : ";
		cin >> opt;

		switch (opt)
		{
		case '1':
			cout << "Enter the MSISDN :";
			cin >> msisdn;
			auto it = cDb.getDb().find(msisdn);
			if (it == cDb.getDb().end())
				cout << "The msisdn is not found\n";
			else
				printCustomerBillToscreen(msisdn, it->second);
			break;
		case '2':
			printCustomerBillFile(cDb);break;
		default:
			cout << "Invalid option\n";
			break;
		case '3':
			break;

		}
	} while (opt != '3');
	return true;
}


bool ProcessingClass::printCustomerBillFile(CustomersDatabase& cDb)
{
	auto data = cDb.getDb();
	
	fstream file("customerdata.cdr", ios::out);

	for (auto it : data)
	{
		auto it2 = it.second;

		file << "------------------------\n";
		file << "Customer ID : " << it2.getMsisdn() << " (" << it2.getNetworkBrand() << ")\n";
		file << " * Services within the mobile operator *";
		auto data1 = it2.getData("1");
		file << "Incoming voice call durations : " << data1["MTC"] << endl;
		file << "Outgoing voice call durations : " << data1["MOC"] << endl;
		file << "Incoming SMS messages : " << data1["SMS-O"] << endl;
		file << "Outgoing SMS messages : " << data1["SMS-MT"] << endl;
		auto data2 = it2.getData("2");
		file << "* Services outside the mobile operator * ";
		file << "Incoming voice call durations : " << data2["MTC"] << endl;
		file << "Outgoing voice call durations : " << data2["MOC"] << endl;
		file << "Incoming SMS messages : " << data2["SMS-O"] << endl;
		file << "Outgoing SMS messages : " << data2["SMS-MT"] << endl;
		file << "* Internet use *" << endl;
		auto data3 = it2.getData("3");
		file << "MB downloaded : " << data3["GPRSD"] << " | MB uploaded : "
			<< data3["GPRSU"] << endl;
		file << "------------------------\n";
	}
	file.close();



	return true;
}

