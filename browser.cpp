#include <iostream>
#include <fstream>
#include "stack.h"
#include "queueADT.h"

using namespace std; 
 

int main(){
string inputp;
int inputd;

stackType<string> pages;
pages.push(inputp); //addQueue
pages.pop(); //delQueue


linkedQueueType<int> downloads;
downloads.addQueue(inputd); //addStack
downloads.deleteQueue(); //delStack


int option;
do{
cout << "\nPlease select one of the following options" << endl;
cout << "Option 1: go forward" << endl; //stack
cout << "Option 2: go back" << endl;	//stack
cout << "Option 3: add file" << endl; //queue
cout << "Option 4: download file" << endl; //queue
cout << "Option 5: size" << endl;
cout << "Option 6: exit" << endl;
cout << "\nSelection: ";

cin >> option;

switch(option){

case 1:
cout << "Which page would you like to visit?" << endl;
cin >> inputp;
pages.push(inputp);
break;

case 2:
cout << "The last webpage you visited was: " << pages.top() << endl;
pages.pop();
break;

case 3: 
cout << "Please enter a file name: "; 
cin >> inputd;
downloads.addQueue(inputd);
break;


case 4:
cout << "The next file set to be downloaded is: " << downloads.front(); 
downloads.deleteQueue();
break;

case 5:
cout << "The queue size is: " << downloads.size();
break;


case 6:
cout << "\nPlease have a great day" << endl;
break;
}



}
while(option != 6);





}

