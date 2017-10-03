//	Author: Dillon Rowan

//	This program creates an N by N 2d vector. The user inputs the value of
//	N and the vector is then made. Random integers from 10 to 120 are then
//	stored in the vector. The vector is then displayed to the user.
//	The sum, average, smallest number, largest number, even numbers, and odd
//	numbers are all found and displayed to the user. The vector is then
//	sorted in ascending order and is then displayed to the user.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

//function prototypes
int randomAlg();								//generates random ints
void makeVector(vector< vector<int> > &, int);	//stores random ints in vector
void displayNumbers(vector< vector<int> > &);	//prints the 2d vector
int vectorSum(vector< vector<int> > &);			//adds numbers stored in vector
double vectorAvg(vector< vector<int> > &);		//makes average of numbers
int smallestNum(vector< vector<int> > &);		//finds smallest number
int largestNum(vector< vector<int> > &);		//finds largest number
void printEven(vector< vector<int> > &);		//prints all even numbers
void printOdd(vector< vector<int> > &);			//prins all numbers
void printPrimes(vector< vector<int> > &);		//prints all prime numbers
bool isPrime(int);								//checks if passed int is prime
void sortVector(vector< vector<int> > &);		//sorts the vector passed




//=============================================================================
//randomAlg generates a random unbiased integer between 10 and 120
//and then returns the value to the invoking object
//=============================================================================
int randomAlg()
{
    int n = 110 + 1;	//max - min + 1
    int remainder = RAND_MAX % n;
    int x;
    do
    {
        x = rand();
    } while (x >= RAND_MAX - remainder);
    return 10 + x % n;
}
//=============================================================================
//makeVector passes the 2d vector by reference and an integer. The 2d vector
//is then made in to dimension set by n. The size of the 2d vector is n by n.
//=============================================================================
void makeVector(vector< vector<int> > &vec, int n)
{
	for (int i = 0; i < n; i++)
	{
		vector<int> row; // Create an empty row
		for (int j = 0; j < n; j++)
		{
			row.push_back(randomAlg()); // Add an element (column) to the row
		}
		vec.push_back(row); // Add the row to the main vector
	}
}

//=============================================================================
//displayNumbers prints all of the integers stored in the 2d vector
//=============================================================================
void displayNumbers(vector< vector<int> > &vec)
{
	size_t last = vec.size() - 1;

	for(int i = 0; i < vec.size(); ++i)
	{
		for(int j = 0; j < vec.size(); ++j)
		{
			cout << "    " << vec[i][j] << "\t";
			if(j == last)
				cout << endl;
		}
	}
}

//=============================================================================
//vectorSum passes the 2d vector by reference and adds all the stored integers
//together and returns their value
//=============================================================================
int vectorSum(vector< vector<int> > &vec)
{
	int sum = 0;
	for(int i = 0; i < vec.size(); ++i)
	{
		for(int j = 0; j < vec.size(); ++j)
		{
			sum += vec[i][j];
		}
	}
	return sum;
}

//=============================================================================
//vectorAvg calls the vectorSum functions and divides its returned value by
//the size of the vector. This value is the average of the integers stored in
//the 2d array. This average is then returned to the invoking object.
//=============================================================================
double vectorAvg(vector< vector<int> > &vec)
{
	double avg = 0;	//average of vector integers
	double sum = static_cast<double>(vectorSum(vec));
	avg = sum / (vec.size()*vec[0].size());
	return avg;
}

//=============================================================================
//smallestNum traverses the entire 2d vector and finds the smallest integer
//stored inside. This value is then returned to the invoking object
//=============================================================================
int smallestNum(vector< vector<int> > &vec)
{
	int s = vec[0][0];	//assume smallest int is in first element of each
						//row and column

	for(int i = 0; i < vec.size(); ++i)
	{
		for(int j = 0; j < vec.size(); ++j)
		{
			if(vec[i][j] < s)
				s = vec[i][j];
		}
	}
	return s;
}

//=============================================================================
//largestNum traverses the entire 2d vector and finds the largest integer
//stored inside the 2d vector. This value is then returned to the invoking
//object.
//=============================================================================
int largestNum(vector< vector<int> > &vec)
{
	int largest = vec[0][0];	//assume largest int is in first element of each
								//row and column

	for(int i = 0; i < vec.size(); ++i)
	{
		for(int j = 0; j < vec.size(); ++j)
		{
			if(vec[i][j] > largest)
				largest = vec[i][j];
		}
	}
	return largest;
}

//=============================================================================
//printEven traverses the 2d vector and prints any even integer found.
//=============================================================================
void printEven(vector< vector<int> > &vec)
{
	for(int i = 0; i < vec.size(); ++i)
	{
		for(int j = 0; j < vec.size(); ++j)
		{
			if(vec[i][j] % 2 == 0)
				cout << vec[i][j] << " ";
		}
	}
}

//=============================================================================
//printOdd traverses the 2d vector and prints any odd integer found.
//=============================================================================
void printOdd(vector< vector<int> > &vec)
{
	for(int i = 0; i < vec.size(); ++i)
	{
		for(int j = 0; j < vec.size(); ++j)
		{
			if(vec[i][j] % 2 == 1)
				cout << vec[i][j] << " ";
		}
	}
}

//=============================================================================
//printPrimes traverses the 2d vector and prints any prime integer found.
//This function calls isPrime for every integer in the 2d vector in order to
//determine which integers are prime.
//=============================================================================
void printPrimes(vector< vector<int> > &vec)
{
	for(int i = 0; i < vec.size(); ++i)
	{
		for(int j = 0; j < vec.size(); ++j)
		{
			if(isPrime(vec[i][j]) == true)
			{
				cout << vec[i][j] << " ";
			}
		}
	}
}

//=============================================================================
//This function takes an integer as a parameter and checks if it is prime.
//If the integer is prime it returns true. If it is not prime it returns false.
//=============================================================================
bool isPrime(int x)
{

	 if(x == 1 || x == 2)
	   return true;

	 if(x % 2 == 0)
	   return false;

	 for(int i = 2; i <= sqrt(x); i++)
	 {
		if(x % i == 0)
		  return false;
	 }
	 return true;
}

//=============================================================================
//sortVector traverses the 2d vector and sorts each element in ascending order.
//=============================================================================
void sortVector(vector< vector<int> > &vec)
{
	for(int i = 0; i < vec.size(); ++i)
		for(int j = 0; j < vec.size(); ++j)
			for(int i2 = 0; i2 < (vec.size()); i2++)
			{
				for(int j2 = 0; j2 < (vec.size()); j2++)
				{
					if(vec[i][j] < vec[i2][j2])
						swap(vec[i][j], vec[i2][j2]);
				}
			}
}

int main()
{
	int n;
	srand(time(NULL)); // Seed the time
	cout << "This program is written by Dillon Rowan\n\n";
	cout << "This program uses an N by N vector object\n";
	cout << "to store a set of distinct random numbers into an array\n";
	cout << "The numbers are between 10 and 120.\n";
	cout << "The program then displays on the screen\n";
	cout << "the numbers, sum, average, smallest, largest\n";
	cout << "all even numbers, all odd numbers, and all prime numbers\n";
	cout << "in the vector array. Finally, the vector array will be sorted\n";
	cout << "in an ascending order\n\n";
	cout << "Enter the size of the vector array   ";
	cin >> n;
	cout << "\n";

	vector< vector<int> > vec;

	makeVector(vec, n);
	cout << "The " << vec.size() << " x " << vec.size() << " vector array is"
			" \n\n";
	displayNumbers(vec);
	int sum = vectorSum(vec);	//sum of all ints in vector
	cout << "\nThe Sum is:     " << sum << "\n\n";
	double avg = vectorAvg(vec);	//average of all ints in vector
	cout << "The Average is:     " << fixed << setprecision(2) << avg <<
			"\n\n";
	int smallest = smallestNum(vec);
	cout << "The Smallest Number is:     " << smallest << "\n\n";
	int largest = largestNum(vec);	//largest of all ints in vector
	cout << "The Largest Number is:     " << largest << "\n\n";
	cout << "The Even Numbers are:     ";
	printEven(vec);
	cout << "\n\n";
	cout << "The Odd Numbers are:  ";
	printOdd(vec);
	cout << "\n\n";
	cout << "The Prime Numbers are:  ";
	printPrimes(vec);
	cout << "\n\n";
	sortVector(vec);
	cout << "The " << vec.size() << " x " << vec.size() << " sorted vector"
			" array is \n\n";
	displayNumbers(vec);
	cout << "\n\n";
	cout << "Implemented by Dillon Rowan\n";
	return 0;
}


