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
	for (i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
}
//_________________________________________________________________________________

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
	} 
} 
//_________________________________________________________________________________
//MERGE SORT 
void merge(int array[], int const left, int const mid,
        int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    int *leftArray = new int[subArrayOne],
        *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
        && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void mergePrint(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}
//_________________________________________________________________________________

//MERGE SORT 
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void quickPrint(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

//_________________________________________________________________________________
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

int option, subOption, findItem; 
int numbers[15];
bool input = false, sort = false;
int arr_size = 15;
int array[arr_size];

do
{
cout << "\nPlease enter an option:" << endl;
cout << "\nOption 1: Enter Numbers" << endl;
cout << "Option 2: Auto generate numbers" << endl;
cout << "Option 3: Sort numbers" << endl;
cout << "Option 4: Search for a number" << endl;
cout << "Option 5: Display the current list of numbers" << endl;
cout << "Option 6: Exit the program" << endl;
cout << "Your Choice: Option ";
cin >> option;
cout << endl;
switch(option){

//___________________________________________
	case 1:

	cout << "Please enter your numbers: " << endl;
for(int total = 0; total < 15; total++){
cin >> numbers[total];
}
input = true;
	break;
//___________________________________________	
    case 2:
    
	srand(time(0));
	for (int i = 0; i < arr_size; i++) {
        array[i] = rand() % 15; // Populate array with random numbers
    }
	
	cout << "Here is the randomly generated array: " << endl;
    for(int x = 0; x < 15; x++){
    cout << array[x] << " ";
    }
    cout << endl;
    
	break;
//___________________________________________
	case 3:
	
	if(input == true){
	    
	
	cout << "Choose an option: " << endl; 
	cout << "1. Bubble Sort" << endl; 
	cout << "2. Selection Sort" << endl;
	cout << "3. Merge Sort" << endl;
	cout << "4. Quick Sort" << endl;
	cout << "Your Choice: Option ";
	cin >> subOption; 
	cout << endl;

	if (subOption == 1){//Bubble
	
	int N = sizeof(numbers) / sizeof(numbers[0]);
	bubbleSort(numbers, N);
	cout << "Bubble sorted array: \n";
	bubblePrint(numbers, N);
	sort = true;
	cout << endl;
	}

	else if(subOption == 2){//Selection
	int n = sizeof(numbers) / sizeof(numbers[0]); 

	selectionSort(numbers, n); 
	cout << "Selection sorted array: \n"; 
	selectionPrint(numbers, n); 
	sort = true;
	cout << endl;
} 

	else if(subOption == 3){//Merge
    mergeSort(numbers, 0, 14);
	cout << "Merge sorted array: \n"; 
	mergePrint(numbers, 15); 
	cout << endl;
	sort = true;
} 

	else if(subOption == 4){//Quick
    quickSort(numbers, 0, 14);
	cout << "Quick sorted array: \n"; 
	quickPrint(numbers, 15); 
	cout << endl;
	sort = true;
} 

    else{
    cout << "Invalid choice" << endl;
    }

}

else{
    cout << "No numbers have been inputted." << endl;
}
	break;
//___________________________________________
	case 4:
	
if(sort == true){
	cout << "Please enter a number to search for: " << endl;
	cout << "Chosen Number: ";
    cin >> findItem;
    cout << endl;
 
	int loc;
	 loc = binarySearch(numbers,15,findItem);
    
    if(loc != -1) 
        cout << "Found " << findItem << " at location " << loc << endl;
    else  
        cout << findItem << " was not found." << endl;
}
else{
    cout << "Please select a sorting option first." << endl;
}

	break;
//___________________________________________
	case 5:
	
if(sort == true){	
cout << "Here is your list of sorted numbers: " << endl;
for(int full = 0; full < 15; full++){
cout << numbers[full] << " ";
}
cout << endl;
}

else if(input == true){	
cout << "Here is your list of unsorted numbers: " << endl;
for(int full = 0; full < 15; full++){
cout << numbers[full] << " ";
}
cout << endl;
}

else{
    cout << "No numbers have been inputted." << endl;    
}
	break;
//___________________________________________
	case 6:
cout << "Exiting Program: May you have a good day!" << endl;
	break;

default:
cout << "Invalid choice" << endl;
break;
}

}while(option != 6);



} 






