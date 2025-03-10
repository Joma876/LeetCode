#pragma once
#include <iostream>;
namespace Custom {
	struct string {
		char* String; 
		~string(); 
		int length(const char String[]);
		int AmountOf(char& Symbol);
		int ToInt(); 
		void Copy(const char Origin[]);
		void Turn(); 

		bool Palindrom(const char Other[]);

		void operator= (const char Other[]);
		friend std::ostream& operator<<(std::ostream& os, string& obj); 
	};

	string::~string() {
		delete[] String; 
	}

	void string::operator=(const char Input[]) {
		String = new char[length(Input) + 1]; 
		int x = 0;
		for (x = 0; Input[x] != '\0'; x++) String[x] = Input[x];
		String[x] = '\0';

	}

	int string::length(const char String[]) {
		int it = 0;
		while (String[it] != '\0') it++;
		return it;
	}

	int string::ToInt() {
		int integer = 0;
		for (int x = 0; x < length(String); x++) {
			if (String[x] - '0' >= 0 && String[x] - '0' < 10) 
			{
				integer *= 10;
				integer += String[x] - '0';
			}
		}
		return integer; 
	}

	void string::Copy(const char Origin[]) {
		int x = 0;
		for (x = 0; Origin[x] != '\0'; x++) String[x] = Origin[x];
		String[x] = '\0';
		return;
	}

	void string::Turn() {
		char Temp; 
		int StringLength = length(String) - 1;
		for (int x = 0; x < StringLength/2; x++) {
			Temp = String[x]; 
			String[x] = String[StringLength - x]; 
			String[StringLength - x] = Temp; 
		}
	}

	int string::AmountOf(char& Symbol) {
		int Amount = 0;
		for (int it = 0; String[it] != '\0'; it++) if (Symbol == String[it]) Amount++;
		return Amount;
	}

	bool string::Palindrom(const char Other[]) {
		if (length(String) != length(Other)) return false;
		int lengthOfString = length(Other) - 1; 
		for (int x = 0; String[x] != '\0'; x++) if (String[x] != Other[lengthOfString-x]) return false;
		return true;
	}

	std::ostream& Custom::operator<<(std::ostream& os, string& obj)
	{
		os << obj.String; 
		return os; 
	}
}