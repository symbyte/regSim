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
