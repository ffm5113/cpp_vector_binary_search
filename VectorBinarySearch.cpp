// Source(s) of logic assistance:  
// Gaddis, T. (2018). Starting out with C++:
// From control structures through objects. Pearson. 

#include <iostream> // To use cin/cout
#include <iomanip>  // To access setw, setprecision for output width
#include <string>   // To implement to_string, getline functions
#include <ctime>    // To access random number generator
#include <vector>   // To use vector (dynamically sized form of array)
using namespace std;

// Global Constant Initialization
const string TITLE = "Vector Binary Search Program";
const string AUTHOR_LINE = "By Forrest Moulin";
const int VECTOR_SIZE = 5000;

// Function prototypes to notify compiler
// Use vector reference parameter to update main vector val
void fillVector(vector<int>& passedVector);
void sortVector(vector<int>& passedVector);
void swapValues(int& a, int& b);
void printVector(vector<int> passedVector);

int getSmallestVal(vector<int> passedVector);
int getLargestVal(vector<int> passedVector);

int getOddCount(vector<int> passedVector);
int getEvenCount(vector<int> passedVector);

int getSumOfValues(vector<int> passedVector);
double getAvgValue(vector<int> passedVector);

// Serial search example that exits on match
// *Shown as example but not implemented*
int searchForInt(vector<int> passedVector);
// Binary search for greatest efficiency 
int binarySearchForInt(vector<int> passedVector);

int main()
{
	// Seed random number generator using current time
	srand(time(NULL));

	// Dynamic Variable Initialization
	int smallestVal, largestVal, oddCount, evenCount,
		sumOfValues, binarySearchIndex;
	double avgValue;
	vector<int> mainVector;

	// Program Logic
	cout << fixed << setprecision(2) << TITLE << endl
		<< AUTHOR_LINE << endl << endl;

	fillVector(mainVector);
	cout << "Sorted Vector:" << endl;
	sortVector(mainVector);
	printVector(mainVector);

	// User main vector object as param for functions
	smallestVal = getSmallestVal(mainVector);
	largestVal = getLargestVal(mainVector);
	oddCount = getOddCount(mainVector);
	evenCount = getEvenCount(mainVector);
	sumOfValues = getSumOfValues(mainVector);
	avgValue = getAvgValue(mainVector);
	binarySearchIndex = binarySearchForInt(mainVector);
}
// Function declarations
void fillVector(vector<int>& passedVector)
{	// Int reused to fill vector
	int randomInt;
	for (int i = 0; i < VECTOR_SIZE; i++)
	{	// New random number each iteration
		randomInt = rand();
		// Fill the passed vector, which
		// updates values in mainVector
		passedVector.push_back(randomInt);
	}
}
void printVector(vector<int> passedVector)
{
	string vectorAsStr = "";
	for (int i = 0; i < VECTOR_SIZE; i++)
	{
		// Convert vector int value to string and 
		// add it to the vector string
		vectorAsStr += to_string(passedVector[i]) + " ";
		// Skip to new line after 10th number
		if ((i + 1) % 10 == 0)
		{
			vectorAsStr += "\n";
		}
	}
	cout << vectorAsStr << endl;
}
int getSmallestVal(vector<int> passedVector)
{
	int smallestVal;
	for (int i = 0; i < VECTOR_SIZE; i++)
	{
		if (i == 0)
		{	// Set first value as smallest
			smallestVal = passedVector[i];
		}   
		// Compare to determine smallest value
		else if (passedVector[i] < smallestVal)
		{
			smallestVal = passedVector[i];
		}
	}
	cout << left << setw(27) 
		<< "Smallest integer value: " << right << setw(10) 
		<< smallestVal << endl;
	return smallestVal;
}
int getLargestVal(vector<int> passedVector)
{
	int largestVal;
	for (int i = 0; i < VECTOR_SIZE; i++)
	{
		if (i == 0)
		{	// Set first value as largest
			largestVal = passedVector[i];
		}
		// Compare to determine largest value
		else if (passedVector[i] > largestVal)
		{
			largestVal = passedVector[i];
		}
	}
	cout << left << setw(27) 
		<< "Largest integer value:" << right << setw(10) 
		<< largestVal << endl;
	return largestVal;
}
int getOddCount(vector<int> passedVector)
{
	int oddCount = 0;
	for (int i = 0; i < VECTOR_SIZE; i++)
	{	// If number is odd (dividing by 2 has a remainder)
		if (passedVector[i] % 2 == 1)
		{
			oddCount++;
		}
	}
	cout << left << setw(27) 
		<< "Number of odd integers:" << right << setw(10) 
		<< oddCount << endl;
	return oddCount;
}
int getEvenCount(vector<int> passedVector)
{
	int evenCount = 0;
	for (int i = 0; i < VECTOR_SIZE; i++)
	{	// If number is even (dividing by 2 has no remainder)
		if (passedVector[i] % 2 == 0)
		{	
			evenCount++;
		}
	}
	cout << left << setw(27) 
		<< "Number of even integers:" << right << setw(10) 
		<< evenCount << endl;
	return evenCount;
}
int getSumOfValues(vector<int> passedVector)
{
	int sumOfValues = 0;
	for (int i = 0; i < VECTOR_SIZE; i++)
	{	// Add to sum on each iteration
		sumOfValues += passedVector[i];
	}
	cout << "Sum of all integer values: " << right << setw(10) 
		<< sumOfValues << endl;
	return sumOfValues;
}
double getAvgValue(vector<int> passedVector)
{
	double avgValue;
	int sumOfValues = 0;
	for (int i = 0; i < VECTOR_SIZE; i++)
	{
		sumOfValues += passedVector[i];
	} // Calc avg by diving sum by 5000
	avgValue = 1.0 * sumOfValues / VECTOR_SIZE;
	cout << left << setw(27)
		<< "Average integer value: " << right << setw(10)
		<< avgValue << endl << endl;
	return avgValue;
}
int searchForInt(vector<int> passedVector)
{
	int searchInt;
	bool intFound = false;
	cout << "Please enter an integer to search for:" << endl;
	cin >> searchInt;
	cout << endl;

	for (int i = 0; i < VECTOR_SIZE; i++)
	{
		if (passedVector[i] == searchInt)
		{
			cout << searchInt << " was found in the vector at"
				<< " position " << i + 1 << "." << endl;
			intFound = true;
			// Exit the loop when found
			break;
		}
	}
	// If value not found, notify user
	if (intFound == false)
	{
		cout << searchInt << " was not found in the vector."
			<< endl;
		searchInt = -1;
	}
	return searchInt;
}

// Binary search can be completed for array/vector values that are in order
int binarySearchForInt(vector<int> passedVector)
{
	int searchInt, startingIndex = 0, middleIndex, lastIndex = VECTOR_SIZE - 1, position = -1;
	bool foundVal = false;
	cout << "Please enter an integer to search for:" << endl;
	cin >> searchInt;
	cout << endl;

	while (foundVal == false && startingIndex <= lastIndex)
	{	
		middleIndex = (startingIndex + lastIndex) / 2;
		// Searched val equals midpoint val
		if (passedVector[middleIndex] == searchInt)
		{
			foundVal = true;
			position = middleIndex;
		}
		// Searched val is less than midpoint val
		else if (passedVector[middleIndex] > searchInt)
		{
			lastIndex = middleIndex - 1;
		}
		// Searched val is greater than midpoint val
		else
		{
			startingIndex = middleIndex + 1;
		}
	}
	if (position == -1)
	{
		cout << searchInt << " was not found in the vector."
			<< endl;
	}
	else
	{
		cout << searchInt << " was found in the vector at "
			<< "position " << position + 1 << "." << endl;
	}
	return position;
}
void sortVector(vector<int>& passedVector)
{
	bool swapped = true;
	int i, numLength = passedVector.size();

	int d = numLength;
	// Loop while swapped bool is true or d greater than 1
	while (swapped || (d > 1))
	{
		// Reset bool before checking for swap
		swapped = false;  
		d = (d + 1) / 2;
		for (i = 0; i < (numLength - d); i++)
		{	
			if (passedVector[i + d] < passedVector[i])
			{
				swapValues(passedVector[i], passedVector[i + d]);
				// Use bool to indicate swap
				swapped = true;     
			}
		}
	}
}
void swapValues(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
/*
* CONSOLE OUTPUT # 1 - INT NOT FOUND
* Vector Binary Search Program
* By Forrest Moulin
* 
* Sorted Vector:
* 4 12 15 30 32 35 38 42 49 61
* 62 65 72 75 91 95 96 106 106 111
* 116 124 127 133 137 139 146 149 166 171
* ...
* 
* Smallest integer value:             4
* Largest integer value:          32757
* Number of odd integers:          2525
* Number of even integers:         2475
* Sum of all integer values:   82350033
* Average integer value:       16470.01
*
* Please enter an integer to search for:
* 2
*
* 2 was not found in the vector.
* 
* CONSOLE OUTPUT # 2 - INT FOUND
* Vector Binary Search Program
* By Forrest Moulin
* 
* Sorted Vector:
* 1 3 6 21 29 42 48 50 55 62
* 65 68 87 98 113 121 123 123 130 130
* 132 133 146 147 175 191 195 195 202 215
* ...
* 
* Smallest integer value:             1
* Largest integer value:          32766
* Number of odd integers:          2526
* Number of even integers:         2474
* Sum of all integer values:   82097212
* Average integer value:       16419.44
*
* Please enter an integer to search for:
* 50
*
* 50 was found in the vector at position 8.
*/
