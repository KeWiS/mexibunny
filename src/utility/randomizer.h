#ifndef MEXIBUNNY_RANDOMIZER_H
#define MEXIBUNNY_RANDOMIZER_H

#include <random>

namespace utility {
    class Randomizer {
    public:
        static int getRandomIntegerInRange(int start, int end);

    private:
        Randomizer() = default;

        static std::mt19937 getNumberGenerator();
    };
}

#endif //MEXIBUNNY_RANDOMIZER_H
