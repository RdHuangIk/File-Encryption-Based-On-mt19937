#include <map>
#include "un_shuffle_code.h"

std::map<char, char> & un_shuffle_code() {
    static std::map<char, char> un_shuffle_code;
    return un_shuffle_code;
}

void generate_un_shuffle(const unsigned int seed) {
    generate_shuffle(seed);

    for (int i = 32; i <= 126; i++) {
        un_shuffle_code()[shuffle_code().find(static_cast<char>(i)) -> second] = static_cast<char>(i);
    }
}