#ifndef DIE_H
#define DIE_H

#include <ctime>
#include <cstdlib>

// Defines the immutable programmatic representation of a single die, e.g., one D6.
class Die {
    public:
        Die(const int sides);
        Die(const Die &die);

        // Accessors
        int getSides() const;
        int getResult() const;

    private:
        int roll(const int max, const int min = 1);
        int sides;
        int result;
};

#endif
