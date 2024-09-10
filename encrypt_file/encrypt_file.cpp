#include "encrypt_file.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void encrypt_file(std::fstream & file_out, std::ifstream & file_in, const unsigned int seed) {
    generate_shuffle(seed);

    std::string text;
    std::string shuffled_text;
    std::ostringstream ss;
    ss << file_in.rdbuf();
    text = ss.str();

    for (int i = 0; i < text.size(); i++) {
        if (text[i] != '\n') {
            shuffled_text.push_back(shuffle_code().find(text[i]) -> second);
        } else if (text[i] == '\n') {
            shuffled_text.push_back('\n');
        }
    }

    file_out << shuffled_text;
}