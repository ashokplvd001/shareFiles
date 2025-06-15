#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std; 

class Customer
{
		string MSISDN;
		string brand;
		unordered_map<string, unsigned int > Data1;
			
		unordered_map<string, unsigned int > Data2;
		
		unordered_map<string, unsigned int > internet;

	public:
		Customer() = default;
		Customer(string MSISDN);
		void addData(string infoType, string callType, int value);

private :
	void addLocalData(string callType, int value);
	void addOutsideData(string callType, int value);
	void addInterNetData(string callType, int value);

public:
	unordered_map<string, unsigned int > getData(string infoType);
	void updateMsisdn(string msisdn);
	void updateNetworkBrand(string brand);
	string getMsisdn();
	string getNetworkBrand();
private :
	unordered_map<string, unsigned int > getLocalData();
	unordered_map<string, unsigned int > getOutNetworkData();

	unordered_map<string, unsigned int > getInterNetData();
};