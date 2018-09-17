#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void initialize_dictionary(vector<string>& dictionary, ifstream& input);
void printMan(unsigned int stage);

int main()
{
	vector<string> dictionary;
	vector<bool> discovered;
	string word, guesses;
	unsigned int stage = 0;
	bool won = false;
	char guess = 0;
	int entry = 0;
	ifstream input("dictionary.txt");
	initialize_dictionary(dictionary, input);
	srand(time(NULL));

	cout << "You are about to play Hangman.\n";
	cout << "Enter any positive number to start playing. Enter a negative number to exit the game: ";
	cin >> entry;
	while (entry >= 0)
	{
		word = dictionary[rand() % dictionary.size()];
		discovered.clear();
		for (int i = 0; i < word.length(); i++)
		{
			discovered.push_back(false);
		}
		guesses.clear();
		stage = 0;
		won = false;

		cout << endl;
		while (stage < 9 && !won)
		{
			cout << "-----------------------------------\n";
			printMan(stage);
			for (int i = 0; i < word.length(); i++)
			{
				if (discovered[i])
				{
					cout << word[i] << " ";
				}
				else
				{
					cout << "_ ";
				}
			}
			cout << endl;
			cout << "Letters guessed: ";
			for (int i = 0; i < guesses.length(); i++)
			{
				cout << guesses[i];
				if (i < (guesses.size() - 1))
				{
					cout << ",";
				}
			}
			cout << endl << endl;

			cout << "Guess a letter: ";
			cin >> guess;

			if (guesses.find(guess) != string::npos)
			{
				cout << "You already guessed that letter, try another.\n";
			}
			else
			{
				guesses.append(1, guess);
				if (word.find(guess) != string::npos)
				{
					for (int i = 0; i < word.length(); i++)
					{
						if (word[i] == guess)
						{
							discovered[i] = true;
						}
					}
					for (int i = 0; i < discovered.size(); i++)
					{
						if (!discovered[i])
						{
							won = false;
							break;
						}
						else
						{
							won = true;
						}
					}
				}
				else
				{
					stage++;
				}
			}
			cout << "-----------------------------------\n";
		}
		if (stage == 9)
		{
			cout << "-----------------------------------\n";
			printMan(stage);
			cout << "You Lost! The correct word was " << word << endl;
			cout << "-----------------------------------\n";
		}
		if (won)
		{
			cout << "-----------------------------------\n";
			printMan(stage);
			for (int i = 0; i < word.length(); i++)
			{
				if (discovered[i])
				{
					cout << word[i] << " ";
				}
				else
				{
					cout << "_ ";
				}
			}
			cout << endl;
			cout << "Letters guessed: ";
			for (int i = 0; i < guesses.length(); i++)
			{
				cout << guesses[i];
				if (i < (guesses.size() - 1))
				{
					cout << ",";
				}
			}
			cout << endl;
			cout << "You Won! Congratulations, you guessed the word!\n";
			cout << "-----------------------------------\n";
		}
		cout << "Enter any positive number to start playing. Enter a negative number to exit the game: ";
		cin >> entry;
	}
	cout << "Hope you enjoyed the game! Have a nice day!\n";
	system("pause");
	return 0;
}

void initialize_dictionary(vector<string>& dictionary, ifstream& input)
{
	string str;
	while (!input.eof())
	{
		input >> str;
		dictionary.push_back(str);
	}
}

void printMan(unsigned int stage)
{
	// |/---
	// |  o
	// | /|\
	// | / \
	// |____

	switch (stage)
	{
	case 0:
		cout << "\n\n\n\n\n";
		break;
	case 1:
		cout << "\n\n\n\n_____";
		break;
	case 2:
		cout << "|\n|\n|\n|\n|____";
		break;
	case 3:
		cout << "|/---\n|\n|\n|\n|____";
		break;
	case 4:
		cout << "|/---\n|  o\n|\n|\n|____";
		break;
	case 5:
		cout << "|/---\n|  o\n|  |\n|\n|____";
		break;
	case 6:
		cout << "|/---\n|  o\n| /|\n|\n|____";
		break;
	case 7:
		cout << "|/---\n|  o\n| /|\\\n|\n|____";
		break;
	case 8:
		cout << "|/---\n|  o\n| /|\\\n| /\n|____";
		break;
	case 9:
		cout << "|/---\n|  o\n| /|\\\n| / \\\n|____";
		break;
	default:
		cout << "|/---\n|  o\n| /|\\\n| / \\\n|____";
		break;
	}
	cout << endl;
}