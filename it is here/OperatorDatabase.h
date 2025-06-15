#pragma once
#include <iostream>
#include <unordered_map>
#include "Operator.h"

class OperatorsDatabase
{
	unordered_map<string, Operator> OperatorDb;
public:
	OperatorsDatabase()
	{
		OperatorDb = 
		{ { "42500" , {"42500", "Cellcom"}} , { "42501" ,{ "42501" ,"Patner"}} ,
			{ "42502" ,{"42502" , "Jio"} } , { "42503" ,{ "42503" ,"Airtel"}} ,
			{ "42504" ,{ "42504" ,"012"}}
		};
	}

	void addData(string Operatorid , string callType, int value)
	{
		OperatorDb[Operatorid].addData( callType, value);
	}

	unsigned int getData(string Operatorid,string callType)
	{
		return OperatorDb[Operatorid].getData(callType);
	}

	unordered_map<string, Operator> getDb()
	{
		return OperatorDb;
	}

};