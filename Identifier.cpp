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
/*алгоритм работы метода инкрементации
проходим по листу с конца, реверсивным итератором
увеличиваем цифру
провер€ем перешел ли разр€д цифры
если флаг true увеличиваем букву до тех пор пока она не будет удовлетвор€ть условию
если флаг false выходим из цикла с новым значением группы
если после всех манипул€ций в элементе с индексом [1] находитс€ группа "A1", добавл€ем разр€д
провер€ем длину,  если длина удовлетвор€ет условию парсим лист в строку, очищаем лист и возвращаем новый id 
или выводим информацию о достиженнии максимальной длины идентификатора
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
