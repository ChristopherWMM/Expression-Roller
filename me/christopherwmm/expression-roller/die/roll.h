#ifndef ROLL_H
#define ROLL_H

#include "die.h"
#include <string>
#include <vector>

// Defines the immutable programmatic representation of a combine set of dice rolls, e.g., 4D6.
class Roll {
    public:
        Roll();
        Roll(const int rolls, const int sides);
        Roll(const std::string dice);
        Roll(const std::vector<Die> dice);
        Roll(const Roll &roll);

        // Accessors / Mutators
        int getNumberOfDice() const;
        void setNumberOfDice(const int numberOfDice);
        int getSides() const;
        void setSides(const int sides);
        int getRangeMax() const;
        void setRangeMax(const int rangeMax);
        int getRangeMin() const;
        void setRangeMin(const int rangeMin);
        int getResult() const;
        std::vector<Die> getDice() const;
        void setDice(std::vector<Die> dice);

    private:
        std::vector<Die> parseRollFormula(std::string);

        int numberOfDice;
        int sides;
        int rangeMax;
        int rangeMin;
        std::vector<Die> newDice;
        std::vector<Die> dice;
};

class MalformedDieRollException {};

class InvalidDieNumberException {};

class InconsistentDieSidesException {};

#endif
