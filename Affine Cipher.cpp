#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string solve() {
	cout << "please input your desired sentence: ";
	string str;
	cin.ignore();
	getline(cin,str);
	int final;
	string cipher;
	int len = str.length();
	int x;
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	for (int i = 0; i != len; i++){
		if (isalpha(str[i])) {


			if (str[i] == ' ') {
				cipher = cipher + ' ';
			}
			else {
				x = int(str[i]) - int('A');
				final = (5 * x + 8) % 26;
				cipher = cipher + char(final + int('A'));
			}
		}
		else {
			cipher = cipher + str[i];
		}

	}
	return cipher;
}



string antisolve() {
	cout << "welcome to decryption, please insert a sentence to decrypt\n";
	string str;
	cin.ignore();
	getline(cin,str);
	string message;
	int y;
	int final;
	int len = str.length();
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	for (int i = 0; i < (len); i++) {

		if (isalpha(str[i])) {
			if (str[i] == ' ') {
				message = message + ' ';
			}
			else {
				y = int(str[i]) - int('A');
				int final = (21 * (y - 8)) % 26;
				if (final < 0) { final = final + 26; }
				message = message + char(final + int('A'));

			}
		}
		else {
			message = message + str[i];
		}
	}
	return message;
}




void menu() {
	cout << "welcome to affine cipher, please select an option (all special characters and numbers arent encrypted)" << endl;
	cout << "1-Encrypt a message" << endl;
	cout << "2-Decrypt a message" << endl;
	cout << "3-Exit code" << endl;
	string response;
	cin >> response;
	if (response == "1") {
		cout << "your encrypted code is: " << solve() << endl;
		cout << "==============================" << endl;
		menu();
	}
	else if (response == "2") {
		cout << "your decrypted code is: " << antisolve() << endl;
		cout << "==============================" << endl;
		menu();
	}
	else if (response == "3") {
		cout << "response at 3 is" << response;
		exit(0);
	}
	else{
		cout << "Please input a correct number" << endl;
		menu();		
	}
}

int main()
{
	menu();
}



