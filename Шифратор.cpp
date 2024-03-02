#include <iostream>
#include <string>

using namespace std;


string encrypt(const string& str, const string& pattern)
{
    string encrypted = "";
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        char p = pattern[i % pattern.length()];
        switch (p)
        {
        case 'N':
            encrypted += c;
            break;
        case 'R':
            encrypted += to_string(int(c));
            break;
        case 'S':
            break;
        case 'D':
            encrypted += string(2, c);
            break;
        }
    }
    return encrypted;
}

string decrypt(const string& encrypted, const string& pattern)
{
    string decrypted = "";
    int i = 0, j = 0;
    while (i < encrypted.length())
    {
        if (j >= pattern.length())
        {
            j = 0;
        }
        char p = pattern[j];
        switch (p)
        {
        case 'N':
            decrypted += encrypted[i];
            i++;
            break;
        case 'R': 
        {
            int ascii = stoi(encrypted.substr(i, 4));
            decrypted += char(ascii);
            i += 4;
            break;
        }
        case 'S':
            i++;
            break;
        case 'D':
            decrypted += encrypted[i];
            i++;
            break;
        }
        j++;
    }
    return decrypted;
}
int main()
{
    setlocale(LC_ALL, "ru");
    string str;
    cout << "Введите фразу: ";
    getline(cin, str);
    string pattern = "NSDR";
    string encrypted = encrypt(str, pattern);
    string decrypted = decrypt(encrypted, pattern);
    cout << "Шифрованно: " << encrypted << endl;
    cout << "Дешифрованно: " << decrypted << endl;
    return 0;
}
