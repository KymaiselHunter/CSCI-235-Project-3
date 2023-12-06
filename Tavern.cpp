//Name : Kyle
//Instructor : Dr. Tiziana Ligorio
//Project 3
#include "Tavern.hpp"

//For getting rounded average
#include <cmath> 

//Constructor
/**
    Default constructor.
    Default-initializes all private members. 
*/
Tavern::Tavern()
{
    level_sum_ = 0;
    enemy_count_ = 0;
}

//enter and exit tavern
/** @param:   A const reference to a Character entering the Tavern
    @return:  returns true if a Character was successfully added to the tavern (i.e. items_),                 false otherwise
    @post:    adds Character to the Tavern and updates the level sum and the enemy count 
              if the character is an enemy.
 **/
bool Tavern::enterTavern(const Character &pCharacter) 
{
    if(!this->add(pCharacter)) return false;

    level_sum_ += pCharacter.getLevel();
    if(pCharacter.isEnemy()) enemy_count_++;

    return true;
}

/** @param:   A const reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from the tavern (i.e. items_),               false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count
              if the character is an enemy.
 **/
bool Tavern::exitTavern(const Character&pCharacter)
{
    if(!this->remove(pCharacter)) return false;

    level_sum_ -= pCharacter.getLevel();
    if(pCharacter.isEnemy()) enemy_count_--;

    return true;
}

//level methods
/** 
    @return:  The integer level count of all the characters currently in the Tavern
 **/
int Tavern::getLevelSum() const
{
    return level_sum_;
}

/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Computes the average level of the Tavern rounded to the NEAREST integer.
 **/
int Tavern::calculateAvgLevel() const
{
    if(this->getCurrentSize() == 0) return 0;
    //std::cout << level_sum_ << " " <<this->getCurrentSize() << std::endl;
    return std::round((double)level_sum_ / this->getCurrentSize());
}


//enemy methods
/** 
    @return:  The integer enemy count of the Tavern
 **/
int Tavern::getEnemyCount() const
{
    return enemy_count_;
}

/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Computes the enemy percentage of the Tavern rounded up to 2 decimal places.
 **/
double Tavern::calculateEnemyPercentage() const
{
    if(this->getCurrentSize() == 0) return 0;
    //std::cout << enemy_count_  << " " <<this->getCurrentSize()  << " " << ((double)enemy_count_ / this->getCurrentSize())<< std::endl;
    //get average, multiply by 10000 to round the decimal points as an int a
    return (round(((double)enemy_count_ / this->getCurrentSize()) * 10000)/100);
}

/** 
    @param:   A const reference to a string representing a character Race with value in 
              ["NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"]
    @return:  An integer tally of the number of characters in the Tavern of the given race. 
              If the argument string does not match one of the expected race values, 
              the tally is zero. NOTE: no pre-processing of the input string necessary, only                  uppercase input will match.
 **/
int Tavern::tallyRace(const std::string &pRace) const
{
    if(pRace != "HUMAN" && pRace != "ELF" && pRace != "DWARF" &&
    pRace != "LIZARD" && pRace != "UNDEAD") return -1;

    int c = 0;
    
    for(int i = 0; i < this->getCurrentSize(); i++)
    {
        if(pRace == this->items_[i].getRace()) c++;
    }
    return c;
}

/**
@post:      Outputs a report of the characters currently in the tavern in the form:
            "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average             level is: [x] \n[x]% are enemies.\n"
            Note that the average level should be rounded to the NEAREST integer, and the enemy             percentage should be rounded to 2 decimal places.

            Example output: 
            Humans: 3
            Elves: 5
            Dwarves: 8
            Lizards: 6
            Undead: 0

            The average level is: 7
            46.67% are enemies.
*/
void Tavern::tavernReport() const
{
    std::cout << "Humans: " << this->tallyRace("HUMAN") << std::endl;
    std::cout << "Elves: " << this->tallyRace("ELF") << std::endl;
    std::cout << "Dwarves: " << this->tallyRace("DWARF") << std::endl;
    std::cout << "Lizards: " << this->tallyRace("LIZARD") << std::endl;
    std::cout << "Undead: " << this->tallyRace("UNDEAD") << std::endl;

    std::cout << "\nThe average level is: " << this->calculateAvgLevel() << std::endl;
    std::cout << this->calculateEnemyPercentage() << "% are enemies."<< std::endl;
}