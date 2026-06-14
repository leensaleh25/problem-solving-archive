#include <iostream>
#include <string>
using namespace std;

string Readstring() {
    string str;
    cout << "Please Enter a string ?\n";
    getline(cin, str);
    return str;
}
void PrintEachWordInString(string S1) {
    cout << "\nYour string wrords are: \n\n";
    string delim = " ";
    string sWord;
    int pos = 0;
    while ((pos = S1.find(delim)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "") 
            cout << sWord << endl;
        
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "") {
        cout << S1 << endl;
    }
    
}
int main()
{
   string S1 = Readstring();
   PrintEachWordInString(S1);
   system("pause>0");
}


