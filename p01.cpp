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
			cout<<"op: " <<op << endl;
			switch(op)
			{
				case '+':
						o << "op code: 000 operation: R0 <-- R0 XOR R1"<<endl;
						break;	
				case 'v':
						o << "op code: 001 operation: R0 <-- R0 OR R1"<<endl;
						break;
				case '-':
						o << "op code: 010 operation: R0 <-- R0 XNOR R1"<<endl;
						break;
				case '^':
						o << "op code: 011 operation: R0 <-- R0 AND R1"<<endl;
						break;
				case 'l':
						o << "op code: 100 operation: R0 <-- D"<<endl;
						break;
				case 'L':
						o << "op code: 101 operation: R1 <-- D"<<endl;
						break;
				case 'p':
						o << "op code: 110 operation: Print R0 "<<endl;
						break;
				case 'P':
						o << "op code: 111 operation: Print R1"<<endl;
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
