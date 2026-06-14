
#include <iostream>
#include <string>
using namespace std;
void Pattern() {
    string word = "";
    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            for (int x = 65; x <= 90; x++) {
               /* word.append(1, char(i));
                word.append(1, char(j));
                word.append(1, char(x));
                cout << word<<endl;*/
                word = word + char(i);
                word = word + char(j);
                word = word + char(x);

                cout << word<<endl;
                word = "";
            }
            
        }
    }
}
int main()
{
    Pattern();
}

