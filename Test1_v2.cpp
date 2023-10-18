#include <iostream>
#include "Identifier.h"
#include <thread>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    list<string> listId = { "A1", "A9", "Z9", "A1-Z9", "Z9-Z9", "Z9-Z8", "Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9" };
    Identifier identifier;
    string str;

    for (string& id : listId)
    {
        thread t(&Identifier::installId, &identifier, id);
        cout << "Identifier: " << id << endl;
        thread t2([&]() {str = identifier.inc(); });
        t.join();
        t2.join();
        cout << "Increase identifier: " << str << endl;
    }
    
    string s = "A2";
    string s1 = "Z9";
    string s2 = "A1-Z9";
    cout << "Identifier: " << s << endl;
    cout << "Identifier: " << s1 << endl;
    cout << "Identifier: " << s2 << endl;
    
    thread t1(&Identifier::installId, &identifier, s);    
    thread t2(&Identifier::installId, &identifier, s1);    
    thread t3(&Identifier::installId, &identifier, s2);      
     
    thread t4([&]() {s = identifier.inc(); });
    thread t5([&]() {s1 = identifier.inc(); });
    thread t6([&]() {s2 = identifier.inc(); });

    t1.join();
    t2.join();
    t3.join();
    
    t4.join();
    t5.join();
    t6.join();
    cout << "Increase identifier: " << s << endl;
    cout << "Increase identifier: " << s1 << endl;
    cout << "Increase identifier: " << s2 << endl;
}