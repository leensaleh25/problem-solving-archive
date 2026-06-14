#include <iostream>
#include <string>
#include <vector>
#include<iomanip>
#include<fstream>
using namespace std;
const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";
enum enMainMenueOptions { eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5,  eTransactions=6, eManageUsers=7,eLogout = 8 };
enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eTotalBalances = 3};
enum enManageUsers { eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenue=6 };
enum enMainMenuePermissions{eAll = -1, pListUsers = 1, pAddNewUsers = 2, pDeleteUsers= 4,pUpdateUsers = 8, pFindUsers = 16, pTranactions = 32,pManageUsers = 64};
void ShowMainMenue();
void ShowTransactionsMenue();
void ShowManageUsersMenue();
void ShowAccessDeniedMessage()
{
	cout << "\n------------------------------------\n";
	cout << "Access Denied, \nYou dont Have Permission To Do this, \nPlease Conact Your Admin.";
	cout << "\n------------------------------------\n";
}
struct sClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};
struct sUser {
	string UserName;
	string PassWord;
	int Permissions;
	bool MarkForDelete = false;
};
sUser CurrentUser;




bool CheckAccessPermission(enMainMenuePermissions Permission)
{
	if (CurrentUser.Permissions == eAll)
		return true;
}


sClient ReadNewClient() {
	sClient Client;
	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);
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
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
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
void ShowAddNewClientsScreen() {
	if
		(!CheckAccessPermission(enMainMenuePermissions::pUpdateUsers))
	{
		ShowAccessDeniedMessage();
		return;
	}
	cout << "\n-----------------------------------\n";    
	cout << "\tAdd New Clients Screen";   
	cout << "\n-----------------------------------\n";   
	AddClients();
	
}

vector <string>spliteString(string s1, string Delim) {

	short pos = 0;
	string sWord;
	vector<string>vString;

	while ((pos = s1.find(Delim)) != std::string::npos) {
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

sClient ConvertClientsLineToRecord(string Line, string Seporter = "#//#") {
	vector<string>vClientData = spliteString(Line, Seporter);
	sClient Client;

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
sUser ConvertUserLinetoRecord(string Line, string Seperator ="#//#")
{
	sUser User;
	vector<string> vUserData = spliteString(Line, "#//#");

	if (vUserData.size() < 3)
		return User;

	User.UserName = vUserData[0];
	User.PassWord = vUserData[1];
	User.Permissions = stoi(vUserData[2]);
	return User;
}
//sUser ConvertUserLinetoRecord(string Line, string Seperator =
//	"#//#")
//{
//	sUser User;
//	vector<string> vUserData;
//	vUserData = spliteString(Line, "#//#");
//	User.UserName = vUserData[0];
//	User.PassWord = vUserData[1];
//	User.Permissions = stoi(vUserData[2]);
//	return User;
//}

string ConvertUserRecordToLine(sUser User, string Seperator =
	"#//#")
{
	string stClientRecord = "";
	stClientRecord += User.UserName + Seperator;
	stClientRecord += User.PassWord + Seperator;
	stClientRecord += to_string(User.Permissions);
	return stClientRecord;
}
vector<sClient> DataClient(vector<string>& vFile) {
	vector<sClient> FillClient;

	for (int i = 0; i < vFile.size(); i++) {
		string Line = vFile[i];
		sClient Client = ConvertClientsLineToRecord(Line, "#//#");

		if (Client.AccountNumber != "") {
			FillClient.push_back(Client);
		}
	}

	return FillClient;
}
void PrintRecord(vector<string>& vFile) {

	vector<sClient> Client = DataClient(vFile);

	for (int i = 0; i < Client.size(); i++) {

		cout << "| " << setw(14) << Client[i].AccountNumber
			<< "| " << setw(15) << Client[i].PinCode
			<< "| " << setw(35) << Client[i].Name
			<< "| " << setw(12) << Client[i].Phone
			<< "| " << setw(10) << Client[i].AccountBalance << endl;
	}

}
vector<sClient> LoadDataFromFile(string FileName) {
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		string Line;
		sClient  Clients;
		while (getline(MyFile, Line)) {
			Clients = ConvertClientsLineToRecord(Line);
			vClients.push_back(Clients);
		}
	}
	MyFile.close();
	return vClients;
}
vector<sUser> LoadUserDataFromFile(string FileName) {
	vector <sUser> vUsers;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		string Line;
		sUser  User;
		while (getline(MyFile, Line)) {
			User= ConvertUserLinetoRecord(Line);
			vUsers.push_back(User);
		}
	}
	MyFile.close();
	return vUsers;
}
void PrintClientRecordLine(vector <sClient> Client) {
	for (int i = 0; i < Client.size(); i++) {

		cout << "| " << setw(14) << Client[i].AccountNumber
			<< "| " << setw(15) << Client[i].PinCode
			<< "| " << setw(35) << Client[i].Name
			<< "| " << setw(12) << Client[i].Phone
			<< "| " << setw(10) << Client[i].AccountBalance << endl;
	}
}
void PrintClientRecord(vector <sClient> Client) {
	cout << "\t\t\t\t\n-----------------------------------\n";
	 Client = LoadDataFromFile(ClientsFileName);
	cout << left << setw(40) << " " << "Client List (" << Client.size() << ") Clients(s)" << setw(40) << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	cout << "| " << setw(14) << "AccountNumber"
		<< "| " << setw(15) << "PinCode"
		<< "| " << setw(35) << "Name"
		<< "| " << setw(12) << "Phone"
		<< "| " << setw(10) << "AccountBalance" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	if (Client.size() == 0) {
		cout << "\t\t\t\tNo Clients Available In the System!";
	}
	else {

		PrintClientRecordLine(Client);
		cout << endl;

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
}
void ShowAllClientsScreen() {
	if
		(!CheckAccessPermission(enMainMenuePermissions::pListUsers))
	{
		ShowAccessDeniedMessage();
		return;
	}
	cout << "\t\t\t\t\n-----------------------------------\n";
	cout << "\t\t\t\t\tShow Clients Screen";
	cout << "\t\t\t\t\n-----------------------------------\n";
	vector <sClient> Client = LoadDataFromFile(ClientsFileName);
	PrintClientRecord( Client);

}
string ReadClientAccountNumber() {
	string AccountNumber = "";
	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;
}
void PrintClientCard(sClient Client) {
	
	cout << "\nThe following are the client details:\n";
	cout << "-----------------------------------";  
	cout << "\nAccout Number: " << Client.AccountNumber; 
	cout << "\nPin Code     : " << Client.PinCode;  
	cout << "\nName         : " << Client.Name; 
	cout << "\nPhone        : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance; 
	cout << "\n-----------------------------------\n";
}
bool FindClientByAccountNumber(string AccountNumber, vector<sClient>vClientData, sClient& Client) {
	for (sClient s : vClientData) {
		if (s.AccountNumber == AccountNumber) {
			Client = s;
			return true;
		}
	}
		return false;
	
}
void FindClientsScreen() {
	if
		(!CheckAccessPermission(enMainMenuePermissions::pFindUsers))
	{
		ShowAccessDeniedMessage();
		return;
	}
	cout << "\n-----------------------------------\n";  
	cout << "\tFind Client Screen";     
	cout << "\n-----------------------------------\n";
	vector <sClient> vClients = LoadDataFromFile(ClientsFileName);
	sClient Client;
	string AccountNumber = ReadClientAccountNumber(); 
	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
		PrintClientCard(Client);
	else    
		cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";

}
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients) {

	for (sClient& s : vClients) {
		if (s.AccountNumber == AccountNumber) {
			s.MarkForDelete = true;
			return true;
		}

	}
	return false;
}
vector <sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients) {
	fstream MyFile;
	string DataLine;
	MyFile.open(FileName, ios::out);
	if (MyFile.is_open())
	{
		for (sClient C : vClients)
		{
			if (C.MarkForDelete == false) {
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vClients;
}
bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
	sClient Client;
	char Answer = 'n';
	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientRecord(vClients);
		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveCleintsDataToFile(ClientsFileName, vClients);
			vClients = LoadDataFromFile(ClientsFileName);
			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else {
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}
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
		PrintClientRecord(vClients);
		cout << "\n\nAre you sure you want update this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {

			for (sClient& C : vClients) {
				if (C.AccountNumber == AccountNumber) {
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}

			SaveCleintsDataToFile(ClientsFileName, vClients);

			cout << "\n\nClient update Successfully.";
			return true;
		}
	}
	else {
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}
void UpdateClientsScreen() {
	if
		(!CheckAccessPermission(enMainMenuePermissions::pUpdateUsers))
	{
		ShowAccessDeniedMessage();
		return;
	}
	cout << "\t\t\t\t-----------------------------------\n";
	cout << "\t\t\t\t\tUpdate Clients Screen\n";
	cout << "\t\t\t\t-----------------------------------\n";
	vector <sClient> vClients = LoadDataFromFile(ClientsFileName);
	UpdateClientByAccountNumber(ReadClientAccountNumber(), vClients);
}
void DeleteClientsScreen() {
	if
		(!CheckAccessPermission(enMainMenuePermissions::pDeleteUsers))
	{
		ShowAccessDeniedMessage();
		return;
	}
	cout << "\t\t\t\t-----------------------------------\n";
	cout << "\t\t\t\t\tDelete Clients Screen\n";
	cout << "\t\t\t\t-----------------------------------\n";
	vector <sClient> vClients = LoadDataFromFile(ClientsFileName);
	DeleteClientByAccountNumber(ReadClientAccountNumber(), vClients);
}
short ReadMainMenueOption() {
	cout << "Choose what do you want to do? [1 to 7]? ";
	short Choice = 0;
	cin >> Choice;
	return Choice;
}


void ShowEndScreen() {
	cout << "\n-----------------------------------\n"; 
	cout << "\tProgram Ends :-)";  
	cout << "\n-----------------------------------\n";
}
void ShowDepositScreen() {
	cout << "\t\t\t\t-----------------------------------\n";
	cout << "\t\t\t\t\t Deposit Screen\n";
	cout << "\t\t\t\t-----------------------------------\n";
	char UserChoice;
	int depositAmount;
	vector <sClient> vClients = LoadDataFromFile(ClientsFileName);
	sClient Client;
	string AccountNumber = ReadClientAccountNumber();
	if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
       PrintClientCard(Client);
	   cout << "Please enter deposit amount? \n\n";
	   cin >> depositAmount;
	   cout << "Are you sure you want perform this transaction [Y/N]?";
	   cin >> UserChoice;
	   if (UserChoice == 'Y' || UserChoice == 'y') {
		   for (sClient& C : vClients) { 
			   if (C.AccountNumber == AccountNumber) { 
				   C.AccountBalance += depositAmount;
				   SaveCleintsDataToFile(ClientsFileName, vClients);      
				   cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;    
			   } 
		   } 
	   }	   
	  
	}
	else {
		cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
		
	}			   
}
void ShowWithdrawScreen() {
	cout << "\t\t\t\t-----------------------------------\n";
	cout << "\t\t\t\t\t Withdraw Screen\n";
	cout << "\t\t\t\t-----------------------------------\n";
	char UserChoice;
	int Withdraw;
	vector <sClient> vClients = LoadDataFromFile(ClientsFileName);
	sClient Client;
	string AccountNumber = ReadClientAccountNumber();
	if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
		PrintClientCard(Client);
		cout << "Please enter Withdraw amount? \n\n";
		cin >> Withdraw;
		if (Client.AccountBalance< Withdraw){
			cout << "Amount Exceeds the balance,you canwithdraw up to: " << Client.AccountBalance<<endl;
			cout << "Please enter Withdraw amount? \n\n";
			cin >> Withdraw;
		}
		else {
			cout << "\nAre you sure you want perform this transaction [Y/N]?";
			cin >> UserChoice;
			if (UserChoice == 'Y' || UserChoice == 'y') {
				for (sClient& C : vClients) {
					if (C.AccountNumber == AccountNumber) {
						C.AccountBalance -= Withdraw;
						SaveCleintsDataToFile(ClientsFileName, vClients);
						cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;
					}
				}
			}
		}
	}
	else {
		cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
	}
}
void ShowTotalBalancesScreen() {
	vector <sClient> vClients = LoadDataFromFile(ClientsFileName);
	sClient Client;
	float TotalBalances = 0;
	for (sClient& C : vClients) {
		TotalBalances += C.AccountBalance;
	}
	PrintClientRecord(vClients);
	cout << "\t\t\t\t\tTotal Balances= " << TotalBalances;

}
short ReadManageMenueOption() {
	cout << "Choose what do you want to do? [1 to 6]? ";
	short Choice = 0;
	cin >> Choice;
	return Choice;
}
void PrintUsersRecordLine(vector <sUser> User) {
	for (int i = 0; i < User.size(); i++) {

		cout << "| " << setw(14) << User[i].UserName
			<< "| " << setw(15) << User[i].PassWord
			<< "| " << setw(15) << User[i].Permissions <<endl;

	}
}


void PrintUsersRecord(vector <sUser> User) {
	cout << "\t\t\t\t\n-----------------------------------\n";
	User = LoadUserDataFromFile(UsersFileName);
	cout << left << setw(40) << " " << "Users List (" << User.size() << ") Users(s)" << setw(40) << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	cout << "| " << setw(14) << "UserName"
		<< "| " << setw(15) << "Password" << "| "
		<< setw(40) << "Permissions" <<endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	if (User.size() == 0) {
		cout << "\t\t\t\tNo Usres Available In the System!";
	}
	else {

		PrintUsersRecordLine(User);
		cout << endl;

		cout << "-----------------------------------------------------------------------------------------------------------------------\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	}
}
void PrintUserRecordLine(sUser User)
{
        cout << "\nThe following are the user details:\n";
		cout << "-----------------------------------";
		cout << "\nUsername : " << User.UserName;
		cout << "\nPassword : " << User.PassWord;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n-----------------------------------\n";
	
}
void ShowListUsers() 
{
	if
		(!CheckAccessPermission(enMainMenuePermissions::pListUsers))
	{
		ShowAccessDeniedMessage();
		ShowMainMenue();
		return;
	}
	vector <sUser> vUsers = LoadUserDataFromFile(UsersFileName);
	cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s).";
		cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "User Name";
	cout << "| " << left << setw(10) << "Password";
	cout << "| " << left << setw(40) << "Permissions";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	if (vUsers.size() == 0)
		cout << "\t\t\t\tNo Users Available In the System!";
	else
		for (sUser User : vUsers)
		{
			PrintUserRecordLine(User);
			cout << endl;
		}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

//void AddUserScreen() {
//	if
//		(!CheckAccessPermission(enMainMenuePermissions::pAddNewUsers))
//	{
//		ShowAccessDeniedMessage();
//		ShowMainMenue();
//		return;
//	}
//	cout << "\n-----------------------------------\n";
//	cout << "\tAdd New User Screen";
//	cout << "\n-----------------------------------\n";
//}
int ReadPermissionsToSet()
{
	if (CurrentUser.Permissions != enMainMenuePermissions::eAll)
	{
		cout << "\nOnly Admin can set permissions.\n";
		return 0; 
	}
	int Permissions = 0;
	char Answer = 'n';
	cout << "\nDo you want to give full access? y/n? ";
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y')
	{
		return -1;
	}
	cout << "\nDo you want to give access to : \n ";
	cout << "\nShow Client List? y/n? ";
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += enMainMenuePermissions::pListUsers;
	}
	cout << "\nAdd New Client? y/n? ";
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += enMainMenuePermissions::pAddNewUsers;
	}
	cout << "\nDelete Client? y/n? ";
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += enMainMenuePermissions::pDeleteUsers;
	}
	cout << "\nUpdate Client? y/n? ";
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += enMainMenuePermissions::pUpdateUsers;
	}
	cout << "\nFind Client? y/n? ";
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += enMainMenuePermissions::pFindUsers;
	}
	cout << "\nTransactions? y/n? ";
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += enMainMenuePermissions::pTranactions;
	}
	cout << "\nManage Users? y/n? ";
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += enMainMenuePermissions::pManageUsers;
	}
	return Permissions;
}
bool UserExistsByUsername(string Username, string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read Mode
	if (MyFile.is_open())
	{
		string Line;
		sUser User;
		while (getline(MyFile, Line))
		{
			User = ConvertUserLinetoRecord(Line);
			if (User.UserName == Username)
			{
				MyFile.close();
				return true;
			}
		}
		MyFile.close();
	}
	return false;
}
sUser ReadNewUser()
{
	sUser User;
	cout << "Enter Username? ";
	getline(cin >> ws, User.UserName);
	while (UserExistsByUsername(User.UserName, UsersFileName))
	{
		cout << "\nUser with [" << User.UserName << "] alreadyexists, Enter another Username ? ";
			getline(cin >> ws, User.UserName);
	}
	cout << "Enter Password? ";
	getline(cin, User.PassWord);
	User.Permissions = ReadPermissionsToSet();
	return User;
}

string ConvertUsersRecordToLine(sUser User, string Seperator = "#//#") {
	string stUsersRecord = "";
	stUsersRecord += User.UserName + Seperator;
	stUsersRecord += User.PassWord + Seperator;
	stUsersRecord += to_string(User.Permissions);
	return stUsersRecord;
}
void AddNewUser() {


	sUser User;
	User = ReadNewUser();
	AddDataLineToFile(UsersFileName, ConvertUsersRecordToLine(User));
}

void AddUser() {
	if
		(!CheckAccessPermission(enMainMenuePermissions::pAddNewUsers))
	{
		ShowAccessDeniedMessage();
		ShowMainMenue();
		return;
	}
	else {
		cout << "\n-----------------------------------\n";
		cout << "\tAdd New User Screen";
		cout << "\n-----------------------------------\n";
		char AddMore;

		cout << "Do you want to add a new user? Y/N? ";
		cin >> AddMore;

		do {
			system("cls");
			cout << "Adding New User:\n\n";
			AddNewUser();

			cout << "\nUser Added Successfully, do you want to add more Users? Y/N? ";
			cin >> AddMore;

		} while (toupper(AddMore) == 'Y');
	}
}

bool MarkUserForDelete(string Username, vector <sUser>& vUser) {

	for (sUser& s : vUser) {
		if (s.UserName ==Username) {
			s.MarkForDelete = true;
			return true;
		}

	}
	return false;
}
string ReadUesrInfo(string Message) {
	string  Info;
	cout << Message << endl;
	getline(cin >> ws, Info);
	return Info;
}


bool FindUserByUsernameAndPassword(string Username, string
	Password,  sUser& User)
{
	vector <sUser> vUsers = LoadUserDataFromFile(UsersFileName);
	for (sUser U : vUsers)
	{
		if (U.UserName == Username && U.PassWord == Password)
		{
			User = U;
			return true;
		}
	}
	return false;
}

bool DataIsValid(string UsernameData, string UserPassword) {
	return FindUserByUsernameAndPassword(UsernameData, UserPassword, CurrentUser);
}

vector <sUser> SaveUsersDataToFile(string FileName, vector<sUser> vUser) {
	fstream MyFile;
	string DataLine;
	MyFile.open(FileName, ios::out);
	if (MyFile.is_open())
	{
		for (sUser C : vUser)
		{
			if (C.MarkForDelete == false) {
				DataLine = ConvertUsersRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vUser;
}

bool DeleteUser(string UserName,string UserPassword, vector<sUser>& vUser) {
	sUser User;
	char Answer = 'n';
	if (UserName == "Admin") {
		cout << "\nYou can not Delete Admin\n";
	}
	else if (FindUserByUsernameAndPassword(UserName, UserPassword, User))
	{
		PrintUserRecordLine(User);
		cout << "\n\nAre you sure you want delete this user? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			MarkUserForDelete(UserName, vUser);
			SaveUsersDataToFile(UsersFileName, vUser);
			vUser = LoadUserDataFromFile(UsersFileName);
			cout << "\n\nUser Deleted Successfully.";
			return true;
		}
	}
	else {
		cout << "\nUser (" <<UserName << ") is Not Found!";
		return false;
	}
}
void DeleteUserssScreen() {
	if
		(!CheckAccessPermission(enMainMenuePermissions::pDeleteUsers))
	{
		ShowAccessDeniedMessage();
		ShowMainMenue();
		return;
	}
	cout << "\t\t\t\t-----------------------------------\n";
	cout << "\t\t\t\t\tDelete Users Screen\n";
	cout << "\t\t\t\t-----------------------------------\n";
	vector <sUser> vUser = LoadUserDataFromFile(UsersFileName);
	sUser User;
	User.UserName = ReadUesrInfo("Username: ");
	User.PassWord = ReadUesrInfo("Password: ");
	DeleteUser(User.UserName, User.PassWord,vUser);
}
sUser ChangeUserRecord(string Username) {
	sUser User;
	User.UserName = Username;
	cout << "\n\nEnter Password? ";
	getline(cin >> ws, User.PassWord);
	User.Permissions = ReadPermissionsToSet();
	return User;
}
bool UpdateUsersByUsername(string Username, string  UserPassword, vector<sUser>& vUser) {
	sUser User;
	char Answer = 'n';
	if (FindUserByUsernameAndPassword(Username, UserPassword,  User))
	{
		PrintUserRecordLine(User);
		cout << "\n\nAre you sure you want update this User? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {

			for (sUser& C : vUser) {
				if (C.UserName== Username) {
					C = ChangeUserRecord( Username);
					break;
				}
			}

			SaveUsersDataToFile(UsersFileName, vUser);

			cout << "\n\nUser update Successfully.";
			return true;
		}
	}
	else {
		cout << "\nUser with Username (" << Username << ") is Not Found!";
		return false;
	}
}
void UpdateUsersScreen() {
	if
		(!CheckAccessPermission(enMainMenuePermissions::pUpdateUsers))
	{
		ShowAccessDeniedMessage();
		ShowMainMenue();
		return;
	}
	cout << "\t\t\t\t-----------------------------------\n";
	cout << "\t\t\t\t\tUpdate Users Screen\n";
	cout << "\t\t\t\t-----------------------------------\n";
	vector <sUser> vUser = LoadUserDataFromFile(UsersFileName);
	sUser User;
	User.UserName = ReadUesrInfo("Username: ");
	User.PassWord = ReadUesrInfo("Password: ");
	UpdateUsersByUsername(User.UserName, User.PassWord, vUser);
}
void FindUsersScreen() {
	if
		(!CheckAccessPermission(enMainMenuePermissions::pListUsers))
	{
		ShowAccessDeniedMessage();
		ShowMainMenue();
		return;
	}

	cout << "\n-----------------------------------\n";
	cout << "\tFind User Screen";
	cout << "\n-----------------------------------\n";
	vector <sUser> vUser = LoadUserDataFromFile(UsersFileName);
	sUser User;
	User.UserName = ReadUesrInfo("Username: ");
	User.PassWord = ReadUesrInfo("Password: ");
	if (FindUserByUsernameAndPassword(User.UserName, User.PassWord, User))
		PrintUserRecordLine(User);
	else
		cout << "\nUser with Username[" << User.UserName << "] is not found!";

}

void PerfromManageMenueOption(enManageUsers ManageUsers) {
	switch (ManageUsers)
	{
	case eListUsers:
		system("cls");
		ShowListUsers();
		break;
	case eAddNewUser:
		
		AddUser();
		break;
	case eDeleteUser:
		DeleteUserssScreen();
		break;
	case eUpdateUser:
		UpdateUsersScreen();
		break;
	case eFindUser:
		FindUsersScreen();
		break;
	case eMainMenue:
		ShowMainMenue();
		break;
	default:
		break;
	}
}
void ManageUsersMenueScreen() {
	if
		(!CheckAccessPermission(enMainMenuePermissions::pManageUsers))
	{
		ShowAccessDeniedMessage();
		ShowMainMenue();
		return;
	}
	cout << "===========================================\n";
	cout << "\t\ Manage Users Menue Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] List Users.\n";
	cout << "\t[2] Add New User.\n";
	cout << "\t[3] Delete User.\n";
	cout << "\t[4] Update User.\n";
	cout << "\t[5] Find User.\n";
	cout << "\t[6] Main Menue.\n";
	cout << "===========================================\n";
	PerfromManageMenueOption((enManageUsers)ReadManageMenueOption());

}
void PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption) {
	switch (TransactionMenueOption)
	{
	case eDeposit:
		ShowDepositScreen();
		break;
	case eWithdraw:
		ShowWithdrawScreen();
		break;
	case eTotalBalances:
		ShowTotalBalancesScreen();
		break;
	}
}
short ReadTransactionsMenueOption() {
	cout << "Choose what do you want to do? [1 to 4]? ";
	short Choice = 0;
	cin >> Choice;
	return Choice;
}
void ShowTransactionsMenue() {
	system("cls");
	if
		(!CheckAccessPermission(enMainMenuePermissions::pTranactions))
	{
		ShowAccessDeniedMessage();
		ShowMainMenue();
		return;
	}
	cout << "===========================================\n";
	cout << "\t\tTransactions Menue Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balances.\n";
	cout << "===========================================\n";
	PerfromTranactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
}
void startUserScreen() {
	short Number = 0;
	do {
		ManageUsersMenueScreen();
		cout << "\n\nPress any key to go back to Main Menue...\n";
		system("pause>0");

	} while (Number != 6);
}
void PerfromMainMenueOption(enMainMenueOptions MainMenueOption) {

	switch (MainMenueOption)
	{
	case eListClients:
		system("cls");
		ShowAllClientsScreen();

		break;
	case eAddNewClient:
		system("cls");
		ShowAddNewClientsScreen();
		

		break;
	case eDeleteClient:
		system("cls");
		DeleteClientsScreen();
		break;
	case eUpdateClient:
		system("cls");
		UpdateClientsScreen();
		break;
	case eFindClient:
		system("cls");
		FindClientsScreen();
		break;
	case eTransactions:
		system("cls");
		ShowTransactionsMenue();
		break;
	case eManageUsers:
		system("cls");
		startUserScreen();
		break;
	case eLogout:
		system("cls");
		ShowEndScreen();
		exit(0);
		break;
	}
}

void ShowMainMenue() {
	
	cout << "===========================================\n";
	cout << "\t\tMain Menue Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Manage Users.\n";
	cout << "\t[8] Logout.\n";
	cout << "===========================================\n";  
	PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

void start() {
	short Number=0;
    do {
		ShowMainMenue();
		cout << "\n\nPress any key to go back to Main Menue...\n";
		system("pause>0");
		
	} while (Number != 6);
}

void ShowMUserScreen() {
	sUser TempUser;  
	system("cls");

	cout << "\n---------------------------------\n";
	cout << "\tLogin Screen";
	cout << "\n---------------------------------\n";

	TempUser.UserName = ReadUesrInfo("Username: ");
	TempUser.PassWord = ReadUesrInfo("Password: ");

	while (!DataIsValid(TempUser.UserName, TempUser.PassWord)) {
		cout << "Invalid Username/Password\n\n";
		TempUser.UserName = ReadUesrInfo("Username: ");
		TempUser.PassWord = ReadUesrInfo("Password: ");
	}

	FindUserByUsernameAndPassword(TempUser.UserName, TempUser.PassWord, CurrentUser);

	start(); 
}

int main()
{
	ShowMUserScreen();

	system("pause>0"); 
	return 0;
}
