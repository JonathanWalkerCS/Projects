#include <iostream>
#include <fstream>
using namespace std;

float highscore(string s, float testa[], float testb[], float testc[])
{
float highesta = testa[0];
float highestb = testb[0]; 
float highestc = testc[0];


	if(s == "1")
	{
		for(int y = 1; y <= 99; y++) 
		{
			if(testa[y] > highesta)
			{		
			highesta = testa[y]; 
			}
		}
	return highesta; 
	}

	if(s == "2")
	{
		for(int y = 1; y <= 99; y++) 
		{
			if(testb[y] > highestb)
			{		
			highestb = testb[y]; 
			}
		}
	return highestb; 
	}

	if(s == "3")
	{
		for(int y = 1; y <= 99; y++) 
		{
			if(testc[y] > highestc)
			{		
			highestc = testc[y]; 
			}
		}
	return highestc; 
	}

}

float lowscore(string s, float testa[], float testb[], float testc[])
{
float lowesta = testa[0];
float lowestb = testb[0]; 
float lowestc = testc[0];

	if(s == "1")
	{
		for(int y = 1; y <= 99; y++) 
		{
			if(testa[y] < lowesta && testa[y] != 0 && testa[y] < testa[y-1])
			{		
			lowesta = testa[y]; 
			}
		}
	return lowesta; 
	}


	if(s == "2")
	{
		for(int y = 1; y <= 99; y++) 
		{
			if(testb[y] < lowestb && testb[y] != 0 && testb[y] < testb[y-1])
			{		
			lowestb = testb[y]; 
			}
		}
	return lowestb; 
	}


	if(s == "3")
	{
		for(int y = 1; y <= 99; y++) 
		{
			if(testc[y] < lowestc && testc[y] != 0 && testc[y] < testc[y-1])
			{		
			lowestc = testc[y]; 
			}
		}
	return lowestc; 
	}
}


string studenthigh(string s, string name[], float testa[], float testb[], float testc[])
{
float highesta = testa[0];
float highestb = testb[0]; 
float highestc = testc[0];
int z = 0;


for(int y = 1; y <= 99; y++) 
{

		if(s == "1")
		{
			if(testa[y] > testa[y-1] && testa[y] > highesta)
			{		
			highesta = testa[y];
			z=y;
			}
		} 
		
		if(s == "2")
		{
			if(testb[y] > testb[y-1] && testb[y] > highestb)
			{		
			highestb = testb[y];
			z=y;
			}
		} 
		
		if(s == "3")
		{
			if(testc[y] > testc[y-1] && testc[y] > highestc)
			{		
			highestc = testc[y];
			z=y;
			}
		} 
}

return name[z];

}


string studentlow(string s, string name[], float testa[], float testb[], float testc[])
{
float lowesta = testa[0];
float lowestb = testb[0]; 
float lowestc = testc[0];
int z = 0;


	if(s == "1")
	{
		for(int y = 1; y <= 99; y++) 
		{
			if(testa[y] < lowesta && testa[y] != 0)
			{		
			lowesta = testa[y]; 
			z = y;
			}
		}
	return name[z]; 
	}


	if(s == "2")
	{
		for(int y = 1; y <= 99; y++) 
		{
			if(testb[y] < lowestb && testb[y] != 0)
			{		
			lowestb = testb[y]; 
			z = y;
			}
		}
	return name[z]; 
	}

	if(s == "3")
	{
		for(int y = 1; y <= 99; y++) 
		{
			if(testc[y] < lowestc && testc[y] != 0)
			{		
			lowestc = testc[y]; 
			z = y;
			}
		}
	return name[z]; 
	}

}



float avgscore(string s, float testa[], float testb[], float testc[])
{
float suma = testa[0];
float sumb = testb[0]; 
float sumc = testc[0];
float avg; 
int z = 1;

	if(s == "1")
	{
		for(int y = 1; y <= 99; y++) 
		{
			if(testa[y] > 0)
			{
			suma += testa[y];	
			z++; 
			}
		}
	return suma / z;
	}


	if(s == "2")
	{
		for(int y = 1; y <= 99; y++) 
		{
			if(testb[y] > 0)
			{
			sumb += testb[y];	
			z++; 
			}
		}
	return sumb / z;
	}


	if(s == "3")
	{
		for(int y = 1; y <= 99; y++) 
		{
			if(testc[y] > 0)
			{
			++z;			
			sumc += testc[y];
			}
		}
	return sumc / z;
	}

}




float avgstudent(int x, float testa[], float testb[], float testc[])
{
float sums = testa[x] + testb[x] + testc[x];
float avgs = sums / 3;
return avgs;
}



int main()
{
string s; 
int r;
string option, account; 
string name[100];
float testa[100] = {0};
float testb[100] = {0};
float testc[100] = {0};

ifstream infile;
string fileName;
cout << "Please enter the input file name: ";
cin >> fileName; 

infile.open(fileName.c_str());

for(int x = 0; x <= 99; x++) 
{	
infile >> name[x];
infile >> testa[x];
infile >> testb[x];
infile >> testc[x];
}

do
{ 
cout << "\n\nOptions: " << endl;
cout << "1. Highest score on an exam" << endl;
cout << "2. Lowest score on an exam" << endl;
cout << "3. Student with the highest score on an exam" << endl;
cout << "4. Student with the lowest score on an exam" << endl;
cout << "5. Average score on an exam" << endl;
cout << "6. Average score for a student" << endl;
cout << "\n7. Quit " << endl;

cin >> option;


	if(option == "1")
	{
	cout << "Please enter which exam you want to find the highest score of: " << endl;
	cin >> s; 

		if(s == "1")
		{
		cout << "The highest score for exam 1 is: " << highscore(s, testa, testb, testc) << endl;	
		}

    else if(s == "2")
		{
		cout << "The highest score for exam 2 is: " << highscore(s, testa, testb, testc) << endl;	
		}

		else if(s == "3")
		{
		cout << "The highest score for exam 3 is: " << highscore(s, testa, testb, testc) << endl;	
		}

		else
		cout << "An error has occurred please try again" << endl;
	}



		else if(option == "2")
	{
	cout << "Please enter which exam you want to find the lowest score of: " << endl;
	cin >> s; 

		if(s == "1")
		{
		cout << "The lowest score for exam 1 is: " << lowscore(s, testa, testb, testc) << endl;	
		}

    else if(s == "2")
		{
		cout << "The lowest score for exam 2 is: " << lowscore(s, testa, testb, testc) << endl;	
		}

		else if(s == "3")
		{
		cout << "The lowest score for exam 3 is: " << lowscore(s, testa, testb, testc) << endl;	
		}

		else
		cout << "An error has occurred please try again" << endl;
	}



		else if(option == "3")
	{
	cout << "Please enter an exam number to find which student scored the highest on it: " << endl;
	cin >> s; 

		if(s == "1")
		{
		cout << "The student with the highest score on exam 1 is: " << studenthigh(s, name, testa, testb, testc) << endl;
		}

    else if(s == "2")
		{
		cout << "The student with the highest score on exam 2 is: " << studenthigh(s, name, testa, testb, testc) << endl;
		}

		else if(s == "3")
		{
	cout << "The student with the highest score on exam 3 is: " << studenthigh(s, name, testa, testb, testc) << endl;
		}

		else
		cout << "An error has occurred please try again" << endl;
	}



		else if(option == "4")
	{
	cout << "Please enter an exam number to find which student scored the lowest on it: " << endl;
	cin >> s; 

		if(s == "1")
		{
		cout << "The student with the lowest score on exam 1 is: " << studentlow(s, name, testa, testb, testc) << endl;
		}

    else if(s == "2")
		{
		cout << "The student with the lowest score on exam 2 is: " << studentlow(s, name, testa, testb, testc) << endl;
		}

		else if(s == "3")
		{
	cout << "The student with the lowest score on exam 3 is: " << studentlow(s, name, testa, testb, testc) << endl;
		}

		else
		cout << "An error has occurred please try again" << endl;
	}



		else if(option == "5")
	{
	cout << "Please enter which exam you want to find the average of: " << endl;
	cin >> s; 

		if(s == "1")
		{
		cout << "The average score of exam 1 is: " << avgscore(s, testa, testb, testc) << endl;
		}

    else if(s == "2")
		{
		cout << "The average score of exam 2 is: " << avgscore(s, testa, testb, testc) << endl;
		}

		else if(s == "3")
		{
		cout << "The average score of exam 3 is: " << avgscore(s, testa, testb, testc) << endl;
		}

		else 
		cout << "An error has occurred please try again" << endl;
	}


		else if(option == "6")
	{
	cout << "Please enter a student's number to find their average score: " << endl;
	cin >> r;

		if(r <= 99)
		{
		cout << "The average score of " << name[r] << " is: " << avgstudent(r, testa, testb, testc) << endl;
		}
		
		else 
		cout << "An error has occurred please try again" << endl;
	}
}
while(option != "7");
}