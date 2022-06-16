#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class AuxiliaryMethods
{
public:
    static char loadCharacter();
    static string changeFirstLetterForUpperCaseAndOthersForLowerCase(string text);
    static string loadLine();
    static string convertIntegerToString(int number);
    static int convertStringToInteger(string number);
    static string convertFloatToString(float amount);
    //static float loadFloat();
    static float convertStringToFloat(string str);
    static string replaceCommaWithDot(string text);
};

#endif
