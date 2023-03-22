#ifndef PASSWORD_CRACKER_H // header guard
#define PASSWORD_CRACKER_H

#include <iostream>
#include <string>
#include <chrono>

using string = std::string;


string getPassword();
string randomGeneratePassword(const string& password);

void bruteForceLoop(const string& password, string& predicted_PSW);

void printResults(string password, string predicted_PSW, decltype(std::chrono::high_resolution_clock::now()) start, decltype(std::chrono::high_resolution_clock::now()) end);
void printDuration(const std::chrono::high_resolution_clock::time_point& start, const std::chrono::high_resolution_clock::time_point& end);


#endif
