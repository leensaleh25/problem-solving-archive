#include <iostream>
#include <string>
using namespace std;

string password() {
    string Password;
	cout << "Enter yor password:\n";
	cin >> Password;
	return Password;
}
bool PrintFromAtoZ() {
    string UserPassword = password();
    string word = "";
    int Count = 0;
    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            for (int x = 65; x <= 90; x++) {

                word = word + char(i);
                word = word + char(j);
                word = word + char(x);

                Count++;
                cout << "Tial" << "[" << Count << "]" << word << endl;

                if (word == UserPassword) {
                    cout << "Password is:" << word;
                    return true;
                } word = "";
            }
        }
    }return false;
    
}

int main()
{
  
    PrintFromAtoZ();
}


