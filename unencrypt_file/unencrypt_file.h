#ifndef UNTITLED1_UNENCRYPT_FILE_H
#define UNTITLED1_UNENCRYPT_FILE_H

#include <iostream>
#include <fstream>
#include <string>
#include "../shuffle_code/shuffle_code.h"

void un_encrypt_file(std::fstream & file_out, std::ifstream & file_in, const unsigned int seed);

#endif //UNTITLED1_UNENCRYPT_FILE_H
