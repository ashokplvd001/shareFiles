#pragma once
#include <iostream>
#include<unordered_map>
#include <string>
#include "Credential.h"

using namespace std;



bool Credential::signIn(string userName, string pass)
{
	credential[userName] = pass;
	return true; 
}
bool Credential::loginIn(string userName, string pass)
{
	auto it = credential.find(userName);

	if (it == credential.end())
	{
		cout << "No user found--------------|\n";
		return false;
	}

	if (it->second != pass)
	{
		cout << "Wrong password\n";
			return false;
	}
	cout << "Welcome u r loged in\n";
	return true;

}
