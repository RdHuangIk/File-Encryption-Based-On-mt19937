#include <iostream>
#include <fstream>
#include <algorithm>
#include "encrypt_file/encrypt_file.h"
#include "unencrypt_file/unencrypt_file.h"

int main() {
    std::fstream file_out;
    std::ifstream file_in;
    unsigned int seed = 0;
    std::string path;

    std::cout << "| PATH: ";
    std::getline(std::cin, path);
    std::replace(path.begin(), path.end(), '\\', '/');
    std::cout << std::endl;

    file_out.open(path);
    file_in.open(path);

    if (!file_out.is_open() || !file_in.is_open()) {
        std::cerr << "| FAILED TO OPEN FILE" << std::endl;
    } else {
        std::cout << "| SEED: ";
        (std::cin >> seed).get();
        std::cout << std::endl;

        if (!std::cin.fail()) {
            std::string MODE;
            std::cout << "| MODE([E] for encrypt; [U] for unencrypt): ";
            (std::cin >> MODE).get();
            std::cout << std::endl;

            if (!std::cin.fail()) {
                if (MODE == "E") {
                    encrypt_file(file_out, file_in, seed);
                    std::cout << "| DONE" << std::endl;
                    std::cin.get();
                }
                else if (MODE == "U") {
                    un_encrypt_file(file_out, file_in, seed);
                    std::cout << "| DONE" << std::endl;
                    std::cin.get();
                }
                else std::cout << "| UNKNOWN MODE" << std::endl;
            } else std::cerr << "| INPUT ERROR" << std::endl;
        } else std::cerr << "| INPUT ERROR" << std::endl;
    }

    file_in.close();
    file_out.close();
    return 0;
}
