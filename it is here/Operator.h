#pragma once
#include <iostream>
#include <unordered_map>

using namespace std; 

class Operator
{
	string operatorID; 
	string operatorBrand;
	unordered_map<string, unsigned int > Data ;
public :
	Operator() = default;
	Operator(string opeoperatorID, string operatorBrand) :
		operatorID(operatorID), operatorBrand(operatorBrand) {
		Data =
		{ { "MTC" , 0 }  , { "MOC" , 0 } , { "SMS-MT" , 0 } ,  { "SMS-MO" , 0 } , { "GPRSD" , 0} , { "GPRSU" , 0 } };
	}

	void addData(string callType, int value)
	{
		auto it = Data.find(callType);
		if (it == Data.end())
			return;

		Data[callType] += value; 
	}

	unsigned int getData(string callType)
	{
		return Data[callType];
	}
	string getId()
	{
		return operatorID;
	}
};