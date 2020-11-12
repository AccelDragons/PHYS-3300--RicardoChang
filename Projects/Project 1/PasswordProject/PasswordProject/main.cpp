#include <iostream>
#include <vector>
#include <string>
//#include <bits/stdc++.h>
using namespace std;

//password variable
string password;


// check if its digit or special character.
int c = 0, s = 0;

//Password requirements
static const char alphnum[] = "0123456789" "!¡¿?*\/"  "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";

//Reduces de amount of caracters left to form the password
int strLen = sizeof(alphnum) - 1;

// A utility function to check whether the password the user entered is valid or not  
bool isValid(string password)
{

    // For checking if password length greater than 8
    if ((password.length() <= 7))
    {
        return false;
    }

    if (true)
    {
        int count = 0;

        // Check digits from 0 to 9  
        for (int i = 0; i <= 9; i++)
        {

            // To convert int to string  
            string str1 = to_string(i);

            if (password.find(str1) != std::string::npos)
                count = 1;
        }
        if (count == 0)
        {
            return false;
        }
    }

    // For special characters  
    if (!((password.find("!") != std::string::npos) ||
        (password.find("¡") != std::string::npos) ||
        (password.find("*") != std::string::npos) ||
        (password.find("/") != std::string::npos) ||
        (password.find("\\") != std::string::npos) ||
        (password.find("?") != std::string::npos) ||
        (password.find("¿") != std::string::npos)))
    {
        return false;
    }


    if (true)
    {
        int count = 0;

        // Checking capital letters  
        for (int i = 65; i <= 90; i++)
        {

            // Type casting  
            char c = (char)i;
            string str1(1, c);

            if (password.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
        {
            return false;
        }
    }

    if (true)
    {
        int count = 0;

        // Checking small letters  
        for (int i = 90; i <= 122; i++)
        {

            // Type casting  
            char c = (char)i;
            string str1(1, c);

            if (password.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
        {
            return false;
        }
    }

    //This needs fixing
    //Checks if there is a repeating character next to each other
    if (true)
    {
        int same = 0;

        int n = password.length();
        for (int i = 1; i < n; i++)
            if (password[i] = password[i + 1])
            {
                same++;
            }
        if (same != 0)
            return false;
    }
    
    // If all conditions fails  
    return true;
}

//Returns a character from the array
char GenRand()
{
    return alphnum[rand() % strLen];
}
int opt;

//Generates the password
void Generate()
{
N:
    char C;
    for (int z = 0; z < 8; z++)
    {
        C = GenRand();
        password += C;
        if (isdigit(C))
        {
            c++;
        }
        if (C == '!' || C == '¡' || C == '¿' || C == '?' || C == '\\' || C == '/')
        {
            s++;
        }
    }
    if (8 > 2 && (s == 0 || c == 0))
    {
        goto N;
    }
    cout << password;
}


int main()
{
    cout << "Password Check" << endl;
    cout << "1. Generate Password" << endl;
    cout << "2. Enter Password" << endl;

    cin >> opt;

    switch (opt)
    {
    case 1:
        cout << "Generate password." << endl;
        Generate();
        break;

    case 2:
        cout << "Enter password." << endl;
        cin >> password;
        if (isValid(password))
            cout << "Valid Password" << endl;
        else
            cout << "Invalid Password" << endl;
        break;

    default:
        break;
    }
}