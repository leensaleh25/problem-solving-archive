#include <iostream>
#include <string>
using namespace std;

string Readstring() {
    string str;
    cout << "Please Enter a string ?\n";
    getline(cin, str);
    return str;
}
bool IsVowel(char Ch1) {
    Ch1 = tolower(Ch1);
    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

string CountVowels(string S1) {
    string vowels = " ";
    for (int i = 0; i <= S1.length(); i++) {
        if (IsVowel(S1[i])) {
            cout << S1[i] << " ";
        }
    }
    return vowels;
}
int main()
{
    string S1 = Readstring();
    cout << CountVowels(S1);
}



