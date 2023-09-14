#include <iostream>
#include <fstream>
using namespace std;
int main() {
//Formatted report version 


ifstream triathlon;
//f = first name
string f1, f2, f3, f4, f5, f6;
// l = last name
string l1, l2, l3, l4, l5, l6;
// n = bib number
int n1, n2, n3, n4, n5, n6;
// r = racing time
int r1, r2, r3, r4, r5, r6; 
// s = swimming time
int s1, s2, s3, s4, s5, s6;
// b = biking time
int b1, b2, b3, b4, b5, b6; 
// t = total time
int t1, t2, t3, t4, t5, t6;
//m = message displayed 
string m1, m2, m3, m4, m5, m6;

//Connects to time.dat file
triathlon.open("times.dat");
triathlon >> f1 >> l1 >> n1 >> r1 >> s1 >> b1;
triathlon >> f2 >> l2 >> n2 >> r2 >> s2 >> b2;
triathlon >> f3 >> l3 >> n3 >> r3 >> s3 >> b3;
triathlon >> f4 >> l4 >> n4 >> r4 >> s4 >> b4;
triathlon >> f5 >> l5 >> n5 >> r5 >> s5 >> b5;
triathlon >> f6 >> l6 >> n6 >> r6 >> s6 >> b6;

t1 = r1 + s1 + b1;
t2 = r2 + s2 + b2;
t3 = r3 + s3 + b3;
t4 = r4 + s4 + b4;
t5 = r5 + s5 + b5;
t6 = r6 + s6 + b6;

if (t1 < 100)
m1 = "Excellent job";
else if (t1 >=100 && t1 < 120)
m1 = "Great job";
else if (t1 >= 120)
m1 = "Good job";

if (t2 < 100)
m2 = "Excellent job";
else if (t2 >=100 && t2 < 120)
m2 = "Great job";
else if (t2 >= 120)
m2 = "Good job";

if (t3 < 100)
m3 = "Excellent job";
else if (t3 >=100 && t3 < 120)
m3 = "Great job";
else if (t3 >= 120)
m3 = "Good job";

if (t4 < 100)
m4 = "Excellent job";
else if (t4 >=100 && t4 < 120)
m4 = "Great job";
else if (t4 >= 120)
m4 = "Good job";

if (t5 < 100)
m5 = "Excellent job";
else if (t5 >=100 && t5 < 120)
m5 = "Great job";
else if (t5 >= 120)
m5 = "Good job";

if (t6 < 100)
m6 = "Excellent job";
else if (t6 >=100 && t6 < 120)
m6 = "Great job";
else if (t6 >= 120)
m6 = "Good job";

//a = average total time for race
int a = (t1 + t2 + t3 + t4 + t5 + t6) / 6;

cout << "Athlete Name: " << f1 << " " << l1 << "\nBib number: " << n1 << "\nRunning time: " << r1 << " minutes \nSwimming time: " << s1 << " minutes \nBiking time: " << b1 << " minutes" << "\nTotal time: " << t1 << " minutes\n" << m1 << endl;

cout << "\nAthlete name: " << f2 << " " << l2 << "\nBib number: " << n2 << "\nRunning time: " << r2 << " minutes \nSwimming time: " << s2 << " minutes \nBiking time: " << b2 << " minutes" << "\nTotal time: " << t2 << " minutes\n" << m2 << endl;

cout << "\nAthlete name: " << f3 << " " << l3 << "\nBib number: " << n3 << "\nRunning time: " << r3 << " minutes \nSwimming time: " << s3 << " minutes \nBiking time: " << b3 << " minutes" << "\nTotal time: " << t3 << " minutes\n" << m3 << endl;

cout << "\nAthlete name: " << f4 << " " << l4 << "\nBib number: " << n4 << "\nRunning time: " << r4 << " minutes \nSwimming time: " << s4 << " minutes \nBiking time: " << b4 << " minutes" << "\nTotal time: " << t4 << " minutes\n" << m4 << endl;

cout << "\nAthlete name: " << f5 << " " << l5 << "\nBib number: " << n5 << "\nRunning time: " << r5 << " minutes \nSwimming time: " << s5 << " minutes \nBiking time: " << b5 << " minutes" << "\nTotal time: " << t5 << " minutes\n" << m5  << endl;

cout << "\nAthlete name: " << f6 << " " << l6 << "\nBib number: " << n6 << "\nRunning time: " << r6 << " minutes \nSwimming time: " << s6 << " minutes \nBiking time: " << b6 << " minutes" << "\nTotal time: " << t6 << " minutes\n" << m6 << endl;

cout << "\nThe average total time for the race is: " << a << " minutes" << endl;
triathlon.close();
}