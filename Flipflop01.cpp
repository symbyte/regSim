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
#include "Flipflop01.h"

Flipflop::Flipflop()
{
    this->state = '0';
}
void Flipflop::setState(char newState)
{
    this->state = newState;
}
char Flipflop::getState()
{
    return this->state;
}
char Flipflop::compState()
{
    return this->state == '0'? '1': '0';
}
