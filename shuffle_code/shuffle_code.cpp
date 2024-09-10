#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include "shuffle_code.h"

std::map<char, char> & shuffle_code() {
    static std::map<char, char> shuffle_code;
    return shuffle_code;
}

void generate_shuffle(const unsigned int seed) {
    std::vector<char> characters;
    for (int i = 32; i <= 126; i++) {
        characters.push_back(static_cast<char>(i));
    }

    std::vector<char> shuffled_characters = characters;

    std::mt19937 generator(seed);
    std::shuffle(shuffled_characters.begin(), shuffled_characters.end(), generator);

    for (int i = 0; i < characters.size(); i++) {
        shuffle_code()[characters[i]] = shuffled_characters[i];
    }
}