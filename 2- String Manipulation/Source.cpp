#include <iostream>
using namespace std;

const int Size = 100;

class NLP
{
private:

	char* str;
	char** A;
	char** B;
	char** uniArray;
	char** biArray;
	char** triArray;
	int len;
	int word;

public:

	//constructors
	NLP()
	{
		str = new char[Size];
		for (int i = 0; i < Size; i++)
			str[i] = '\0';
		len = 0;
		word = 0;
	}
	NLP(char* string)
	{
		str = new char[Size];
		for (int i = 0; i < Size; i++)
			str[i] = string[i];
	}
	NLP(char* string, int length)
	{
		str = new char[Size];
		for (int i = 0; i < Size; i++)
			str[i] = string[i];

		len = length;
	}

	//functions
	void setArray(char* string)
	{
		for (int i = 0; string[i] != '\0'; i++)
			str[i] = string[i];
	}
	void setLength(int length)
	{
		len = length;
	}

	int strLength(char* string)
	{
		for (int i = 0; i < Size; i++)
		{
			if (*(str + i) == '\0')
				return i;
		}
		return 0;
	}

	int wordCount(char* string)
	{
		int count = 0;

		for (int i = 0; i < len; i++)
		{
			if (*(str + i) == ' ')
				count++;
		}

		return count + 1;
	}

	int uniqueWord(char* string, int length, int words)
	{
		A = new char* [words]; //declaring a 2D array to store list of words

		const int word = words;

		for (int i = 0; i < word; i++) //making columns for each row
			A[i] = new char[Size];

		for (int i = 0; i < word; i++) //initialising it with null
			for (int j = 0; j < Size; j++)
				A[i][j] = '\0';

		//first creating a list of all the words used in the string using a 2D array
		//with every row for a single word
		int row = 0;
		int col = 0;
		for (int i = 0; i < length + 1; i++)
		{
			if (str[i] == ' ')
			{
				row++;
				col = 0;
				continue;
			}

			if (str[i] == '\0')
			{
				break;
			}

			A[row][col] = str[i];
			col++;
		}
		//			cout<<"\n(words used: ";
		//			for(int i=0; i<word; i++) {
		//			{
		//				cout<<endl;
		//				for(int j=0; A[i][j]!='\0'; j++)
		//					cout<<A[i][j];
		//				}
		//			}
		//				
		//			cout<<" )";

					//comparing
		cout << "\n";
		int sameWords = 0;
		int* visited = new int[word];

		for (int i = 0; i < word; i++)
		{
			if (visited[i] == 1)
				continue;

			for (int j = i + 1; j < word; j++)
			{
				int flag = 0;
				for (int k = 0; A[i][k] != '\0' || A[j][k] != '\0'; k++)
				{
					if (A[i][k] != A[j][k])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)	//if the word matches, it will later be subtracted from the total words
				{
					sameWords++;
					visited[j] = 1;
				}
			}
		}

		int uniqueWords = word - sameWords;
		return uniqueWords;

		//		delete[] visited;
		//		for(int i=0; i<words; i++)
		//			delete[] A[i];

	}

	void unigrams(char* string, int length, int words, int unique)
	{
		B = new char* [words]; //declaring a 2D array to store words

		for (int i = 0; i < words; i++) //making columns for each row
			B[i] = new char[Size];

		for (int i = 0; i < words; i++)
			for (int j = 0; j < Size; j++)
				B[i][j] = '\0';

		//first creating a list of all the words used in the string using a 2D array
		//with every row for a single word
		int row = 0;
		int col = 0;
		for (int i = 0; i < length + 1; i++)
		{
			if (str[i] == ' ') //if space encountered, move to next row for next word
			{
				row++;
				col = 0;
				continue;
			}

			if (str[i] == '\0')
			{
				break;
			}

			B[row][col] = str[i];
			col++;
		}


		//comparing

		int unigram = 0;
		cout << "\n\nUnique Words are: \n";
		int* checked = new int[words];

		//delaring an array for storing frequency
		int* frequency = new int[unique];
		int n = 0;

		//declaring a new 2D array to store unique words
		uniArray = new char* [unique];
		for (int i = 0; i < unique; i++)
			uniArray[i] = new char[100];
		for (int i = 0; i < unique; i++)
			for (int j = 0; j < 100; j++)
				uniArray[i][j] = '\0';

		for (int i = 0; i < words; i++)
		{
			int freq = 1;

			if (checked[i] == 1)
				continue;

			for (int j = i + 1; j < words; j++)
			{
				int flag = 0;

				for (int k = 0; B[i][k] != '\0' || B[j][k] != '\0'; k++)
				{
					if (B[i][k] != B[j][k])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					freq++;
					checked[j] = 1;
				}
			}

			for (int p = 0; B[i][p] != '\0'; p++)
				uniArray[n][p] = B[i][p];
			frequency[n] = freq;
			n++;

		}

		//sortingg in descending order
		char temp2[100] = { '\0' };
		for (int i = 0; i < unique; i++)
		{
			for (int j = 0; j < unique - 1; j++)
			{
				if (frequency[j] < frequency[j + 1])
				{
					int temp = frequency[j];
					frequency[j] = frequency[j + 1];
					frequency[j + 1] = temp;

					for (int k = 0; k < 100; k++)
					{
						temp2[k] = uniArray[j][k];
						uniArray[j][k] = uniArray[j + 1][k];
						uniArray[j + 1][k] = temp2[k];
					}
				}

			}
		}

		//displaying

		for (int p = 0; p < unique; p++) {
			cout << "'";
			for (int q = 0; uniArray[p][q] != '\0'; q++)
				cout << uniArray[p][q];
			cout << "' which appears " << frequency[p] << " time(s)\n";
		}

		//		delete[] checked;
		//		delete[] frequency;
		//		for(int i=0; i<words; i++)
		//				delete[] B[i];
	}

	void bigrams(char* string, int length, int words)
	{
		int Size = words - 1; //bigrams will always be one size less
		cout << endl;
		int row = 0;
		int col = 0;

		biArray = new char* [Size];

		for (int i = 0; i < Size; i++)
		{
			biArray[i] = new char[50];
			for (int j = 0; j < 50; j++)
				biArray[i][j] = '\0';
		}


		//to find spaces in the string
		int* spaces = new int[words];
		int ind = 0;
		for (int i = 0; i < length + 1; i++)
		{
			if (string[i] == ' ' || string[i] == '\0')
			{
				spaces[ind] = i;
				ind++;
			}
		}

		//copying the pair of words in bigram array
		int c = 0;
		for (int i = 0; i < spaces[1]; i++)//second space
		{
			biArray[0][c] = string[i];
			c++;
		}
		int x = 0;
		c = 0;
		for (int j = 1; j < Size; j++)
		{
			for (int i = spaces[x] + 1; i < spaces[x + 2]; i++)
			{
				biArray[j][c] = string[i];
				c++;
			}
			c = 0;
			x++;
		}

		//display of bigrams
		cout << "Bigrams are: \n";
		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; biArray[i][j] != '\0'; j++)
				cout << biArray[i][j];
			cout << endl;
		}
		cout << endl;
		//UNIQUE
		int sameWords = 0;
		int* visited2 = new int[Size];

		for (int i = 0; i < Size; i++)
		{
			if (visited2[i] == 1)
				continue;

			for (int j = i + 1; j < Size; j++)
			{
				int flag = 0;
				for (int k = 0; biArray[i][k] != '\0' || biArray[j][k] != '\0'; k++)
				{
					if (biArray[i][k] != biArray[j][k])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)	//if the word matches, it will later be subtracted from the total words
				{
					int index = 0;
					sameWords++;
					visited2[j] = 1;
					//					for(int f=0; biArray[i][f]!='\0'; f++){
					//						cout<<biArray[i][f];
					//					}
					//					cout<<endl;
				}
			}
		}

		int biUnique = Size - sameWords;
		cout << "\nNumber of Unique Bigrams: " << biUnique << endl;

		cout << "\n\nUnique Bigrams are: \n";

		int* checked2 = new int[Size];

		//delaring an array for storing frequency
		int* frequency2 = new int[biUnique];
		int n = 0;

		//declaring a new 2D array to store biUnique words
		uniArray = new char* [biUnique];
		for (int i = 0; i < biUnique; i++)
			uniArray[i] = new char[100];
		for (int i = 0; i < biUnique; i++)
			for (int j = 0; j < 100; j++)
				uniArray[i][j] = '\0';

		for (int i = 0; i < Size; i++)
		{
			int freq = 1;

			if (checked2[i] == 1)
				continue;

			for (int j = i + 1; j < Size; j++)
			{
				int flag = 0;

				for (int k = 0; biArray[i][k] != '\0' || biArray[j][k] != '\0'; k++)
				{
					if (biArray[i][k] != biArray[j][k])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					freq++;
					checked2[j] = 1;
				}
			}

			for (int p = 0; biArray[i][p] != '\0'; p++)
				uniArray[n][p] = biArray[i][p];
			frequency2[n] = freq;
			n++;

		}

		//sortingg in descending order
		char temp2[100] = { '\0' };
		for (int i = 0; i < biUnique; i++)
		{
			for (int j = 0; j < biUnique - 1; j++)
			{
				if (frequency2[j] < frequency2[j + 1])
				{
					int temp = frequency2[j];
					frequency2[j] = frequency2[j + 1];
					frequency2[j + 1] = temp;

					for (int k = 0; k < 100; k++)
					{
						temp2[k] = uniArray[j][k];
						uniArray[j][k] = uniArray[j + 1][k];
						uniArray[j + 1][k] = temp2[k];
					}
				}

			}
		}

		//displaying

		for (int p = 0; p < biUnique; p++) {
			cout << "'";
			for (int q = 0; uniArray[p][q] != '\0'; q++)
				cout << uniArray[p][q];
			cout << "' which appears " << frequency2[p] << " time(s)\n";
		}

	}

	void trigrams(char* string, int length, int words)
	{
		//int Size= words-2; //trigrams will always be two Size less
		cout << endl;
		int row = 0;
		int col = 0;

		triArray = new char* [words - 2];

		for (int i = 0; i < words - 2; i++)
		{
			triArray[i] = new char[Size];
		}
		for (int i = 0; i < words - 2; i++)
			for (int j = 0; j < Size; j++)
				triArray[i][j] = '\0';

		//to find spaces in the string
		int* spaces2 = new int[words];
		int ind = 0;
		for (int i = 0; i < length + 1; i++)
		{
			if (string[i] == ' ' || string[i] == '\0')
			{
				spaces2[ind] = i;
				ind++;
			}
		}
		//copying the words in array
		int c = 0;
		for (int i = 0; i < spaces2[2]; i++)
		{
			triArray[0][c] = string[i];
			c++;
		}
		int x = 0;
		c = 0;
		for (int j = 1; j < words - 2; j++)
		{
			for (int i = spaces2[x] + 1; i < spaces2[x + 3]; i++)
			{
				triArray[j][c] = string[i];
				c++;
			}
			c = 0;
			x++;
		}
		//		for(int i=0; i<words; i++)
		//		{
		//			cout<<spaces2[i]<<" ";
		//		}
				//display of trigrams
		cout << "Trigrams are: \n";
		for (int i = 0; i < words - 2; i++)
		{
			for (int j = 0; triArray[i][j] != '\0'; j++)
				cout << triArray[i][j];
			cout << endl;
		}



		//UNIQUE
		int sameWords = 0;
		int* visited3 = new int[words - 2];

		for (int i = 0; i < words - 2; i++)
		{
			if (visited3[i] == 1)
				continue;

			for (int j = i + 1; j < words - 2; j++)
			{
				int flag = 0;
				for (int k = 0; triArray[i][k] != '\0' || triArray[j][k] != '\0'; k++)
				{
					if (triArray[i][k] != triArray[j][k])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)	//if the word matches, it will later be subtracted from the total words
				{
					sameWords++;
					visited3[j] = 1;
					//					for(int f=0; triArray[i][f]!='\0'; f++){
					//						cout<<triArray[i][f];
					//					}
					//					cout<<endl;
				}
			}
		}

		int triUnique = words - 2 - sameWords;
		cout << "\nNumber of Unique Trigrams: " << triUnique << endl;

		cout << "\n\nUnique Trigrams are: \n";

		int* checked2 = new int[words - 2];

		//delaring an array for storing frequency
		int* frequency3 = new int[triUnique];
		int n = 0;

		//declaring a new 2D array to store triUnique words
		uniArray = new char* [triUnique];
		for (int i = 0; i < triUnique; i++)
			uniArray[i] = new char[100];
		for (int i = 0; i < triUnique; i++)
			for (int j = 0; j < 100; j++)
				uniArray[i][j] = '\0';

		for (int i = 0; i < words - 2; i++)
		{
			int freq = 1;

			if (checked2[i] == 1)
				continue;

			for (int j = i + 1; j < words - 2; j++)
			{
				int flag = 0;

				for (int k = 0; triArray[i][k] != '\0' || triArray[j][k] != '\0'; k++)
				{
					if (triArray[i][k] != triArray[j][k])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					freq++;
					checked2[j] = 1;
				}
			}

			for (int p = 0; triArray[i][p] != '\0'; p++)
				uniArray[n][p] = triArray[i][p];
			frequency3[n] = freq;
			n++;

		}

		//sortingg in descending order
		char temp2[100] = { '\0' };
		for (int i = 0; i < triUnique; i++)
		{
			for (int j = 0; j < triUnique - 1; j++)
			{
				if (frequency3[j] < frequency3[j + 1])
				{
					int temp = frequency3[j];
					frequency3[j] = frequency3[j + 1];
					frequency3[j + 1] = temp;

					for (int k = 0; k < 100; k++)
					{
						temp2[k] = uniArray[j][k];
						uniArray[j][k] = uniArray[j + 1][k];
						uniArray[j + 1][k] = temp2[k];
					}
				}

			}
		}

		//displaying

		for (int p = 0; p < triUnique; p++) {
			cout << "'";
			for (int q = 0; uniArray[p][q] != '\0'; q++)
				cout << uniArray[p][q];
			cout << "' which appears " << frequency3[p] << " time(s)\n";
		}

	}
	//destructor
	~NLP()
	{
		delete[] str;
		for (int i = 0; i < word; i++)
			delete[] A[i];
		delete[] A;
		for (int i = 0; i < word; i++)
			delete[] B[i];
		delete[] B;
		for (int i = 0; i < word - 1; i++)
			delete[] biArray[i];
		delete[] biArray;
		for (int i = 0; i < word; i++)
			delete[] uniArray[i];
		delete[] uniArray;
		for (int i = 0; i < word - 2; i++)
			delete[] triArray[i];
		delete[] triArray;


	}
};



int main()
{
	char* string = new char[Size];

	cout << "Enter a string: ";
	cin.getline(string, Size);

	NLP  obj(string);

	int length = obj.strLength(string);

	NLP obj2(string, length);

	obj2.setArray(string);
	obj2.setLength(length);

	int words = obj2.wordCount(string);
	cout << "\nLength= " << length << "\n\nWords= " << words;

	cout << "\n\t\t-----------------------------------";

	int uniqueWords = obj2.uniqueWord(string, length, words);
	cout << "\nUnique Words= " << uniqueWords;

	obj2.unigrams(string, length, words, uniqueWords);

	cout << "\n\t\t-----------------------------------\n";

	obj2.bigrams(string, length, words);

	cout << "\n\t\t-----------------------------------\n";

	obj2.trigrams(string, length, words);


	cout << "\n\n";
	system("pause");
	return 0;
}
