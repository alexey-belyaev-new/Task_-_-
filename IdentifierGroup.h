#pragma once

/*����� ��� �������� ����� ��������������� A4,B4,Z9 � �.�.*/
class IdentifierGroup
{
public:
	IdentifierGroup(char letterInit, char numberInit);
	char getLetter(); //����� ��������� ����� �� ������
	char getNumber(); //����� ��������� ����� �� ������
	bool getFlagNum(); //����� ��������� �����, ���� true ���� ����� ������� ������ ������ 9 ����� ������������
	bool getFlagLet(); // ����� ��������� �����, ���� true ���� ����� ������� ������ ������ Z ����� ������������

	void incLetter(); //����� ���������� �����
	void incNumber(); //����� ���������� �����

	bool checkLetter(); //����� �������� ������������ �����, �� �������� �� ������
	bool checkNumber(); //����� �������� ������������ �����, �� �������� �� ������

private:
	char letter{}; 
	char number{};
	bool flagNum{ false };
	bool flagLet{ false };
};