#ifndef REGISTER01_H
#define REGISTER01_H

#include <vector>
#include <string>
#include "Flipflop01.h"

using namespace std;

class Register01
{
	private:
	vector<Flipflop01> flipflops;
	int numFlipFlops;	

	public:
	Register01(int numFlipFlops)
	{
		this->numFlipFlops = numFlipFlops;
		for(int i = 0; i < numFlipFlops;i++)
		{
			flipflops.push_back(Flipflop01());
		}	
	}
	string regOr(Register01& compare)
	{
		string output = string(numFlipFlops, '0');
		for(int i = 0; i < numFlipFlops; i++)
		{
			if(!(this->flipflops.at(i).getState()== '0' && compare.flipflops.at(i).getState()== '0'))
				output[i] = '1';
		}
		return output;
	}
	string regAnd(Register01& compare)
	{
		string output = string(numFlipFlops, '0');
		for(int i = 0; i < numFlipFlops; i++)
		{
			if(this->flipflops.at(i).getState()== '1' && compare.flipflops.at(i).getState()== '1')
				output[i] = '1';
		}
		return output;

	}
	string regNot(Register01& compare)
	{
		string output = string(numFlipFlops, '0');
		for(int i = 0; i < numFlipFlops; i++)
		{
				output[i] = compare.flipflops.at(i).compState();
		}
		return output;

	}
	string regXOR(Register01& compare)
	{
		
	}
	string regXNOR(Register01& compare)
	{

	}
	void regLoad(string toLoad)
	{
		for(int i = 0; i < numFlipFlops; i++)
		{
			this->flipflops.at(i).setState(toLoad[i]);
		}
		
	}
	

};

#endif
