/*----------------------------------------------------------*/
 //Author:	Steven Chambers
 //Student ID: 	*20342421
 //E-mail:	schambers4@uco.edu
 //Course: 	CMSC 3833 - Computer Organization II 
 //CRN:		11404, Autumn 2014
 //Project: 	p01
 //Due: 	November 10, 2014
 //Account: 	tt002
/*---------------------------------------------------------*/
#ifndef REGISTER01_H
#define REGISTER01_H

#include <vector>
#include <string>
#include "Flipflop01.h"

using namespace std;

class Register
{
	private:
	vector<Flipflop> flipflops;
	int numFlipFlops;	

	public:
	Register(int numFlipFlops);
	string regOr(Register& compare);
	string regAnd(Register& compare);
	string regNot();
	string regXOR(Register& compare);
	string regXNOR(Register& compare);
	void regLoad(string toLoad);
	string printReg();

};

#endif
