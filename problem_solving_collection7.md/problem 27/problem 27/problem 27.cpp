#include <iostream>
#include <string>
using namespace std;
char  ReadChar() {
    char Ch1;  
    cout << "Please Enter a Character?\n";    
    cin >> Ch1;
    return Ch1; 
}
char InvertLetterCase(char char1) {
    return isupper(char1) ? tolower(char1) : toupper(char1);

}

int main()
{
    char char1 = ReadChar();
    cout<<InvertLetterCase(char1);


}

