#include <iostream>
using namespace std;
//void ReadNumbers(float &l) {
//    cout << "\n Enter L= " << endl;
//    cin >> l;
//}
//float CalculateCircleAreaAlongTheCircumference(float l) {
//    const float PI = 3.14;
//    float Area = pow(l, 2) / 4 * PI;
//    return Area;
//}
//void PrintResult(float Area) {
//    cout << "\n Area= " << Area << endl;
//}
/**/
int ReadAge() {
    int Age;
    cout << "\n Enter Age: " << endl;
    cin >> Age;
    return Age;
}
bool validateNumberInRange(int Age, int from, int to) {
    return (Age >= from && Age <= to);
}
int ReadUntilAgeBetween(int from, int to) {
    int Age = 0;
    do {
        Age = ReadAge();
    } while (!validateNumberInRange(Age, from, to));
    return Age;
}
void PrintR(int Age) {
     cout << Age << "is a valid age\n";
  
        
}
int main()
{
  
   /* float l;
    ReadNumbers(l);
    PrintResult(CalculateCircleAreaAlongTheCircumference(l));*/
    PrintR(ReadUntilAgeBetween(18, 45));

    return 0;
}
