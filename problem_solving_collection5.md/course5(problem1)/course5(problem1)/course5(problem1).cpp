#include <iostream>
using namespace std;

//my solution
void Header() {
	cout << "\t\t\tMultipliaction Table From 1 to 10 \n\n";
	/*cout << "\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n";*/
	for (int i = 1; i <= 10; i++) {
		cout << "\t" << i;
	}
	cout << "\n--------------------------------------------------------------------------------------------\n";
}
string CoiumSperator(int i) {//Abo-hadhoud solution
	if (i < 10)
		return "  |";
	else
		return " |";
}
void PrintMaltiplicationTable() {
	Header();
	for (int i = 1; i <= 10; i++) {
		cout << i << CoiumSperator( i);
		for (int j = 1; j <= 10; j++) {
		  cout<<"\t" << i * j;
		}
        
		cout << "\n";
	}
} 
int main()
{
	PrintMaltiplicationTable();
	
	return 0;
}

