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
   
    for (int i = 0; i < S1.length(); i++) {
        
            S1[i] = toupper(S1[i]);

      
        isFirstChar = (S1[i] == ' ' ? true : false);
    }
    cout << S1;
}
void lowerFirstLetterOfEachWord(string S1) {
    bool isFirstChar = true;

    for (int i = 0; i < S1.length(); i++) {

        S1[i] = tolower(S1[i]);


        isFirstChar = (S1[i] == ' ' ? true : false);
    }
    cout << S1;
}
int main()
{
    string s1;
    s1=ReadString();
    cout << "\nString after upper:\n";  
    UpperFirstLetterOfEachWord(s1);
    cout << "\nString after lower:\n";
    lowerFirstLetterOfEachWord(s1);
    system("pause>0");
    
}


