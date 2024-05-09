#include<iostream>
#include <bits/stdc++.h>
#include <cstdlib> 
#include <ctime>  
using namespace std;

//_________________________________________________________________________________
//BUBBLE SORT 
void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		// If no two elements were swapped
		// by inner loop, then break
		if (swapped == false)
			break;
	}
}

// Function to print an array
void bubblePrint(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << " " << arr[i];
		cout << endl; 
}
//_________________________________________________________________________________
//SELECTION SORT 
void selectionSort(int arr[], int n) 
{ 
	int i, j, min_idx; 

	// One by one move boundary of 
	// unsorted subarray 
	for (i = 0; i < n - 1; i++) { 

		// Find the minimum element in 
		// unsorted array 
		min_idx = i; 
		for (j = i + 1; j < n; j++) { 
			if (arr[j] < arr[min_idx]) 
				min_idx = j; 
		} 

		// Swap the found minimum element 
		// with the first element 
		if (min_idx != i) 
			swap(arr[min_idx], arr[i]); 
	} 
} 

// Function to print an array 
void selectionPrint(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) { 
		cout << arr[i] << " "; 
		cout << endl; 
	} 
} 
//_________________________________________________________________________________\
//BINARY Search

int binarySearch(const int list[], int listLength, int searchItem) 
{
    int first = 0;
    int last = listLength - 1;
    int mid;

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;

        if (list[mid] == searchItem)
            found = true;
        else if (list[mid] > searchItem)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found) 
        return mid;
    else
        return -1;
}//end binarySearch





//___________________________________________________________-
int main(){

int option;
int subOption; 
int numbers[15];
int findItem; 

do
{
cout << "\nPlease enter an option:" << endl;
cout << "\nOption 1: Entering Numbers" << endl;
cout << "Option 2: Sort numbers" << endl;
cout << "Option 3: Search for a number" << endl;
cout << "Option 4: Display the current list of numbers" << endl;
cout << "Option 5: Exit the program" << endl;
cout << "Option: ";
cin >> option;

switch(option){

//___________________________________________
	case 1:

	cout << "Please enter your numbers: " << endl;
for(int total = 0; total < 15; total++){
cin >> numbers[total];
}

	break;




//___________________________________________
	case 2:
	cout << "Choose an option: " << endl; 
	cout << "1. Bubble Sort" << endl; 
	cout << "2. Selection Sort" << endl; 
	cin >> subOption; 

	if (subOption == 1){//Bubble
	
	int N = sizeof(numbers) / sizeof(numbers[0]);
	bubbleSort(numbers, N);
	cout << "Sorted array: \n";
	bubblePrint(numbers, N);
	}

	else if(subOption == 2){//Selection
	int n = sizeof(numbers) / sizeof(numbers[0]); 

	// Function Call 
	selectionSort(numbers, n); 
	cout << "Sorted array: \n"; 
	selectionPrint(numbers, n); 
} 

	break;


//___________________________________________
	case 3:
	cout << "Please enter a number to search for: " << endl;
cin >> findItem;
 
	int loc;
	
	 loc = binarySearch(numbers,15,findItem);
    
    if(loc != -1) 
        cout << "Found " << findItem << " at location " << loc << endl;
    else  
        cout << findItem << " not found" << endl;
    
    findItem = 5;
    loc = binarySearch(numbers,15,findItem);

    if(loc != -1) 
        cout << "Found " << findItem << "at location " << loc << endl;
    else  
        cout << findItem << " not found" << endl;

	break;



//___________________________________________
	case 4:
cout << "Here is your list of numbers: " << endl;
for(int full = 0; full < 15; full++){
cout << numbers[full] << " ";
}


	break;




//___________________________________________
	case 5:
cout << "Exiting Program: May you have a good day!" << endl;
	break;


}

}while(option != 5);











}