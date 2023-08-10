#include <iostream>
using namespace std;

class Time
{
private:

	int hours, minutes, seconds;

public:

	//default constructor
	Time()
	{
		hours = minutes = seconds = 0;
	}
	//parameterized constructor
	Time(int hour, int min, int sec)
	{
		hours = hour;
		minutes = min;
		seconds = sec;
	}
	//--------------------------------------------------------------------------------------------------------------------------
		//getters
	int getHour()
	{
		return hours;
	}
	int getMinute()
	{
		return minutes;
	}
	int getSecond()
	{
		return seconds;
	}
	//--------------------------------------------------------------------------------------------------------------------------
	int check() //to check validity and then convert the time into a 12 hour format
	{
		//checking if input is valid
		//if not, it will end program
		if (hours < 0 || minutes < 0 || seconds < 0)
		{
			cout << "\nInvalid Input\n\n";
			return 0;	//sends this zero to main
		}

		int temp1 = 0;
		int temp2 = 0;

		//start checking from seconds
		if (seconds >= 60)
		{
			temp1 = seconds / 60;
			temp2 = seconds % 60;
			minutes = minutes + temp1;
			seconds = temp2;
		}

		if (minutes >= 60)
		{
			temp1 = minutes / 60;
			temp2 = minutes % 60;
			hours = hours + temp1;
			minutes = temp2;
		}

		if (hours > 12)
		{
			hours = hours % 12;
		}
	}
	void display()
	{
		cout << hours << " : " << minutes << " : " << seconds << "\n";
	}
	//--------------------------------------------------------------------------------------------------------------------------
	Time operator++() //pre-increment operator
	{
		Time temp;
		temp.hours = hours + 1;
		temp.minutes = minutes + 1;
		temp.seconds = seconds + 1;

		//we need to check if its in the correct form i.e. doesnt exceed 60+ mins or seconds OR 24+hrs
		int temp1 = 0;
		int temp2 = 0;

		if (temp.seconds >= 60)
		{
			temp1 = temp.seconds / 60;
			temp2 = temp.seconds % 60;
			temp.minutes = temp.minutes + temp1;
			temp.seconds = temp2;
		}

		if (temp.minutes >= 60)
		{
			temp1 = temp.minutes / 60;
			temp2 = temp.minutes % 60;
			temp.hours = temp.hours + temp1;
			temp.minutes = temp2;
		}

		if (temp.hours > 12)
		{
			temp.hours = temp.hours % 12;
		}

		return temp;
	}
	Time operator--() //pre-decrement operator
	{
		Time temp;
		temp.hours = hours - 1;
		temp.minutes = minutes - 1;
		temp.seconds = seconds - 1;

		//to check if it doesnt give negative answers
		if (temp.seconds < 0) //if so we take a 60 second carry i.e. 1 minute
		{
			while (temp.seconds < 0)
			{
				temp.minutes = temp.minutes - 1;
				temp.seconds = temp.seconds + 60;
			}
		}
		if (temp.minutes < 0) //if true we add 60 minutes, from 1 hour
		{
			while (temp.minutes < 0)
			{
				temp.hours = temp.hours - 1;
				temp.minutes = temp.minutes + 60;
			}
		}
		if (temp.hours < 0)
		{
			while (temp.hours < 0)
			{
				temp.hours = temp.hours + 12;
			}
		}
		return temp;
	}
	Time operator++(int) //post-increment operator
	{
		Time temp;
		temp.hours = hours + 1;
		temp.minutes = minutes + 1;
		temp.seconds = seconds + 1;

		//checking 
		int temp1 = 0;
		int temp2 = 0;

		if (temp.seconds >= 60)
		{
			temp1 = temp.seconds / 60;
			temp2 = temp.seconds % 60;
			temp.minutes = temp.minutes + temp1;
			temp.seconds = temp2;
		}

		if (temp.minutes >= 60)
		{
			temp1 = temp.minutes / 60;
			temp2 = temp.minutes % 60;
			temp.hours = temp.hours + temp1;
			temp.minutes = temp2;
		}

		if (temp.hours > 12)
		{
			temp.hours = temp.hours % 12;
		}

		return temp;
	}
	Time operator--(int) //post-decrement operator
	{
		Time temp;
		temp.hours = hours - 1;
		temp.minutes = minutes - 1;
		temp.seconds = seconds - 1;

		//checking
		if (temp.seconds < 0)
		{
			while (temp.seconds < 0)
			{
				temp.minutes = temp.minutes - 1;
				temp.seconds = temp.seconds + 60;
			}
		}
		if (temp.minutes < 0)
		{
			while (temp.minutes < 0)
			{
				temp.hours = temp.hours - 1;
				temp.minutes = temp.minutes + 60;
			}
		}
		if (temp.hours < 0)
		{
			while (temp.hours < 0)
			{
				temp.hours = temp.hours + 12;
			}
		}
		return temp;
	}

	Time& operator=(const Time& obj) //assignment operator
	{
		hours = obj.hours;
		minutes = obj.minutes;
		seconds = obj.seconds;

		return *this;
	}

	Time operator-(const Time& obj)
	{
		//this is after it has been confirmed that LHS hours are greater than the RHS hours
		//however minutes and seconds can vary 

		Time temp;

		//checking if the seconds of the LHS are smaller and if so, then we take carry
		if (seconds < obj.seconds)
		{
			minutes--;
			seconds = seconds + 60;
			temp.seconds = seconds - obj.seconds;
		}
		else
			temp.seconds = seconds - obj.seconds;

		//checking if the minutes of the LHS are smaller and if so, then we take carry
		if (minutes < obj.minutes)
		{
			hours--;
			minutes = minutes + 60;
			temp.minutes = minutes - obj.minutes;
		}
		else
			temp.minutes = minutes - obj.minutes;

		//finally subtracting the hours
		temp.hours = hours - obj.hours;

		return temp;
	}
	Time& operator*(float x) //multiplication overload
	{
		//	Time temp;
		hours = hours * x;
		minutes = minutes * x;
		seconds = seconds * x;

		return *this;
	}

};

int main()
{
	//input
	int hour, min, sec;
	cout << "Enter hours: ";
	cin >> hour;
	cout << "Enter minutes: ";
	cin >> min;
	cout << "Enter seconds: ";
	cin >> sec;

	Time t1(hour, min, sec);
	t1.check(); //corrects the time, maintaining a 12 hr standard format
	cout << "\nEntered Time = ";
	t1.display();

	//--------------------------------------------------------------------------------------------------------------------------
	cout << "\n\t\t--------------------------------------------\n";

	//Performing increment and decrement functions
	Time result;
	result = t1++;

	//post operations
	cout << "\npost ++ operator overload= ";
	result.display();

	result = t1--;

	cout << "post -- operator overload= ";
	result.display();

	result = ++t1;

	//pre operations
	cout << "pre ++ operator overload = ";
	result.display();

	result = --t1;

	cout << "pre -- operator overload = ";
	result.display();

	//--------------------------------------------------------------------------------------------------------------------------
	cout << "\n\t\t--------------------------------------------\n";

	//input for two times to subtract them all while checking if they are valid + converting them to the right format

	cout << "\nFor Time 1:\n"; //Time 1
	cout << "Enter hours: ";
	cin >> hour;
	cout << "Enter minutes: ";
	cin >> min;
	cout << "Enter seconds: ";
	cin >> sec;

	Time time1(hour, min, sec);
	if (!time1.check()) //if invalid input, it will end program
	{
		system("pause");
		return 0;
	}

	cout << "\nFor Time 2:\n"; //Time 2
	cout << "Enter hours: ";
	cin >> hour;
	cout << "Enter minutes: ";
	cin >> min;
	cout << "Enter seconds: ";
	cin >> sec;

	Time time2(hour, min, sec);
	if (!time2.check())
	{
		system("pause");
		return 0;
	}

	//now checking which time is bigger

	if (time1.getHour() > time2.getHour())
	{
		cout << "\nSubtracting time 2 from time 1 = ";
		result = time1 - time2;
	}
	else
	{
		cout << "\nSubtracting time 1 from time 2 = ";
		result = time2 - time1;
	}

	result.display();

	//--------------------------------------------------------------------------------------------------------------------------
	cout << "\n\t\t--------------------------------------------\n";

	//for multipying time by a float value given by the user	
	float value;

	cout << "\nFor Time 3:\n"; //Time 3
	cout << "Enter hours: ";
	cin >> hour;
	cout << "Enter minutes: ";
	cin >> min;
	cout << "Enter seconds: ";
	cin >> sec;

	Time time3(hour, min, sec);

	if (!time3.check()) //checking validity of data
	{
		system("pause");
		return 0;
	}

	cout << "\nEnter the value to multiply time with: ";
	cin >> value;

	cout << "\nMultiplying time with " << value << " = ";

	//overloading * operator
	result = time3 * value;
	result.check();
	result.display();

	cout << "\n\t\t--------------------------------------------\n";
	cout << "\n\n";
	system("pause");
	return 0;
}
