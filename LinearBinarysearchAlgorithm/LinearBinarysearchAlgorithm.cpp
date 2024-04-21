// Omar Vergara
// 04/20/2024
// Skill Assignment 7

#include <iostream>
#include <cstdlib>

using namespace std;

// Constants
const int SIZE = 20;
const int TARGET = 521;

// Function prototypes
bool linearSearch(int data[], int size, int target, int& comparisons);
bool binarySearch(int data[], int size, int target, int& comparisons);
int bubbleSort(int data[], int size);

int main() {
    // Variables
    int data[SIZE] = { 101, 142, 147, 189, 199, 207, 222, 234, 289, 296, 310, 319, 388, 394, 417, 429, 447, 521, 536, 600 };
    int comparisonsLinear = 0;
    int comparisonsBinary = 0;

    // Bubble Sort the array
    bubbleSort(data, SIZE);

    // Linear Search
    bool foundLinear = linearSearch(data, SIZE, TARGET, comparisonsLinear);

    // Binary Search
    bool foundBinary = binarySearch(data, SIZE, TARGET, comparisonsBinary);

    // Display results
    if (foundLinear) {
        cout << "Linear Search: Value found after " << comparisonsLinear << " comparisons.\n";
    }
    else {
        cout << "Linear Search: Value not found.\n";
    }

    if (foundBinary) {
        cout << "Binary Search: Value found after " << comparisonsBinary << " comparisons.\n";
    }
    else {
        cout << "Binary Search: Value not found.\n";
    }

    return 0;
}

// Linear Search Function 
bool linearSearch(int data[], int size, int target, int& comparisons) {
    comparisons = 0; // Starts the counter
    for (int i = 0; i < size; i++) {  // Loops the array
        comparisons++; // increase counter
        if (data[i] == target) { // if current is equal to target
            return true;
        }
    }
    return false;
}

// Binary Search Function
bool binarySearch(int data[], int size, int target, int& comparisons) {
    comparisons = 0;
    int first = 0;
    int last = size - 1;
    int middle;

    while (first <= last) {
        comparisons++;
        middle = (first + last) / 2;

        if (data[middle] == target) {
            return true;
        }
        else if (data[middle] > target) {
            last = middle - 1;
        }
        else {
            first = middle + 1;
        }
    }
    return false;
}

// Bubble Sort 
int bubbleSort(int data[], int size) {
    bool swap;
    int temp;
    int numSwaps = 0;

    do {
        swap = false;
        for (int count = 0; count < (size - 1); count++) {
            if (data[count] > data[count + 1]) {
                temp = data[count];
                data[count] = data[count + 1];
                data[count + 1] = temp;
                swap = true;
                numSwaps++;
            }
        }
    } while (swap);

    if (numSwaps == 0) {
        return -1;
    }
    else {
        return numSwaps;
    }
}
