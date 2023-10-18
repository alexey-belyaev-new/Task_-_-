#pragma once

/* ласс дл€ хранени€ групп идентификаторов A4,B4,Z9 и т.д.*/
class IdentifierGroup
{
public:
	IdentifierGroup(char letterInit, char numberInit);
	char getLetter(); //метод получени€ буквы из группы
	char getNumber(); //метод получени€ цифры из группы
	bool getFlagNum(); //метод получени€ флага, флаг true если число перешло разр€д больше 9 после инрементации
	bool getFlagLet(); // метод получени€ флага, флаг true если буква перешлф разр€д больше Z после инрементации

	void incLetter(); //метод увеличени€ буквы
	void incNumber(); //метод увеличени€ цифры

	bool checkLetter(); //метод проверки корректности буквы, по услови€ю из задачи
	bool checkNumber(); //метод проверки корректности цифры, по услови€ю из задачи

private:
	char letter{}; 
	char number{};
	bool flagNum{ false };
	bool flagLet{ false };
};