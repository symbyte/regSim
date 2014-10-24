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
