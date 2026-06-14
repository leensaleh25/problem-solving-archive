#include <iostream>
#include<string>
using namespace std;

struct strInfo {
    string FirstName;
    string LastName;
};
strInfo ReadInfo() {
    strInfo user;
    cout << "Enter your first name?\n";
    cin >> user.FirstName;
    cout << "Enter your last name?\n";
    cin >> user.LastName;
    return user;
}
string GetFullName(strInfo user, bool reversed){
     string FullName="";
     if (reversed)
       FullName = user.LastName + " " + user.FirstName;
     else
         FullName = user.FirstName + " " + user.LastName;
     return FullName;

}
void PrintFullName(string FullName){

    cout << "\n your full name is: " << FullName;
}
//half number
int ReadNumber() {
    int number;
    cout << "ENTER NUMBER?" << endl;
    cin >> number;
    return number;
}
float CalculateHalfNumber(int number) {
    return float(number)/2;
        
}
void PrintResult(int number) {
    string result = "Half of " + to_string(number) + "  is : " + to_string(CalculateHalfNumber(number));
    cout << "\t"<<result << endl;
}
//pass or fail mark
enum enPassFail{pass=1,fail=0};
int ReadMarkes(){
     int mark;
    cout << "Enter your mark?";
    cin >> mark;
    return mark;
}
enPassFail CheckMark(int mark) {
    if (mark >= 50)
        return enPassFail::pass;
    else
        return enPassFail::fail;
}
void PrintResult0(int mark){
    if (CheckMark(mark) == enPassFail::pass)
        cout << "\n you passed" << endl;
    else
        cout << "\n you Faild" << endl;

}
//9-10
void Readnum(int& num1, int& num2, int &num3) {
    cout << "Please enter number: \n";
    cin >> num1;
    cout << "Please enter number: \n";
    cin >> num2;
    cout << "Please enter number: \n";
    cin >> num3;
}
int SumOf3Numbers(int num1,int  num2,int num3) {
    return num1 + num2 + num3;
}
float CalculateAvarage(int num1, int  num2, int num3) {
    return (float)SumOf3Numbers(num1, num2, num3) / 3;
}
enPassFail checkAvarage(float avarege) {
    if (avarege >= 50)
        return enPassFail::pass;
    else
        return enPassFail::fail;
}
void PrintResult2(float avarage) {
    cout << "sum of 3 numbers is: " << avarage<< endl;
    if (checkAvarage(avarage) == enPassFail::pass)
        cout << "you passed! \n";
    else
        cout << "you failed!\n";
}

int main()

{
    
    /*PrintFullName(GetFullName(ReadInfo(),true));
    PrintResult(ReadNumber());
    PrintResult0(ReadMarkes());*/
    int num1, num2, num3;
    Readnum(num1, num2, num3);
    PrintResult2(CalculateAvarage(num1, num2, num3));

    return 0;
}


