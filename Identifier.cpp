#include "Identifier.h"
#include <mutex>
std::mutex mInst;
std::mutex mInc;
std::once_flag flag;

void Identifier::installId(std::string id)
{	
	std::lock_guard<std::mutex> la{ mInst }; 
	newIdentifier = "";
	newIdentifier = id;
	listGroup.clear();
	size_t size = id.size();
	for (int i = 0; i < size; i += 3)
	{
		listGroup.push_back(IdentifierGroup(id[i], id[i + 1]));
	}
}
/*�������� ������ ������ �������������
�������� �� ����� � �����, ����������� ����������
����������� �����
��������� ������� �� ������ �����
���� ���� true ����������� ����� �� ��� ��� ���� ��� �� ����� ������������� �������
���� ���� false ������� �� ����� � ����� ��������� ������
���� ����� ���� ����������� � �������� � �������� [1] ��������� ������ "A1", ��������� ������
��������� �����,  ���� ����� ������������� ������� ������ ���� � ������, ������� ���� � ���������� ����� id 
��� ������� ���������� � ����������� ������������ ����� ��������������
*/
std::string Identifier::inc()
{
	std::lock_guard<std::mutex> la{ mInst };
	for (auto revIt{ listGroup.rbegin() }; revIt != listGroup.rend(); ++revIt) {	
		revIt->incNumber();
		if (revIt->getFlagNum()) {
			revIt->incLetter();
			while (revIt->checkLetter()) {
				revIt->incLetter();
			}
			if (std::next(revIt) == listGroup.rend() && revIt->getFlagLet()) {
				listGroup.push_back(IdentifierGroup('A', '1'));
				break;
			}
		}else { break; }
	}
	if (checkLenght()) {		
		parseList();
 		listGroup.clear();		
		return newIdentifier;
	}
	else
	{
		listGroup.clear();
		return "Max lenght." + newIdentifier;
	}
	
}

bool Identifier::checkLenght()
{
	if (maxSize > listGroup.size()) {
		return true;
	}
	return false;
}

void Identifier::parseList()
{
	newIdentifier = "";
	for (auto it{ listGroup.begin() }; it != listGroup.end(); ++it) {
		if (std:: next(it) == listGroup.end()) {
			newIdentifier.push_back(it->getLetter());
			newIdentifier.push_back(it->getNumber());
		}
		else {
			newIdentifier.push_back(it->getLetter());
			newIdentifier.push_back(it->getNumber());
			newIdentifier.push_back('-');
		}
	}
}
