#include <iostream>
using namespace std;

class Publication //Parent class that holds title and price
{
public:

	char* title;
	float price;

	Publication()
	{
		title = NULL;
		price = 0;
	}
	Publication(char* Title, float Price)
	{
		int i = 0;
		for (i; Title[i] != '\0'; i++)
		{
			//to find the length of the string
		}
		title = new char[i];

		for (i = 0; Title[i] != '\0'; i++)
		{
			title[i] = Title[i];
		}

		price = Price;
	}
	void getData1() //input function
	{
		int size;
		cout << "Enter the length of the book title: ";
		cin >> size;

		title = new char[size];

		cout << "Enter the title of the book: ";
		cin.ignore();
		cin.getline(title, size);

		cout << "Enter the price: $";
		cin >> price;
	}
	void putData1() //display function
	{
		cout << "\nPublication Title: ";
		for (int i = 0; title[i] != '\0'; i++)
		{
			cout << title[i];
		}
		cout << "\nPrice: $" << price;
	}

	~Publication()
	{
		delete title;
	}
};
class Sales
{
public:

	float* sales = new float[3]; //to store the sale amounts for the last 3 months

	void getData2()
	{
		cout << "Enter the amount of sales for: \n";
		for (int i = 0; i < 3; i++)
		{
			cout << "Month " << i + 1 << ": ";
			cin >> sales[i];
		}
	}
	void putData2()
	{
		cout << "\nSales For: ";
		for (int i = 0; i < 3; i++)
		{
			cout << "\nMonth " << i + 1 << ": ";
			cout << sales[i];
		}
	}
	~Sales()
	{
		delete[] sales;
	}
};
class Book : public Publication, public Sales
{	//child class to both publication and sales
public:

	int pages; //takes input of pages and displays

	Book()
	{
		pages = 0;
	}
	Book(int pages)
	{
		this->pages = pages;
	}
	void getData()
	{
		getData1();
		cout << "Enter the number of pages: ";
		cin >> pages;
		getData2();
	}
	void putData()
	{
		putData1();
		cout << "\nNumber of pages: " << pages;
		putData2();
	}

};

class Tape : public Publication, public Sales
{	//child class to both publication and sales
public:

	float time; //takes duration of time and displays

	Tape()
	{
		time = 0;
	}
	Tape(int time)
	{
		this->time = time;
	}
	void getData()
	{
		cout << "Enter the time in mins of the audio book: ";
		cin >> time;
		getData2();
	}
	void putData()
	{
		cout << "\nDuration of audiobook: " << time;
		putData2();
	}

};

class Disk : public Publication
{
public:

	int option; //can be 1 or 2 for CD or DVD respectively

	Disk()
	{
		option = 0;
	}
	Disk(int option)
	{
		this->option = option;
	}
	void getData()
	{
		cout << "Do you prefer: \n1)CD or 2)DVD\n";
		cin >> option;
	}
	void putData()
	{
		if (option == 1)
		{
			cout << "\nDisk Type: CD";
		}
		else if (option == 2)
		{
			cout << "\nDisk Type: DVD";
		}
		else
			cout << "\nDisk Type: NON";
	}

};

int main()
{
	//creating instances of the child classes
	Book B;
	Tape T;
	Disk D;

	//calling their input functions, Book function will also take in input of publication
	B.getData();
	T.getData();
	D.getData();
	cout << "\n\t\t--------------------------------------------\n";

	//displaying the information
	B.putData();
	T.putData();
	D.putData();
	cout << "\n\t\t--------------------------------------------\n";

	cout << "\n\n";
	system("pause");
	return 0;
}












