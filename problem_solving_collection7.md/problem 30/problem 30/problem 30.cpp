#include <iostream>
#include <string>
using namespace std;

char ReadChar() {
    char c;
    cout << "Please Enter a character ?\n";
    cin >> c;
    return c;
}
string Readstring() {
    string str;
    cout << "Please Enter a string ?\n";
    getline(cin, str);
    return str;
}
int countLetter(string str1, char c) {
    int Counter = 0;

    for (int i = 0; i <= str1.length(); i++) {
        if (str1[i]==c) {
            Counter++;
        }
    } return Counter;
}
int countLetterCapitalOrSmall(string str1, char c,bool matchCase=true) {
    int Counter1 = 0;

    for (int i = 0; i <= str1.length(); i++) {
        if (matchCase){
            if (str1[i] ==c) {
               Counter1++;
            }
        }
        else {
            if (tolower(str1[i]) == tolower(c)) {
                Counter1++;
            }
        }
    } return Counter1;
}
int main()
{
    string str = Readstring();
    char c = ReadChar();
    
    cout << "count"<<c<<"  " << countLetterCapitalOrSmall(str, c) <<endl;

    cout << "count" << countLetterCapitalOrSmall(str, c,false);

}