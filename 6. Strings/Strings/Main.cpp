#include <iostream>
#include <string>
#include <algorithm>
#include <locale>

using namespace std;

string ReverseString(string str);
string ToUpperCase(string str);
string ToLowerCase(string str);
bool IsPolindrome(string str);

int main()
{
	cout.setf(ios::boolalpha);

	string str = "some STRING";
	cout << "Original string: " << str << endl;
	cout << "Reversed string: " << ReverseString(str) << endl;
	cout << "To upper case: " << ToUpperCase(str) << endl;
	cout << "To lower case: " << ToLowerCase(str) << endl;
	cout << "Is \"rizov\" a polindrome: " << IsPolindrome("rizov") << endl;
	cout << "Is \"vozov\" a polindrome: " << IsPolindrome("vozov") << endl;
}

string ReverseString(string str)
{
	string reversedStr = str;
	reverse(reversedStr.begin(), reversedStr.end());

	return reversedStr;
}

string ToUpperCase(string str)
{
	string result = str;

	locale loc;
	for (int i = 0; i < str.length(); i++)
	{
		result[i] = toupper(str[i]);
	}

	return result;
}

string ToLowerCase(string str)
{
	string result = str;

	locale loc;
	for (int i = 0; i < str.length(); i++)
	{
		result[i] = tolower(str[i]);
	}

	return result;
}

bool IsPolindrome(string str)
{
	bool isPolindrome = true;
	for (int i = 0; i < str.length() / 2; i++)
	{
		if (str[i] != str[str.length() - i - 1])
		{
			isPolindrome = false;
			break;
		}
	}

	return isPolindrome;
}
