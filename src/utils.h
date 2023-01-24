#ifndef UTILS_H
#define UTILS_H

#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <chrono>

bool is_valid(char* str);
void parse(char* str, int* res);
std::string generate_random();
void print_expr(int arr[4], std::string prefix, std::string op1, std::string op2, std::string op3, std::string suffix);
void append_to_ftext(std::string str);
void save_to_text(std::string filename);

#endif