#include "Header.h"

class Encrypt {

	fstream DataSheet;
	array<char, 25> Alpha; 

	string Data; 
	char Key; 

private: 

	void encrypt(); 
	void CheckForDouble(); 

public: 
	Encrypt(); 
};
Encrypt::Encrypt() 
{
	DataSheet.open("Text.dat", ios::in); 
	if(!cin.fail())	{
		cout << "Geben sie den Key an: ";
		cin >> Key;
		cout << "Geben sie Ihr Kennwort an: ";
		cin >> Data;
		cin.clear(); 
	}

	encrypt(); 
}

void Encrypt::CheckForDouble() {
	unordered_map<char, int> Doups; 
	for (int It = 0; It < Data.size(); It++) {

		if (Doups.count(Data[It])) {
			Data.erase(It,It); 
		}
	}
	return; 
}

void Encrypt::encrypt()
{
	CheckForDouble(); 
}

int main(){
	Encrypt Data; 
}