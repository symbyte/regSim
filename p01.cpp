//----------------------------------------------------------
// Author:	Steven Chambers
// Student ID: 	*20342421
// E-mail:	schambers4@uco.edu
// Course: 	CMSC 3833 - Computer Organization II 
// CRN:		11404, Autumn 2014
// Project: 	p01
// Due: 	November 10, 2014
// Account: 	tt060
//---------------------------------------------------------
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iomanip>
#include "Register01.h"


using namespace std;

struct CommandLineException 
{
	CommandLineException(int max, int actual)
	{
		cout << endl << "Too many command line arguments." << endl;
		cout << "a Maximum of " << max << " arguments are permitted" << endl;
		cout << actual << " arguments were entered." << endl;
	}
};

struct FileException
{	
	FileException(const char*fn)
	{
		cout << endl << "File " << fn << " could not be opened." << endl;
	}
};

char decoder(char c2, char c1, char c0)
{
	if(c2 == '0' && c1 == '0' && c0 == '0')
		return '+';
	if(c2 == '0' && c1 == '0' && c0 == '1')
		return 'v';
	if(c2 == '0' && c1 == '1' && c0 == '0')
		return '-';
	if(c2 == '0' && c1 == '1' && c0 == '1')
		return '^';
	if(c2 == '1' && c1 == '0' && c0 == '0')
		return 'l';
	if(c2 == '1' && c1 == '0' && c0 == '1')
		return 'L';
	if(c2 == '1' && c1 == '1' && c0 == '0')
		return 'p';
	if(c2 == '1' && c1 == '1' && c0 == '1')
		return 'P';
       	
}
char andGate(char first, char second)
{
	if(first == '1' && second == '1')
		return '1';
	else 
		return '0';
}
char orGate(char first, char second)
{
	if(first == '0' && second == '0')
		return '0';
	else 
		return '1';
}
char notGate(char sig)
{
	if(sig == '0')
		return '1';
	else
		return '0';
}
char* regAndGate(char R0[], char R1[])
{
	char* toReturn = new char[9];
	for(int i = 0; i <strlen(R0);i++)
	{
		toReturn[i] = andGate(R0[i], R1[i]);
	}
	toReturn[8] = '\0';
	return toReturn;	
		
}
char* regOrGate(char R0[], char R1[])
{
	char* toReturn = new char[9];
	for(int i = 0; i <strlen(R0);i++)
	{
		toReturn[i] = orGate(R0[i], R1[i]);
	}
	toReturn[8] = '\0';
	return toReturn;	
}
char* regNotGate(char R0[])
{
	char* toReturn = new char[9];
	for(int i = 0; i <strlen(R0);i++)
	{
		toReturn[i] = notGate(R0[i]);
	}
	toReturn[8] = '\0';
	return toReturn;	
}
void regLoad(char reg[],char data[])
{
	for(int i = 0; i <= strlen(reg);i++)
	{
		reg[i] = data[i];
	}
}

int main(int argc, char* argv[])
{

	try
	{
		char ifn[255], ofn[255];
		switch (argc)
		{
			case 1:
				cout << "Enter the input file name: ";
				cin >> ifn;
				cout << "Enter the output file name: ";
				cin >> ofn;
				break;
			case 2:
				strcpy(ifn, argv[1]);
				cout << "Enter the output file name: ";
				cin >> ofn;
				break;
			case 3: 
				strcpy(ifn, argv[1]);
				strcpy(ofn, argv[2]);
				break;
			default:
				throw CommandLineException(2, argc-1);
				break;
		}
		ifstream i(ifn);
		if(!i)
			throw FileException(ifn);
		ofstream o(ofn);
		if(!o)
			throw FileException(ofn);
		char R0[] = {'0','0','0','0','0','0','0','0','\0'};
		char R1[] = {'0','0','0','0','0','0','0','0','\0'};
		char* tmp;
		char* tmp2;
		char* tmp3;
		while(i.peek() != EOF)
		{
			char c2,c1,c0;
			char inString[255];
			char data[9];
			bool dataFound = false;
			i.getline(inString,255);
			if(strlen(inString) == 4)
			{
				c2 = inString[0];
				c1 = inString[1];
				c0 = inString[2];
			}
			else if(strlen(inString) == 13)
			{
				dataFound = true;
				c2 = inString[0];
				c1 = inString[1];
				c0 = inString[2];
				for (int i = 4;i < 12;i++)
				{
					data[i-4] = inString[i];
				}
				
				data [8] = '\0';
			}
			else
			{
				cout << "For shame! You did not follow the input file format!"<< endl;
				exit(EXIT_FAILURE);
			}
			char op = decoder(c2,c1,c0);
			switch(op)
			{
				case '+':
						o << setw(20) << setfill('-')<< "-" << endl;
						o << "Initial conditions: R0: " << string(R0) << " R1: " << string(R1) << endl;	
						o << "op code: 000 operation: R0 <-- R0 XOR R1"<<endl;
						tmp = regNotGate(R0);
						tmp2 = regNotGate(R1);
						tmp3 = regAndGate(tmp,tmp2);
						delete tmp,tmp2;
						tmp = regAndGate(R0,R1);
						tmp2 = regOrGate(tmp3,tmp);
						delete tmp3,tmp;
						tmp = regNotGate(tmp2);
						regLoad(R0,tmp);
						delete tmp,tmp2;
						o << "Post operation conditions: R0: " << string (R0) << " R1: "<< string(R1) << endl;
						o << setw(20) << setfill('-')<< "-" << endl << endl;	
						break;	
				case 'v':
						
						o << setw(20) << setfill('-')<< "-" << endl;
						o << "Initial conditions: R0: " << string(R0) << " R1: " << string(R1) << endl;	
						o << "op code: 001 operation: R0 <-- R0 OR R1"<<endl;
						tmp = regOrGate(R0,R1);
						regLoad(R0,tmp);
						delete tmp;
						o << "Post operation conditions: R0: " << string (R0) << " R1: "<< string(R1) << endl;
						o << setw(20) << setfill('-')<< "-" << endl << endl;	
						break;
				case '-':
						o << setw(20) << setfill('-')<< "-" << endl;	
						o << "Initial conditions: R0: " << string(R0) << " R1: " << string(R1) << endl;	
						o << "op code: 010 operation: R0 <-- R0 XNOR R1"<<endl; 
						tmp = regNotGate(R0);
						tmp2 = regNotGate(R1);
						tmp3 = regAndGate(tmp,tmp2);
						delete tmp,tmp2;
						tmp = regAndGate(R0,R1);
						tmp2 = regOrGate(tmp3,tmp);
						regLoad(R0,tmp2);
						delete tmp,tmp2,tmp3;
						o << "Post operation conditions: R0: " << string (R0) << " R1: "<< string(R1) << endl;
						o << setw(20) << setfill('-')<< "-" << endl << endl;	
						break;
				case '^':
						o << setw(20) << setfill('-')<< "-" << endl;	
						o << "Initial conditions: R0: " << string(R0) << " R1: " << string(R1) << endl;	
						o << "op code: 011 operation: R0 <-- R0 AND R1"<<endl;
						tmp = regAndGate(R0,R1); 
						regLoad(R0,tmp);
						delete tmp;
						o << "Post operation conditions: R0: " << string (R0) << " R1: "<< string(R1) << endl;
						o << setw(20) << setfill('-')<< "-" << endl << endl;	
						break;
				case 'l':
						o << setw(20) << setfill('-')<< "-" << endl;	
						o << "Initial conditions: R0: " << string(R0) << " R1: " << string(R1) << endl;	
						o << "op code: 100 operation: R0 <-- D"<<endl;
						regLoad(R0,data);
						o << "Post operation conditions: R0: " << string (R0) << " R1: "<< string(R1) << endl;
						o << setw(20) << setfill('-')<< "-" << endl<< endl;	
						break;
				case 'L':
						o << setw(20) << setfill('-')<< "-" << endl;	
						o << "Initial conditions: R0: " << string(R0) << " R1: " << string(R1) << endl;	
						o << "op code: 101 operation: R1 <-- D"<<endl;
						regLoad(R1,data);
						o << "Post operation conditions: R0: " << string (R0) << " R1: "<< string(R1) << endl;
						o << setw(20) << setfill('-')<< "-" << endl<< endl;	
						break;
				case 'p':
						o << setw(20) << setfill('-')<< "-" << endl;	
						o << "Initial conditions: R0: " << string(R0) << " R1: " << string(R1) << endl;	
						o << "op code: 110 operation: Print R0 "<<endl;
						o <<"R0 : " << string(R0) << endl;
						cout <<"R0: " <<  string(R0) << endl;
						o << "Post operation conditions: R0: " << string (R0) << " R1: "<< string(R1) << endl;
						o << setw(20) << setfill('-')<< "-" << endl<< endl;	
						break;
				case 'P':
						o << setw(20) << setfill('-')<< "-" << endl;	
						o << "Initial conditions: R0: " << string(R0) << " R1: " << string(R1) << endl;	
						o << "op code: 111 operation: Print R1"<<endl;
						o << "R1: " <<string(R1) << endl;
						cout <<"R1: " << string(R1) << endl;
						o << "Post operation conditions: R0: " << string (R0) << " R1: "<< string(R1) << endl;
						o << setw(20) << setfill('-')<< "-" << endl<< endl;	
						break;
				default:
						;


			}	
		}	

	}catch (...)
	{
		cout << "Program closed." << endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}
