#include <iostream>
using namespace std;
void ReadNumber(int &m,int &Number) {
    
    cout << "Number:" << endl;
    cin >> Number;
    cout << "enter m:" << endl;
    cin >> m;
}
void PowerOf2_3_4(int Number) {
    int a, b, c;
    a = Number * Number;
    b = Number * Number * Number;
    c = Number * Number * Number * Number;
    cout << a <<" " << b<<" " << c<<" " << endl;
}

int PowerOfM(int m, int Number) {
   
    int power = 1;

    if (power == 0)
        return 1;
    else

      for(int i= 1;i <=m; i++) {
        power*= Number;
      }
    return power;
}
float ReadGrade(int from,int to) {
    float Grade;
    do {
        cout << "Enter your Grade:";
        cin >> Grade;
    } while (from > Grade || to < Grade);
    return Grade;
}
char GetGradeLetter(float Grade) {
    if (Grade >= 90)
        return 'A';
    else if (Grade >= 80)
        return 'B';
    else if (Grade >= 70)
        return 'c';
    else if (Grade >= 60)
        return 'D';
    else if (Grade >= 50)
        return 'E';
    else
        return 'F';

}
  
int main()
{
    cout << "Result=" << GetGradeLetter(ReadGrade(0, 100)) << endl;
    /*int m;
    int Number;
    ReadNumber(m,Number);   PowerOf2_3_4(ReadNumber("Enter number"));
   cout<< PowerOfM(m, Number);*/

}

