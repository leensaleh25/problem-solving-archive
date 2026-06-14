#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Readstring() {
    string str;
    cout << "Please Enter a string ?\n";
    getline(cin, str);
    return str;
}
vector<string> Split(string S1, string delim = " ") {
    vector<string> vString;
    
    int Token = 0;
    cout << "\nYour string wrords are: \n\n";
   
    string sWord;
    int pos = 0;
    while ((pos = S1.find(delim)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "")
            vString.push_back(sWord);

        S1.erase(0, pos + delim.length());
    }
    if (S1 != "") {
        vString.push_back(S1);
    }
    return vString;
}

int main()
{
    vector<string> vString;
    string S1 = Readstring();
    vString = Split(S1, " ");
    cout << "token= " << vString.size() << endl;
    for (string& S : vString) {
        cout << S<<endl;
        
    }
}


