//Name : Kyle
//Instructor : Dr. Tiziana Ligorio
//Project 3

#ifndef TAVERN_HPP
#define TAVERN_HPP

#include "ArrayBag.hpp"
#include "Character.hpp"

class Tavern : public ArrayBag<Character>
{
    private:
        int level_sum_;
        int enemy_count_;

    public:
        //constructor
        Tavern();

        //enter and exit tavern
        bool enterTavern(const Character &pCharacter);
        bool exitTavern(const Character &pCharacter);

        //level methods
        int getLevelSum() const;
        int calculateAvgLevel() const;

        //enemy methods
        int getEnemyCount() const;
        double calculateEnemyPercentage() const;

        //race tally
        int tallyRace(const std::string &pRace) const;

        //tavern display
        void tavernReport() const;
};

#endif //TAVERN_HPP