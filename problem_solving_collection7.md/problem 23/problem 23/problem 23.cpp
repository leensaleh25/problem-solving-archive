#include <iostream>
#include<string>
using namespace std;
string ReadString() {
    string s1;
    cout << "enter your String\n";
    getline(cin, s1);
    return s1;
}
void UpperFirstLetterOfEachWord(string S1) {
    bool isFirstChar = true;
    cout << "\nFirst letters of this string: \n";
    for (int i=0;i<=S1.length();i++){
       if (S1[i] != ' ' && isFirstChar) {
          cout << S1[i];
       }
       isFirstChar = (S1[i] == ' ' ? true : false);
}
}
int main()
{
    UpperFirstLetterOfEachWord(ReadString());
}


