#include<std_lib_facilities.h>

using namespace std;
void print(string ss);
int main()
{
	int letter;
	string word,newsuffix;
	vector<string> suffix;
	vector<string> etyma;
	ifstream ff("dictionary.txt");
	cout << "Please enter the number of letters:" << endl;
	cin >> letter;
	while (ff)
	{
		ff >> word;
		int size = 0;
		while (size < etyma.size())
		{
			if (etyma[size] != word.substr(0, etyma[size].length()))
			{
				etyma.erase(etyma.begin() + size);
			}
			else{ size++; }
		}
		for (int i = 0; i < etyma.size(); i++)
		{
			if (word.size() != etyma[i].size() + letter)
			{
				continue;
			}
			if (etyma[i] == word.substr(0, word.length() - letter))
			{
				newsuffix = word.substr(word.length() - letter);
				suffix.push_back(newsuffix);
				for (int i = 0; i < suffix.size()-1; i++)
				{
					if (suffix[i] == newsuffix)
					{
						suffix.pop_back();
						break;
					}
				}
			}
		}
		etyma.push_back(word);
	}
	ff.close();
	string mysuffix;
	cout << "Please enter the mysuffic:" << endl;
	cin >> mysuffix;
	for (int i = 0; i < suffix.size(); i++)
	{
		if (suffix[i] == newsuffix)
		{
			print(mysuffix);
		}
	}
}
void print(string ss)
{
	string mysuffix,word;
	ifstream ff("dictionary.txt");
	vector<string>etyma;
	vector<string>myword;
	cout << "Please enter the mysuffic:" << endl;
	cin >> mysuffix;
	while (ff)
	{
		ff >> word;
		int size = 0;
		while (size < etyma.size())
		{
			if (etyma[size] != word.substr(0, etyma[size].length()))
			{
				etyma.erase(etyma.begin() + size);
			}
			else { size++; }
		}
		for (int i = 0; i < etyma.size(); i++)
		{
			if (word.substr(etyma[i].length()) == mysuffix)
			{
				myword.push_back(word);
			}
		}
		etyma.push_back(word);
	}
	ff.close();
	for (int i = myword.size() - 1; i >= 0; i--)
	{
		cout << myword[i] << endl;
	}
}