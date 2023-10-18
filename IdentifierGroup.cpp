#include "IdentifierGroup.h"

IdentifierGroup::IdentifierGroup(char letterInit, char numberInit)
{
	letter = letterInit;
	number = numberInit;
	flagNum = false ;
	flagLet = false;
}

char IdentifierGroup::getLetter()
{
	return letter;
}

char IdentifierGroup::getNumber()
{
	return number;
}

bool IdentifierGroup::getFlagNum()
{
	return flagNum;
}

bool IdentifierGroup::getFlagLet()
{
	return flagLet;
}

void IdentifierGroup::incLetter()
{
	++letter;
	if (letter > 'Z') {
		letter = 'A';
		flagLet = true;
	}
}

void IdentifierGroup::incNumber()
{
	++number;
	if (number > '9') {
		number = '1';
		flagNum = true;
	}
}

bool IdentifierGroup::checkLetter()
{
	if (letter == 'D' ||
		letter == 'F' ||
		letter == 'G' ||
		letter == 'J' ||
		letter == 'M' ||
		letter == 'Q' ||
		letter == 'V' ||
		letter < 'A' ||
		letter > 'Z'
		) {
		return true;
	}
	else {
		return false;
	}
}

bool IdentifierGroup::checkNumber()
{
	if (number <= '0' || number > '9') {
		return false;
	}
	return true;
}
