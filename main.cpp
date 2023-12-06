//Name : Kyle
//Instructor : Dr. Tiziana Ligorio
//Project 3

#include <iostream>
using namespace std;

#include "Character.hpp"
#include "ArrayBag.hpp"
#include "Tavern.hpp"

int main()
{
    Character c;
    c.display();
    Character c2;

    Character c3("Kule", "HUMAN");

    cout << "c1 == c2 : " << (c == c2) << endl;
    cout << "c1 != c2 : " << (c != c2) << endl;

    cout << "c1 == c3 : " << (c == c3) << endl;
    cout << "c1 != c3 : " << (c != c3) << endl;

    ArrayBag<int> testBag1, testBag2;

    testBag1.add(1);
    testBag1.add(2);
    testBag1.add(3);

    testBag2.add(1);
    testBag2.add(4);

    cout << "test bag 1" << endl;
    for(int i = 1; i < 5; i++)
    {
        if(testBag1.contains(i)) cout << i << endl;
    }

    cout << "test bag 2" << endl;
    for(int i = 1; i < 5 ; i++)
    {
        if(testBag2.contains(i)) cout << i << endl;
    }

    cout << "test +=" << endl;
    testBag1 += testBag2;

    for(int i = 1; i < 5 ; i++)
    {
        if(testBag1.contains(i)) cout << i << " frequency: " << testBag1.getFrequencyOf(i)<< endl;
    }
    

    ArrayBag<int> testBag3, testBag4;

    testBag3.add(1);
    testBag3.add(2);
    testBag3.add(3);

    testBag4.add(1);
    testBag4.add(4);

    testBag3 /= testBag4;

    cout << "test /=" << endl;
    for(int i = 1; i < 5 ; i++)
    {
        if(testBag3.contains(i)) cout << i << " frequency: " << testBag3.getFrequencyOf(i)<< endl;
    }

    Tavern t;

    cout << "Initial tavern:" << endl;
    t.tavernReport();

    Character NPC1("SPYNACH", "ELF", 6, 4, 4, false);
    t.enterTavern(NPC1);

    Character NPC2("FLEA", "DWARF", 12, 7, 5, false);
    t.enterTavern(NPC2);

    Character NPC3("MARROW", "UNDEAD", 9, 6, 5, true);
    t.enterTavern(NPC3);

    Character NPC4("BONK", "HUMAN", 11, 5, 5, true);
    t.enterTavern(NPC4);

    Character NPC5("Kyle", "DWARF", 11, 5, 5, false);
    t.enterTavern(NPC5);

    Character NPC6("Kyle2", "DWARF", 11, 5, 5, false);
    t.enterTavern(NPC6);

    Character NPC7("Kyle3", "DWARF", 11, 5, 5, false);
    t.enterTavern(NPC7);
    
    cout << "\nFilled tavern: " << endl;
    t.tavernReport();

    cout << "\nEverybody Leaves the tavern:" << endl;

    t.exitTavern(NPC1);
    t.exitTavern(NPC2);
    t.exitTavern(NPC3);
    t.exitTavern(NPC4);
    t.exitTavern(NPC5);
    t.exitTavern(NPC6);
    t.exitTavern(NPC7);
        
    t.tavernReport();
}
