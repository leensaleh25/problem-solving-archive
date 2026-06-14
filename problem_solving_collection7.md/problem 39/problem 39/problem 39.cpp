#include<string>
#include<iostream>
#include<vector>
using namespace std;
string JoinString(vector<string> vString, string Delim) {
    string s1 = " ";
    for (string& s : vString) {
       s1= s1 + s + Delim;

    }
    return s1.substr(0, s1.length() - Delim.length());
}
string JoinString(string arrstring[],short length, string Delim) {
    string s1 = " ";
    for (int i = 0; i < length; i++) {
        s1 = s1 + arrstring[i] + Delim;
        
    }
    return s1.substr(0, s1.length() - Delim.length());
}
int main()
{

    vector<string> vString = { "Mohammed","Faid","Ali","Maher" };   
    string arrstring[] = {"Mohammed","Faid","Ali","Maher"};
    cout << "\nVector after join: \n";  
    cout << JoinString(vString, " ");  
    cout << "\nVector after join: \n";
    cout << JoinString(arrstring,4," ");
    system("pause>0");
}


