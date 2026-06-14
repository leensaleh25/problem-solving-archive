#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
    //int Array[3][4] = {
    //    {1,2,3,4},
    //    {5,6,7,8},
    //    {9,10,11,12}
    //};
   /* for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << Array[i][j] << " ";
        }
        cout << endl;
    }*/

    //int Array[10][10];
    //for (int i = 0; i < 10; i++) {
    //    for (int j = 0; j <10; j++) {
    //        Array[i][j] = (i+1) *(j+1);
    //    }
    //}

    //for (int i = 0; i < 10; i++) {
    //    for (int j = 1; j < 10; j++) {
    //        printf("%0d", 2, Array[i][j]);
    //    }

    //    cout << endl;
    //}
    int Array[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            Array[i][j] = (i + 1) * (j + 1);
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%0*d  ",2, Array[i][j]); 
        }
        cout << endl;
    }

}

