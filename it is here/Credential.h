#pragma once
#include <iostream>
#include<unordered_map>
#include <string>

using namespace std; 

class Credential
{
	unordered_map<string, string> credential;
	public:
		Credential() = default;

		bool signIn(string userName, string pass);
		bool loginIn(string userName, string pass);
};