#include <iostream>
#include <unordered_map>
#include <string>
#include "Customer.h"
using namespace std;


void Customer::updateMsisdn(string msisdn)
{
	this->MSISDN = msisdn;
}
void Customer::updateNetworkBrand(string brand)
{
	this->brand = brand; 
}
string Customer::getMsisdn()
{
	return MSISDN; 
}
string Customer::getNetworkBrand()
{
	return brand; 
}



	Customer::Customer(string MSISDN) :
		MSISDN(MSISDN) {
		Data1
			= { { "MTC" , 0 }  , { "MOC" , 0 } , { "SMS-MT" , 0 } ,  { "SMS-MO" , 0 } };
		Data2
			= { { "MTC" , 0 }  , { "MOC" , 0 } , { "SMS-MT" , 0 } ,  { "SMS-MO" , 0 } };
		internet
			= { { "GPRSD" , 0 }, { "GPRSU" , 0 } };

	}


	void Customer::addData(string infoType, string callType, int value)
	{
//		cout << "inside top----\n";
	//	cout << callType << endl;
		if (infoType == "1")
			addLocalData(callType, value);
		else if (infoType == "2")
			addOutsideData(callType, value);
		else if (infoType == "3")
			addInterNetData(callType, value);
	}


	void Customer::addLocalData(string callType, int value)
	{
//		cout << "inside top----\n";
//		cout << callType << endl;
		/*
		auto it = Data1.find(callType);
		if (it == Data1.end())
			return;
		*/
	//	cout << "Inside " << value << endl;
		Data1[callType] += value;
		cout << "Inside2 " << Data1[callType] << endl;
	}

	void Customer::addOutsideData(string callType, int value)
	{
		/*
		auto it = Data2.find(callType);
		if (it == Data2.end())
			return;
			*/
	//	cout << "Inside " << value << endl;
		Data2[callType] += value;
		cout << "Inside2 " << Data2[callType] << endl;
	}

	void Customer::addInterNetData(string callType, int value)
	{
		/*
		auto it = internet.find(callType);
		if (it == internet.end())
			return;
			*/
//		cout << "Inside " << value << endl;
		internet[callType] += value;
		cout << "Inside2 " << internet[callType] << endl;
	}

	unordered_map<string, unsigned int > Customer::getData(string infoType)
	{
		if (infoType == "1")
			return getLocalData();
		else if (infoType == "2")
			return getOutNetworkData();
		else if (infoType == "3")
			return getInterNetData();
		return {};
	}

	unordered_map<string, unsigned int > Customer::getLocalData()
	{
		return Data1;
	}

	unordered_map<string, unsigned int > Customer::getOutNetworkData( )
	{
		return Data2;
	}

	unordered_map<string, unsigned int > Customer::getInterNetData( )
	{
		return internet;
	}
