#pragma once
#include <iostream>
#include "CustomersDatabase.h"
#include "Customer.h"
#include "Operator.h"
#include "OperatorDatabase.h"
#include <thread>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std; 

class ExtractFromFile
{
	string fileName;

public:
	ExtractFromFile(string fileName)
	{
		this->fileName = fileName;
	}

	bool ExtractData(CustomersDatabase & db1, OperatorsDatabase & db2 )
	{
		/*
		ExtractCustomerData(db1);
		ExtractOperatorData(db2);
		*/
//	/*
		thread t1( &ExtractFromFile::ExtractCustomerData , this, std::ref(db1));
		thread t2(&ExtractFromFile::ExtractOperatorData, this, std::ref(db2));
		t1.join();
		//t2.join();
	//	*/
		cout << "Proccessed the CDR data\n";
		return true;
	}
private :
	void ExtractCustomerData(CustomersDatabase& db)
	{
		fstream file((char*)fileName.c_str(), ios::in);
		string line, word, msisdn , AnetworkId , networdName , calltype ,  BnteworkId ;
		int value; 
		int i = 0; 
			while (getline(file, line))
			{
		//		cout << "i1 = " << i++ << endl;
				//cout << "okok\n";
			/*	transform(line.begin(), line.end(), line.end(),
					[](char& ch) { if (ch == '|') ch = ' '; return ch;});
			*/
				/*
				stringstream ss(line);
				ss >> msisdn;
				cout << "msisdn" << msisdn << endl;
				*/

			//line.replace(line.begin(), line.end(), '|', ' ');
				for (int i = 0; i < line.size(); i++)
				{
					if (line.at(i) == '|')		line.at(i) = ' ';
				}
			
			//cout << "okok\n";
				stringstream ss(line);
				ss >> msisdn;
				cout << "msisdn" << msisdn << endl;
				ss >> networdName;
				cout << networdName << endl;
				ss >> AnetworkId;
				cout << AnetworkId << endl;
				ss >> calltype; 
				cout << calltype << endl;
				
				if (calltype == "MOC" || calltype == "MTC" )
				{
					ss >> value ;	// first column
					cout << value << endl;
					for (int i = 0; i < 4; i++)
					{
						ss >> word;
						cout << word << endl;
					}
						ss >> word;
						cout << word << endl;
					ss >> BnteworkId;
					cout << word << endl;
					if (AnetworkId == BnteworkId)
						db.addData(msisdn, AnetworkId,  "1", calltype , value);
					else
						db.addData(msisdn, AnetworkId, "2", calltype, value);

				}
				else if( calltype == "SMS-MO"  || calltype == "SMS-MT" )
				{
					for (int i = 0; i < 5; i++)
					{
						ss >> word;
						cout << word << endl;
					}
						
						value = 1; 
					ss >> BnteworkId;
					cout << BnteworkId << endl;

					if (AnetworkId == BnteworkId)
						db.addData(msisdn, AnetworkId, "1", calltype, value);
					else
						db.addData(msisdn, AnetworkId,"2", calltype, value);

				}
				else if (calltype == "GPRS")
				{
					ss >> word;
					cout << word << endl;
					ss >> value;
					cout << value << endl;
					int value2; 
					ss >> value2;
					cout << value2 << endl;
					
					if (value != 0)
						db.addData(msisdn, AnetworkId, "3", calltype+'D', value);
					else
						db.addData(msisdn, AnetworkId,"3", calltype + 'U', value2);
				}


			}
			file.close();
	}

	void ExtractOperatorData(OperatorsDatabase& db)
	{
		fstream file((char*)fileName.c_str(), ios::in);
		string line, word, msisdn, AnetworkId, networdName, calltype, BnteworkId;
		int value;
		int i = 0;
		while (getline(file, line))
		{
	//		cout << "i2 = " << i++ << endl;
			/*
			transform(line.begin(), line.end(), line.end(),
				[](char& ch) { if (ch == '|') ch = ' '; return ch;});
				*/

	//		line.replace(line.begin(), line.end(), '|', ' ');
		
			for (int i = 0; i < line.size(); i++)
			{
				if (line.at(i) == '|')		line.at(i) = ' ';
			}

			stringstream ss(line);
			ss >> msisdn;
			ss >> networdName;
			ss >> AnetworkId;
			ss >> calltype;

			if (calltype == "MOC" || calltype == "MTC")
			{
				ss >> value;	// first column
				db.addData(msisdn,  calltype, value);
				

			}
			else if (calltype == "SMS-MO" || calltype == "SMS-MT")
			{
				value = 1;
					db.addData(msisdn, calltype, value);
			}
			else if (calltype == "GPRS")
			{
				ss >> word;
				ss >> value;
				int value2;
				ss >> value2;

				if (value != 0)
					db.addData(msisdn , calltype + 'D', value);
				else
					db.addData(msisdn,  calltype + 'U', value2);
			}

		}
		file.close();
	}
	

};