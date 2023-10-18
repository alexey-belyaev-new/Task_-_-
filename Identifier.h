#pragma once
#include <list>
#include "IdentifierGroup.h"
#include <string>

class Identifier
{
public:	
	void installId(std::string id); //����� ��������� ��������
	std::string inc();				//����� �������������

private:
	std::list<IdentifierGroup> listGroup;  //������ ������������� ��� ���� �����
	std::string newIdentifier{ "A1" };		//������ ��� �������� ������ ��������������
	int maxSize{10};						//������������ ������ �������������� 10 �����

	bool checkLenght();						//����� �������� ����� ��������������
	void parseList();						//����� �������� �� ����� � ������
};





