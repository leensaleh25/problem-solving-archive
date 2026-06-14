#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";


struct stClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

void LoadDataFromFileToVector(string FileName, vector<string>& vFile) {

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {
		string Line;
		while (getline(MyFile, Line)) {
			vFile.push_back(Line);
		}
	}
	MyFile.close();
}

vector <string>spliteString(string s1, string Delim) {

	short pos = 0;
	string sWord;
	vector<string>vString;

	while ((pos = s1.find(Delim)) != std::string::npos){
		sWord = s1.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		s1.erase(0, pos + Delim.length());
	}
	if (s1 != "") {
		vString.push_back(s1);
	}
	return vString;
}

stClient ConvertLineToRecord(string Line, string Seporter = "#//#") {
	vector<string>vClientData = spliteString(Line, Seporter);
	stClient Client;

	if (vClientData.size() != 5) {
	
		return Client;
	}

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);

	return Client;
}
vector<stClient> DataClient(vector<string>& vFile) {
	vector<stClient> FillClient;

	for (int i = 0; i < vFile.size(); i++) {
		string Line = vFile[i];
		stClient Client = ConvertLineToRecord(Line, "#//#");

		if (Client.AccountNumber != "") {
			FillClient.push_back(Client);
		}
	}

	return FillClient;
}


void PrintRecord(vector<string>& vFile) {

	vector<stClient> Client = DataClient(vFile);

	for (int i = 0; i < Client.size(); i++) {

		cout << "| " << setw(14) << Client[i].AccountNumber
			<< "| " << setw(15) << Client[i].PinCode
			<< "| " << setw(35) << Client[i].Name
			<< "| " << setw(12) << Client[i].Phone
			<< "| " << setw(10) << Client[i].AccountBalance << endl;
	}

}

void PrintAll(vector<string>& vFile) {


	vector<stClient> Client = DataClient(vFile);

	cout << left << setw(40) << " " << "Client List (" << Client.size() << ") Clients(s)" << setw(40) << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	cout << "| " << setw(14) << "AccountNumber"
		<< "| " << setw(15) << "PinCode"
		<< "| " << setw(35) << "Name"
		<< "| " << setw(12) << "Phone"
		<< "| " << setw(10) << "AccountBalance" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	PrintRecord(vFile);
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";

}

int main() {

	vector<string> vFile;
	LoadDataFromFileToVector(ClientsFileName, vFile);
	PrintAll(vFile);

	system("pause>0");

	return 0;
}