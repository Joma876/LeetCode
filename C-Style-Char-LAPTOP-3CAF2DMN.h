#pragma once
#include <iostream>;
namespace Custom {
	struct string {
		char* content; 
		~string(); 
		int length(const char String[]);
		int AmountOf(char& Symbol);
		int ToInt(); 
		void Copy(const char Origin[]);
		void Turn(); 

		bool Palindrom(const char Other[]);

		void operator= (const char Other[]);
		friend std::ostream& operator<<(std::ostream& os, string& obj); 
		friend std::istream& operator>>(std::istream& is, string& obj); 
	};

	string::~string() {
		delete[] content; 
	}

	void string::operator=(const char Input[]) {
		content = new char[length(Input) + 1]; 
		int x = 0;
		for (x = 0; Input[x] != '\0'; x++) content[x] = Input[x];
		content[x] = '\0';

	}

	int string::length(const char String[]) {
		int it = 0;
		while (String[it] != '\0') it++;
		return it;
	}

	int string::ToInt() {
		int integer = 0;
		for (int x = 0; x < length(content); x++) {
			if (content[x] - '0' >= 0 && content[x] - '0' < 10) 
			{
				integer *= 10;
				integer += content[x] - '0';
			}
		}
		return integer; 
	}

	void string::Copy(const char Origin[]) {
		int x = 0;
		for (x = 0; Origin[x] != '\0'; x++) content[x] = Origin[x];
		content[x] = '\0';
		return;
	}

	void string::Turn() {
		char Temp; 
		int StringLength = length(content) - 1;
		for (int x = 0; x < StringLength/2; x++) {
			Temp = content[x]; 
			content[x] = content[StringLength - x]; 
			content[StringLength - x] = Temp; 
		}
	}

	int string::AmountOf(char& Symbol) {
		int Amount = 0;
		for (int it = 0; content[it] != '\0'; it++) if (Symbol == content[it]) Amount++;
		return Amount;
	}

	bool string::Palindrom(const char Other[]) {
		if (length(content) != length(Other)) return false;
		int lengthOfString = length(Other) - 1; 
		for (int x = 0; content[x] != '\0'; x++) if (content[x] != Other[lengthOfString-x]) return false;
		return true;
	}

	std::ostream& Custom::operator<<(std::ostream& os, string& obj)
	{
		os << obj.content; 
		return os; 
	}

	
}