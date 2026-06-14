#include <iostream>
#include <string>
#include <vector>
#include<fstream>
using namespace std;


struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};
sClient ReadNewClient() {
    sClient Client;
    cout << "Enter Account Number? ";
    getline(cin>>ws, Client.AccountNumber);
    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;

}

void AddDataLineToFile(string FileName, string stDataLine) {
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open()) {
        MyFile << stDataLine << endl;
        MyFile.close();
    }
}
void AddNewClient() {
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile("Clients", ConvertRecordToLine(Client));
}
void AddClients() {
    char AddMore = 'Y';
    do {
        system("cls");
        cout << "Adding New Client:\n\n";
        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

vector<string> SplitString(string S1, string Delim) {
    vector <string> vString;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "") {
        vString.push_back(S1);

    }

    return vString;
}

sClient ConvertLinetoRecord(string line, string Seperator = "#//#") {
    sClient Client;
    vector<string>vClientData;
    vClientData = SplitString(line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;

}


vector<sClient> LoadDataFromFile(string FileName) {
    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open()) {
        string Line;
        sClient  Clients;
        while (getline(MyFile, Line)) {
            Clients= ConvertLinetoRecord(Line);
            vClients.push_back(Clients);
        }
    }
    MyFile.close();
    return vClients;
}

vector <sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients) {
    fstream MyFile;  
    string DataLine;
    MyFile.open(FileName, ios::out);
     if (MyFile.is_open())   
     { 
         for (sClient C : vClients)     
         { 
             if (C.MarkForDelete == false)   { 
                   DataLine = ConvertRecordToLine(C); 
                   MyFile << DataLine << endl;          
             }     
         }       
         MyFile.close();   
     } 
     return vClients; 
}
void PrintClientRecord(sClient Client) {
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccout Number  : " << Client.AccountNumber;
    cout << "\nPin Code       : " << Client.PinCode;
    cout << "\nName           : " << Client.Name;
    cout << "\nPhone          : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}
string ReadClientAccountNumber() {
    string AccountNumber = "";   
    cout << "\nPlease enter AccountNumber? ";   
    cin >> AccountNumber;
    return AccountNumber; 
}
bool FindClientByAccountNumber(string AccountNumber, vector<sClient>vClientData, sClient& Client) {
  
    for (sClient  s : vClientData) {
        if (s.AccountNumber == AccountNumber) {
            Client = s;
            return true;
        }
        return false;
    }
   ;

}


bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients) {

    for (sClient & s : vClients) {
        if (s.AccountNumber == AccountNumber) {
            s.MarkForDelete=true;
            return true;
        }
      
    }
    return false;
}
bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) 
    {
        PrintClientRecord(Client);
        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer; 
        if (Answer == 'y' || Answer == 'Y') {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile("Clients", vClients); 
            vClients = LoadDataFromFile("Clients");
            cout << "\n\nClient Deleted Successfully."; 
            return true;
        }
    }
    else { 
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!"; 
        return false;
    }
}

//***********************************************
sClient ChangeClientRecord(string AccountNumber) { 
    sClient Client;   
    Client.AccountNumber = AccountNumber;  
    cout << "\n\nEnter PinCode? ";  
    getline(cin >> ws, Client.PinCode);   
    cout << "Enter Name? ";    
    getline(cin, Client.Name);   
    cout << "Enter Phone? ";    
    getline(cin, Client.Phone); 
    cout << "Enter AccountBalance? ";  
    cin >> Client.AccountBalance; 
    return Client; 
}
bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientRecord(Client);
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {

            for (sClient& C : vClients){
                if (C.AccountNumber == AccountNumber) {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
           
            SaveCleintsDataToFile("Clients", vClients);
            
            cout << "\n\nClient update Successfully.";
            return true;
        }
    }
    else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}
int main()
{
    /*AddClients();*/
    vector <sClient> vClients = LoadDataFromFile("Clients");
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
    system("pause>0");
    return 0;
}