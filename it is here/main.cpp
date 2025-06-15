#include <iostream>
//#include <unordered_map>
#include <string>
//#include "CustomersDatabase.h"
//#include "Customer.h"
//#include "Operator.h"
//#include "OperatorDatabase.h"
//#include "getDatafromFile.h"
//#include "Credential.h"
//#include "ProcessingClass.h"

using namespace std;

int main()
{
	/*ExtractFromFile fileHandler( "data.cdr" );
	CustomersDatabase custDb ; 
	OperatorsDatabase opDb; */

	//ProcessingClass processObj;
	cout << "WelCome to the Application\n";

	/*fileHandler.ExtractData(custDb, opDb);

	Credential creditsDb;*/

	//cout << "1. Signup\n2. Login\n3. Exit\n";
	char opt;
	
	string username; 
	string password; 
	do
	{
		cout << "1. Signup\n2. Login\n3. Exit\n";
		cin >> opt; 
		switch( opt )
		{
			case '1':
				cout << "Enter user name and passwor : ";
				cin >> username >> password;
			//	creditsDb.signIn(username, password);
				cout << "Successfully signup , thankyou , welcome\n";
				break;
			case '2':
				cout << "Enter user name and passwor : ";
				cin >> username >> password;
			/*	if (creditsDb.loginIn(username, password))
					processObj.processingFun(opDb, custDb );*/
				break;
			case '3':
				break;
		}	

	} while (opt != '3');

}


