#include <iostream>
#include <string>
using namespace std;
string ReadChar() {
    string str;
    cout << "Please Enter a string ?\n";
    cin >> str;
    return str;
}
char InvertLetterCase(char char1) {
    return isupper(char1) ? tolower(char1) : toupper(char1);

}
string InvertLetterCaseinstring(string str1) {
  
    for (int i = 0; i <= str1.length(); i++) {
        str1[i]= InvertLetterCase(str1[i]);
    }
    return str1;
}
int main()
{
    string str1 = ReadChar();
    cout << InvertLetterCaseinstring(str1);


}

