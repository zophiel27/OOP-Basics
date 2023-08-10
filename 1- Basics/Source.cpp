#include <iostream>
using namespace std;
const int sizeV = 500;

void display(char* array, int size);
void sort(char* array, int size);
void distinct(char* array, int& size);
char* Union(char* setA, char* setB, int size1, int size2, int& size3);
char* Intersect(char* setA, char* setB, int size1, int size2, int& size3);
void VOWELS(char* str, int** vowel, int count);
void circularShift(int& a, int& b, int& c, int num);
int main()
{
	int op;
	input:
	cout << "Choose from the following:\n1.Find AnB, AuB, U-(AUB), A', B'\n2.Check vowel and consonants count and display vowels in descending order\n3.Given three variables x, y, z, circularly shift their values to right\n";
	cin >> op;
	if (op == 1) {
		char* U = new char[26];
		int size1 = 0;//A
		int size2 = 0;//B 
		int size3 = 0;//finalarray

		for (int i = 0; i < 26; i++) //filling set U with alphabets
			U[i] = ('a' + i);

		cout << "Enter size of set A: "; //input A
		cin >> size1;
		char* A = new char[size1];

		cout << "Enter array elements: ";
		for (int i = 0; i < size1; i++)
		{
			cin >> A[i];

			if (A[i] >= 65 && A[i] <= 90)
				A[i] = A[i] + 32;
		}

		cout << "\nEnter size of set B: "; //input B
		cin >> size2;
		char* B = new char[size2];

		cout << "Enter array elements: ";
		for (int i = 0; i < size2; i++)
		{
			cin >> B[i];

			if (B[i] >= 65 && B[i] <= 90)
				B[i] = B[i] + 32;
		}

		//making sets distinct
		distinct(A, size1);
		distinct(B, size2);

		//the main result array pointer
		char* result;

		//UNION

		result = Union(A, B, size1, size2, size3);

		sort(result, size3);
		cout << "\nAUB ";//"of size "<<size3;
		display(result, size3);

		//INTERSECTION
		result = Intersect(A, B, size1, size2, size3);
		cout << "\nAnB ";
		display(result, size3);


		//U-(AUB)
		result = Union(A, B, size1, size2, size3);
		cout << "\nU-(AUB) : { ";
		for (int i = 0; i < 26; i++)
		{
			int flag = 1;
			for (int j = 0; j < size3; j++)
			{
				if (U[i] == result[j])
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				cout << U[i] << " ";
			}
		} cout << "}\n";


		cout << "\nA' : { ";
		for (int i = 0; i < 26; i++)
		{
			int flag = 1;
			for (int j = 0; j < size1; j++)
			{
				if (U[i] == A[j])
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				cout << U[i] << " ";
			}
		} cout << "}\n";

		cout << "\nB' : { ";
		for (int i = 0; i < 26; i++)
		{
			int flag = 1;
			for (int j = 0; j < size2; j++)
			{
				if (U[i] == B[j])
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				cout << U[i] << " ";
			}
		} 
		cout << "}\n\n\n";
	}
	else if(op == 2) {
		
		char* str = new char[sizeV];
		int** vowel = new int* [5];	//making a 5x2 array, one column for the vowels and second column for their count
		for (int i = 0; i < 5; i++)
			vowel[i] = new int[1]{0};

		for (int i = 0; i < 5; i++)		//initialising it to zero
			for (int j = 0; j < 2; j++)
				vowel[i][j] = 0;

		cout << "Enter string: ";
		cin.ignore();
		cin.getline(str, sizeV);

		int V_count = 0;
		int C_count = 0;

		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == ' ')
				continue;

			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
				V_count++;

			else if ((str[i] > 'a' && str[i] <= 'z') || (str[i] > 'A' && str[i] <= 'Z'))
				C_count++;

		}

		cout << "\nConsonants: " << C_count << endl << "Vowels: " << V_count << "\n\n";

		VOWELS(str, vowel, V_count);

		//sorting 
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5 - 1; j++)

				if (vowel[j][1] < vowel[j + 1][1])
				{
					int temp = vowel[j][1];
					vowel[j][1] = vowel[j + 1][1];
					vowel[j + 1][1] = temp;		//till here it sorts the second column

					int temp2 = vowel[j][0];
					vowel[j][0] = vowel[j + 1][0];
					vowel[j + 1][0] = temp2;	//it will sort the vowels(first column) to match the numbers
				}

		//display
		for (int i = 0; i < 5; i++)
			cout << char(vowel[i][0]) << ": " << vowel[i][1] << endl;

		cout << "\n\n";

		//deleting pointers
		delete[] str;
		//	for(int i=0; i<5; i++)
		//		delete[] vowel[i];

	}
	else if (op == 3) {
		int x, y, z, num;

		cout << "Enter x: ";
		cin >> x;
		cout << "Enter y: ";
		cin >> y;
		cout << "Enter z: ";
		cin >> z;

		cout << "\nEnter the number of times you want to shift: ";
		cin >> num;

		cout << "\nBefore shift: ";
		cout << "x=" << x;
		cout << ", y=" << y;
		cout << ", z=" << z;

		circularShift(x, y, z, num);

		cout << "\nAfter shift: ";
		cout << "x=" << x;
		cout << ", y=" << y;
		cout << ", z=" << z;

	}
	else {
		cout << "Invalid Input";
	}
	
	char op2;
	cout << "\nWant to choose again? (y/n)\n";
	cin >> op2;
	if (op2 == 'y') {
		system("cls"); 
		goto input;
	}
		
	cout << endl;
	system("pause");
	return 0;

}

char* Intersect(char* setA, char* setB, int size1, int size2, int& size3) {

	char* setC = new char[size1 + size2];
	int size = 0;

	for (int i = 0; i < size1; i++) //increments through A to check if any of those elements is in B
	{						  //doesnt matter which array is bigger, both are distinct anyway
		for (int j = 0; j < size2; j++)
		{
			if (setA[i] == setB[j])
			{
				setC[size] = setA[i];
				size++;
			}
		}
	}

	size3 = size;

	char* final = new char[size3];
	for (int i = 0; i < size3; i++)
		final[i] = setC[i];

	delete[] setC;

	return final;

}
char* Union(char* setA, char* setB, int size1, int size2, int& size3) {

	char* setC = new char[size1 + size2];
	int size = 0;

	//copying all elements of setA into new array
	for (int i = 0; i < size1; i++)
	{
		*(setC + size) = *(setA + i);
		size++;
	}

	//then copying elements from setB that were not in setA

	for (int i = 0; i < size2; i++)//iterating through B 
	{
		int flag = 1;
		for (int j = 0; j < size1; j++) //iterating through A array to see if that element appears; if so, then break and move to next element of B
		{
			if (setB[i] == setA[j])
			{
				flag = 0;
				break;
			}
		}

		if (flag == 1)
		{
			setC[size] = setB[i];
			size++;
		}
	}

	size3 = size;

	char* final = new char[size3];
	for (int i = 0; i < size3; i++)
		final[i] = setC[i];

	delete[] setC;

	return final;
}
void display(char* array, int n) {
	cout << ": { ";
	for (int i = 0; i < n; i++)
	{
		cout << *(array + i) << " ";
	}
	cout << "}\n";

}
void sort(char* array, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)

			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}

}
void distinct(char* array, int& n) {
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; )
		{
			if (array[i] == array[j])
			{
				for (int k = j; k < n - 1; ++k)
					array[k] = array[k + 1];
				n--;
			}
			else
				++j;
		}
}
void VOWELS(char* str, int** vowel, int count) {

	vowel[0][0] = 97; //ascii code of all the vowels
	vowel[1][0] = 101;
	vowel[2][0] = 105;
	vowel[3][0] = 111;
	vowel[4][0] = 117;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == 'a' || str[i] == 'A')
			vowel[0][1] += 1;
		else if (str[i] == 'e' || str[i] == 'E')
			vowel[1][1] += 1;
		else if (str[i] == 'i' || str[i] == 'I')
			vowel[2][1] += 1;
		else if (str[i] == 'o' || str[i] == 'O')
			vowel[3][1] += 1;
		else if (str[i] == 'u' || str[i] == 'U')
			vowel[4][1] += 1;

	}


}
void circularShift(int& a, int& b, int& c, int num) {

	int* p1 = &a;
	int* p2 = &b;
	int* p3 = &c;

	for (int i = 0; i < num; i++)
	{
		int temp = *p3;
		*p3 = *p2;
		*p2 = *p1;
		*p1 = temp;
	}

}