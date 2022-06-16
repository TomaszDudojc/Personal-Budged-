#include "AuxiliaryMethods.h"

char AuxiliaryMethods :: loadCharacter()
{
    string enrtrance = "";
    char character  = {0};

    while (true)
    {
        getline(cin, enrtrance);

        if (enrtrance.length() == 1)
        {
            character = enrtrance[0];
            break;
        }
        cout << "This is not a single character. Please retype." << endl;
    }
    return character;
}

string AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string AuxiliaryMethods::loadLine()
{
    string enrtrance = "";
    getline(cin, enrtrance);
    return enrtrance;
}

string AuxiliaryMethods::convertIntegerToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();

    return str;
}
int AuxiliaryMethods::convertStringToInteger(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AuxiliaryMethods::convertFloatToString(float amount)
{
    std::stringstream FloatToStr;
    std::string str;

    FloatToStr << amount;
    FloatToStr >> str;
    FloatToStr.clear();

    return str;
}

float AuxiliaryMethods::convertStringToFloat(string str)
{
    float num_float = std::stof(str);

    return num_float;
}
/*
float AuxiliaryMethods::loadFloat()
{
    string entrance = "";
    float number;

    while (true)
    {
        cin.clear();
        getline(cin, entrance);

        stringstream myStream(entrance);
        if (myStream >> number)
            break;
        cout << "This is not the amount. Please retype." << endl;
    }
    return number;
}
*/
string AuxiliaryMethods::replaceCommaWithDot(string text)
{
    for (int i=0; i<text.size(); i++)
    {
        if (text[i]==',')
        {
            text[i]='.';
        }
    }
    return text;
}


