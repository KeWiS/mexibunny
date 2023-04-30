#include "randomizer.h"

int utility::Randomizer::getRandomIntegerInRange(int start, int end) {
    auto numberGenerator = getNumberGenerator();
    std::uniform_int_distribution<int> distribution(start, end);

    return distribution(numberGenerator);
}

std::mt19937 utility::Randomizer::getNumberGenerator() {
    std::random_device randomDevice;

    return std::mt19937(randomDevice());
}
