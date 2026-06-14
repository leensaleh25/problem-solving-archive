#include <iostream>
#include <string>
using namespace std;

string ReadChar() {
    string str;
    cout << "Please Enter a string ?\n";
    getline(cin, str);
    return str;
}
char InvertLetterCase(char char1) {
    return isupper(char1) ? tolower(char1) : toupper(char1);

}
//string InvertLetterCaseinstring(string str1) {
//
//    for (int i = 0; i <= str1.length(); i++) {
//        str1[i] = InvertLetterCase(str1[i]);
//    }
//    return str1;
//}
int countCapitalLetter(string str1) {
    int Counter1 = 0;

    for (int i = 0; i <= str1.length(); i++) {
        if (isupper(str1[i])) {
            Counter1++;
        }
    } return Counter1;
}
int countSmallLetter(string str1) {
    int Counter = 0;
    for (int i = 0; i <= str1.length(); i++) {
        if (islower(str1[i])) {
            Counter++;
        }
    }
        return Counter;
    
}
int main()
{
    string str1 = ReadChar();
    cout << "capital" << endl;
    cout << countCapitalLetter(str1);
    cout << "\nsmall" << endl;
    cout << countSmallLetter(str1);

}

