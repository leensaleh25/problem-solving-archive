#include <iostream>
#include <string>
using namespace std;

// Read and print your name     
string ReadName() {
    string Name;
    cout << "enter your name? " << endl;
    getline(cin, Name);
    return Name;
}
void PrintName(string Name) {
    cout << "\n your name is: " << Name << endl;
    
}

//read number,check if the number even or odd and print     
enum enNmberType{odd=1,even=2};

int ReadNumber() {
    int number;
    cout << "ENTER NUMBER?" << endl;
    cin >> number;
    return number;
}
enNmberType CheckNumberType(int number) {
    int result = number % 2;
    if (result == 0)
        return enNmberType::even;
    else
        return enNmberType::odd;
}
void PrintNumberType(enNmberType NumberType) {
    if (NumberType == ::even)
        cout << "\n NUMBER IS Even.\n";
    else
        cout<< "\n NUMBER IS Odd.\n";

}

//hire a  driver case1  (edit to case2)
struct strInfo {
    int Age;
    bool HasDrivingLicense;
    bool HasRecommendation;
};
strInfo ReadInfo() {
    strInfo info;
    cout << "Enter your age?" << endl;
    cin >> info.Age;
    cout << "Do you have driving license?(1/0)" << endl;
    cin >> info.HasDrivingLicense;
    cout << "do you have recommendation?(0/1)" << endl;
    cin >> info.HasRecommendation;
    return info;
}
bool IsAccepted(strInfo info) {
    return ((info.Age > 21 && info.HasDrivingLicense)||info.HasRecommendation);
}
void PrintResult(strInfo info) {
    if (IsAccepted(info))
        cout << "\n Hired";
    else
        cout << "\n Rejected";
}




int main()
{
   /* PrintName(ReadName());
    int number;
    PrintNumberType(CheckNumberType(ReadNumber()));*/
    PrintResult(ReadInfo());
    return 0;
}
