#ifndef FLIPFLOP01_H
#define FLIPFLOP01_H
class Flipflop
{
	private:
	char state;

	public:
	Flipflop()
	{
		this->state = '0';
	}
	void setState(char newState)
	{
		this->state = newState;
	}
	char getState()
	{
		return this->state;
	}
	char compState()
	{
		return this->state == '0'? '1': '0';
	}
	
};

#endif
