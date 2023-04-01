#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>

bool is_palindrom(std::string& word);
int count_marks(std::string& str);
std::string last_char_sub_string(std::string& str, char c);

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	srand(time(NULL));

	/*
		The string str is given. The user enters the sym character. 
	The program creates a new string that consists of
	the sym character. The length of the new line is equal to the number
	of matches of the entered character in the original string
	str.
	Example:
	str = "Hello world!"
	sym = 'o'
	new_str = "oo"
		���� ������ str. ������������ ������ ������ sym. 
	��������� ������ ����� ������, ������� ������� �� 
	������� sym. ����� ����� ������ ����� ���������� 
	���������� ��������� ������� � ����������� ������ 
	str.
	������:
	str = "Hello world!"
	sym = 'o'
	new_str = "oo"
	*/
	
	{
		std::cout << "Exercise 1.\n��������� ��� ���������� ������ �� �������� ������������� � ������.\n";
		std::string str = "Hello world!";
		std::cout << str << std::endl;
		std::cout << "Enter a symbol -> ";
		char sym = 'o';
		std::cin >> sym;
		std::string new_str;
		for (auto i : str) {
			if (i == sym)
				new_str += sym;
		}
		std::cout << "A string of symbols '" << sym << "' in string \"" << str << "\" is -> " << new_str << std::endl;
	}
	

	/*
		Create a function that accepts a word and
	returns true if it is a palindrome. 
	Otherwise, false is returned. The function should 
	be unregistered.
		�������� �������, ������� ��������� ����� � 
	���������� true, ���� ��� �������� �����������. �
	��������� ������ ������������ false. ������� ������ 
	���� �������������������.
	*/
	
	{
		std::cout << "\n\n\nExercise 2\nA program for determining the palindrome\n";
		std::cout << "Enter the word -> ";
		std::string word;
		std::cin >> word;
		std::cout << word << std::endl;
		if (is_palindrom(word))
			std::cout << "The word \"" << word << "\" is a palindrom.\n";
		else
			std::cout << "The word \"" << word << "\" is not a palindrom.\n";
	}
	


	/*
		Create a function that accepts a string. 
	The function counts all spaces, dots, commas,
	exclamation marks and question marks that are
	in the passed string and returns their total number.
		�������� �������, ������� ��������� ������. 
	������� ������� ��� �������, �����, �������, 
	��������������� � �������������� �����, ������� ���� 
	� ���������� ������ � ���������� �� ����� ����������.
	*/
	
	{
		std::cout << "\n\n\nExercise 3.\nCounting punctuation marks.\n";
		std::cout << "Enter string -> ";
		std::cin.ignore();
		std::cin.clear();
		std::cin.sync();
		std::string str;
		std::getline(std::cin, str);
		std::cout << "There are " << count_marks(str) << "  \"' ' '.' ',' '!' '?'\" such characters in the line.\n";
	}
	

	/*
		Create a function that accepts a string and
	a character. The function searches for the last occurrence of a character in
	the passed string and returns a substring
	starting with this character and ending with 
	the end of the line. If there is no character in the string, then the function 
	returns an empty string.
		�������� �������, ������� ��������� ������ � 
	������. ������� ���� ��������� ��������� ������� � 
	���������� ������ � ���������� ���������, 
	������������ � ����� ������� � ��������������� 
	������ ������. ���� ������� � ������ ���, �� ������� 
	���������� ������ ������.
	*/
	std::cout << "\n\n\nExercise 4.\n";
	std::cout << "Enter string -> ";
	std::string str;
	std::getline(std::cin, str);
	char c;
	std::cout << "Enter a character -> ";
	std::cin >> c;
	std::cout << str << std::endl;
	std::cout << last_char_sub_string(str, c) << std::endl;

	return 0;
}

// ������� ������������ ��������� ������������ � ���������� ������� 'c' � ������ �� ����� ������
// a function that returns a substring starting from the last character 'c' in the string to the end of the string
std::string last_char_sub_string(std::string& str, char c) {
	if (str.rfind(c) == std::string::npos) {
		std::string empty_str;
		return empty_str;
	}
	return str.substr(str.rfind(c));
}

// ������� ��� �������� ���������� ������ ���������� � ��������
// function for counting the number of punctuation marks and spaces
int count_marks(std::string& str) {
	int count = 0;
	for (auto i : str) {
		if (i == '.' || i == ',' || i == '?' || i == ' ' || i == '!')
			count++;
	}
	return count;
}

// ������� ��� �������� ����������
// function for checking the palindrome
bool is_palindrom(std::string& word) {
	for (size_t i = 0; i < word.length(); i++) {
		if (word[i] >= 'A' && word[i] <= 'Z' || word[i] >= '�' && word[i] <= '�')
			word[i] = std::tolower(word[i]);
		if (word[word.length() - i] >= 'A' && word[word.length() - i] <= 'Z' || word[word.length() - 1 - i] >= '�' && word[word.length() - 1 - i] <= '�')
			word[i] = std::tolower(word[word.length() - 1 - i]);
		if (word[i] != word[word.length() - 1 - i])
			return false;
	}
	return true;
}















