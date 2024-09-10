cmake_minimum_required(VERSION 3.29)
project(encrypt_file)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(encrypt_file main.cpp
        encrypt_file/encrypt_file.h
        shuffle_code/shuffle_code.h
        unencrypt_file/unencrypt_file.h
        encrypt_file/encrypt_file.cpp
        unencrypt_file/unencrypt_file.cpp
        shuffle_code/shuffle_code.cpp
        un_shuffle_code/un_shuffle_code.h
        un_shuffle_code/un_shuffle_code.cpp)
