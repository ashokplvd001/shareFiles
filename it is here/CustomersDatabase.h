#pragma once
#include <iostream>
#include <unordered_map>
#include "Customer.h"

class CustomersDatabase
{
	unordered_map<string, Customer> cutomerDb ;
public:
	CustomersDatabase() = default;

	void addData(string MSISDN ,string brand  ,string infoType , string callType , int value   )
	{
	//	cout << "customeraddData--------->\n";
		auto it = cutomerDb.find(MSISDN);
		if (it == cutomerDb.end())
		{
			cutomerDb[MSISDN] = {};
			cutomerDb[MSISDN].updateMsisdn(MSISDN);
			cutomerDb[MSISDN].updateNetworkBrand(brand);
//			cout << "insideif\n";
		}

		cutomerDb[MSISDN].addData(infoType, callType, value);
		//cout << "customeraddData--------->>\n";
	}

	unordered_map<string, unsigned int > getData(string MSISDN, string infoType)
	{
		return cutomerDb[MSISDN].getData(infoType );
	}
	 unordered_map<string, Customer> & getDb( )
	{
		return cutomerDb;
	}

};
