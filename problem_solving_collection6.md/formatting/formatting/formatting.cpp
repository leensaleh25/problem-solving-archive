#include <iostream>
using namespace std;
int main()
{
    int page = 1, totalpages = 10;
    printf("page %d \n", page);
    printf("page %d ,total %d\n", page, totalpages);
    // width specification 
    printf("page %0*d \n",2, page);
    printf("page %0*d \n",3, page);
    printf("page %0*d \n",4, page);

    int Number1 = 10, Number2 = 20;
    printf("number 1= %d\n number 2 = %d\n the total= %d", Number1, Number2, Number1 +Number2);
    
    float PI =3.1415;
    printf("PI %.*f ", 2, PI);

    double d = 7.0;
    printf("d= %.3f",d);

    char name[] = "leen saleh";
    char SchoolName[] = "programming advices";
    printf("\nhi,how are you %s ", name);
    printf("\nwelcome to %s school", SchoolName);

    char c = 'A';
    cout << endl;
    printf("%*c\n", 1,c);
    printf("%*c\n", 2,c);
    printf("%*c\n", 3,c);


}
