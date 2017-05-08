#include<std_lib_facilities.h>

using namespace std;
void print(string ss);
int main()
{
	int letter;
	string word, newsuffix;
	vector<string> suffix;
	vector<string> etyma;
	vector<int> suffixnum;
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
			else { size++; }
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
				suffixnum.push_back(1);
				for (int i = 0; i < suffix.size() - 1; i++)
				{
					if (suffix[i] == newsuffix)
					{
						suffixnum[i]++;
						suffix.pop_back();
						suffixnum.pop_back();
						break;
					}
				}
			}
		}
		etyma.push_back(word);
	}
	ff.close();
	vector<int> position;
	int max;
	for (int i = 0; i < suffixnum.size(); i++)
	{
		max = suffixnum[i];
		position.push_back(i);
		for (int j = 0; j < position.size() - 1; j++)
		{
			if (max > suffixnum[position[j]])
			{
				position.insert(position.begin() + j, i);
				position.pop_back();
				break;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << suffix[position[i]] << ' '
			<< suffixnum[position[i]] << endl;
	}
	int havenum = 0;
	while (1)
	{
		string mysuffix;
		cout <<'\n'<< "Please enter the mysuffic ( enter \"Quit\" for quit):" << endl;
		cin >> mysuffix;
		if (mysuffix == "Quit")
		{
			break;
		}
		else if (mysuffix.size() != letter)
		{
			cout << "error" << endl;
			continue;
		}
		print(mysuffix);
	}
}
void print(string mysuffix)
{
	string word;
	ifstream ff("dictionary.txt");
	vector<string>etyma;
	vector<string>myword;
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
	cout << myword.size() << endl;
}