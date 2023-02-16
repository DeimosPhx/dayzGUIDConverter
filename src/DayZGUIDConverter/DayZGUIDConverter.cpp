// DayZGUIDConverter.cpp
// @Author DeimosPhx
//

#include <iostream>
#include <string>
#include "sha.h"
#include "filters.h"
#include "base64.h"

using namespace std;

string convertToDayZGUID(string str)
{
    string digest;
    CryptoPP::SHA256 hash;

    CryptoPP::StringSource foo(str, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::Base64Encoder(
                new CryptoPP::StringSink(digest))));

    return digest;
}

int main()
{
    string userID;
    string userDayZGUID;


    //Greetings
    cout << "SteamID64 to DayZ GUID converter." << endl;

    //Request user to input he's SteamID64
    cout << "Entrer votre steamID64: ";
    cin >> userID;
    cout << endl;

    //converting steamID; TODO change parameter to fit input using Crypto++ library
    userDayZGUID = convertToDayZGUID(userID);
    cout << "DayZGUID = " << userDayZGUID;

    system("pause");
}