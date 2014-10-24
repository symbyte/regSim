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
