#ifndef FLIPFLOP01_H
#define FLIPFLOP01_H
class Flipflop
{
	private:
	char state;

	public:
	Flipflop();
	void setState(char);
	char getState();
	char compState();
	
};

#endif
