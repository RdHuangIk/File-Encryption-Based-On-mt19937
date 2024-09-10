#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../shuffle_code/shuffle_code.h"
#include "../un_shuffle_code/un_shuffle_code.h"
#include "unencrypt_file.h"

void un_encrypt_file(std::fstream & file_out, std::ifstream & file_in, const unsigned int seed) {
    generate_un_shuffle(seed);

    std::string text;
    std::string un_shuffled_text;
    std::ostringstream ss;
    ss << file_in.rdbuf();
    text = ss.str();

    for (int i = 0; i < text.size(); i++) {
        if (text[i] != '\n') {
            un_shuffled_text.push_back(un_shuffle_code().find(text[i]) -> second);
        } else if (text[i] == '\n') {
            un_shuffled_text.push_back('\n');
        }
    }

    file_out << un_shuffled_text;
}