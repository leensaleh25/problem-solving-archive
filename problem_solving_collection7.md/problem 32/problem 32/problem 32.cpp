#include <iostream>
#include<string>
using namespace std;

char ReadChar() {
    char c;
    cout << "Please Enter a character ?\n";
    cin >> c;
    return c;
}
bool isVowel(char letter) {
    if (letter == 'a' || (letter == 'o') || (letter == 'i') || (letter == 'u'), (letter == 'e')) {
        return true;
    }
}
int main()
{
    char letter = ReadChar();
    if (isVowel(letter) == true) {
        cout << "\nYES Letter \'" << letter << "\' is vowel";
    }
    else {
        cout << "\nNO Letter \'" << letter << "\' is not vowel";
    }
}


