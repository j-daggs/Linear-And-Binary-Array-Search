// CS111Project3-Daggs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

const int SIZE = 2000;
#define NOT_FOUND -1
typedef int Data[SIZE];

//postcondition: each element is initialized with its index
void initializeArray(Data array, int size);
//precondition: d[] contains the initialized array to be searched, size contains the array size, target contains the target-value to be searched for, count is initialized to zero
//postcondition: the index of the target is returned, count now contains the number of swaps
int linearSearch(int d[], const int size, int target, int &count);
//precondition: d[] contains the initialized array to be searched, size contains the array size, target contains the target-value to be searched for, count is initialized to zero
//postcondition: the index of the target is returned, count now contains the number of swaps
int binarySearch(int d[], const int size, int target, int &count);


int main(void) {

	Data a;
	srand(time(0));
	initializeArray(a, SIZE);
	int target = 0;
	ofstream outFile;

	outFile.open("runData.txt");
	if (outFile.fail()) {
		cout << "Couldnt open data file\n";
		return 0;
	}

	int workingArraySize = 10;
	for (; workingArraySize < SIZE; workingArraySize += 10) {
		target = rand() % workingArraySize;
		cout << "Target " << target << " ";
		int countLinear = 0;
		int b = linearSearch(a, workingArraySize, target, countLinear);
		int countBinary = 0;
		b = binarySearch(a, workingArraySize, target, countBinary);
		
		cout << "Array Size: " << workingArraySize << " Number of Comparisons (Linear): " << countLinear << " Number of Comparisons (Binary): " << countBinary << "\n";
		outFile << workingArraySize << " " << countLinear << " " << countBinary << "\n";
	}
	outFile.close();
	return 0;
}

void initializeArray(Data array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = i;
	}
}

int linearSearch(int d[], const int size, int target, int &count) {
	for (int i = 0; i < size; i++) {
		count++;
		if (d[i] == target)
			return i;
	}
	return NOT_FOUND;
}

int binarySearch(int d[], const int size, int target, int &count) {
	int left = 0;
	int right = size-1;
	while (right >= left) {
		int middle = (left + right) / 2;
		count++;
		if (d[middle] == target)
			return middle;
		count++;
		if (target < middle)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return NOT_FOUND;
}
