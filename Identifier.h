#pragma once
#include <list>
#include "IdentifierGroup.h"
#include <string>

class Identifier
{
public:	
	void installId(std::string id); //метод установки значения
	std::string inc();				//метод инкрементации

private:
	std::list<IdentifierGroup> listGroup;  //храним идентификатор как лист групп
	std::string newIdentifier{ "A1" };		//строка для хранения нового идентификатора
	int maxSize{10};						//максимальный размер идентификатора 10 групп

	bool checkLenght();						//метод проверки длины идентификатора
	void parseList();						//метод парсинга из листа в строку
};





