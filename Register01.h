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
	Register(int numFlipFlops)
	{
		this->numFlipFlops = numFlipFlops;
		for(int i = 0; i < numFlipFlops;i++)
		{
			flipflops.push_back(Flipflop());
		}	
	}
	string regOr(Register& compare)
	{
		string output = string(numFlipFlops, '0');
		for(int i = 0; i < numFlipFlops; i++)
		{
			if(!(this->flipflops.at(i).getState()== '0' && compare.flipflops.at(i).getState()== '0'))
				output[i] = '1';
		}
		return output;
	}
	string regAnd(Register& compare)
	{
		string output = string(numFlipFlops, '0');
		for(int i = 0; i < numFlipFlops; i++)
		{
			if(this->flipflops.at(i).getState()== '1' && compare.flipflops.at(i).getState()== '1')
				output[i] = '1';
		}
		return output;

	}
	string regNot()
	{
		string output = string(numFlipFlops, '0');
		for(int i = 0; i < numFlipFlops; i++)
		{
				output[i] = this->flipflops.at(i).compState();
		}
		return output;

	}
	string regXOR(Register& compare)
	{
		string tmp = this->regXNOR(compare);
		for(int i = 0; i < numFlipFlops; i++)
		{
			if(tmp[i] == '1')
				tmp[i] = '0';
			else 
				tmp[i] = '1';
		}
		return tmp;	
	}
	string regXNOR(Register& compare)
	{
		string R0not = this->regNot();
		string R1not = compare.regNot();
		string tmp= string(numFlipFlops, '0');
		for(int i = 0;i < numFlipFlops; i++)
		{
			if(R0not[i] == '1'&& R1not[i] =='1')
				tmp[i] = '1';
		}
		string R0andR1 = this->regAnd(compare);
		string output= string(numFlipFlops,'0');
	      	for(int i = 0; i < numFlipFlops; i++)
		{
			if(!(tmp[i] == '0' && R0andR1[i] == '0'))
				output[i] = '1';

		}
		return output;	

	}
	void regLoad(string toLoad)
	{
		for(int i = 0; i < numFlipFlops; i++)
		{
			this->flipflops.at(i).setState(toLoad[i]);
		}
		
		
	}
	string printReg()
	{
		string output = string(numFlipFlops, '0');
		for(int i = 0; i < numFlipFlops;i++)
		{	
			if(this->flipflops.at(i).getState() == '1')
				output[i] = '1';	
		}
		return output;
	}
	

};

#endif
