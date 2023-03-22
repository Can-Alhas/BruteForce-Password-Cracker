#include <iostream>
#include <string.h>
#include <conio.h> // for _getch()
#include <stdlib.h>
#include <chrono> // for timer end-start
#include "Password_Cracker.hpp"

using string = std::string;


int main() {
    auto start = std::chrono::high_resolution_clock::now(); // start time


    string password = getPassword();
    std::cout << "The password you entered: " << password << std::endl;

    string predicted_PSW = "";
    bruteForceLoop(password, predicted_PSW);


    auto end = std::chrono::high_resolution_clock::now(); //end time
    // final print
    printResults(password, predicted_PSW, start, end);

    return 0;
}




string getPassword() {
    char password[30] = "";
    std::cout << "Enter your integer password: ";
    char ch;
    int i = 0;
    while (1) {
        ch = _getch();
        if (ch == 13) {
            password[i] = '\0';
            break;
        }
        else if (ch == 8) {
            if (i > 0) {
                i--;
                std::cout << "\b \b \b";
            }
        }
        else {
            password[i] = ch;
            i++;
            std::cout << "*";
        }
    }
    std::cout << std::endl;
    return password;
}

string randomGeneratePassword(const string& password) {
    char predicted_PSW[30] = "";
    size_t length = password.length();
    for (int i = 0; i < length; i++) {
        predicted_PSW[i] = (char)((rand() % 10) + 48);
    }
    predicted_PSW[length] = '\0';
    return predicted_PSW;
}

void bruteForceLoop(const string& password, string& predicted_PSW)
{
    int attempt = 0;

    while (predicted_PSW != password) {
        std::cout << "attemptNO = " << attempt << " ~~~~~~ PREDICTION -->> " << predicted_PSW << " <<--" << std::endl;
        predicted_PSW = randomGeneratePassword(password);
        attempt++;
    }
}

void printResults(string password, string predicted_PSW, decltype(std::chrono::high_resolution_clock::now()) start, decltype(std::chrono::high_resolution_clock::now()) end)
{
    std::cout << " ***** Your password matched with the prediction *****" << std::endl;
    std::cout << "Your password = " << password << " |||||| Prediction = " << predicted_PSW << std::endl;



    printDuration(start, end);

}

void printDuration(const std::chrono::high_resolution_clock::time_point& start, const std::chrono::high_resolution_clock::time_point& end) {

    auto duration_sec = std::chrono::duration_cast<std::chrono::seconds>(end - start); // Seconds
    auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); // milliseconds
    std::cout << "DURATION --> " << duration_sec.count() << "s," << (duration_ms.count() % 1000) << "ms" << std::endl;
}