/*
 * main.cpp
 *
 *  Created on: Sep 15, 2017
 *      Author: ryan
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

int hexToBase10(string x);

int main(){
	string hex;
	cout << "32-bit Hex to Base-10" << endl;
	cout << "Please enter a 32-bit hexadecimal number:" << endl;
	cin >> hex;
	cout << "Base-10: " << hexToBase10(hex) << endl;

	return 0;
}

int hexToBase10(string x){
	int result = 0;

	for(int i=0;i<x.length();i++){
		switch(x[i]){
		case '0':
			break;
		case '1':
			result += (int)(pow(16,x.length()-i-1) + 0.5);
			break;
		case '2':
			result += 2 * (int)(pow(16,x.length()-i-1) + 0.5);
			break;
		case '3':
			result += 3 * (int)(pow(16,x.length()-i-1) + 0.5);
			break;
		case '4':
			result += 4 * (int)(pow(16,x.length()-i-1) + 0.5);
			break;
		case '5':
			result += 5 * (int)(pow(16,x.length()-i-1) + 0.5);
			break;
		case '6':
			result += 6 * (int)(pow(16,x.length()-i-1) + 0.5);
			break;
		case '7':
			result += 7 * (int)(pow(16,x.length()-i-1) + 0.5);
			break;
		case '8':
			result += 8 * (int)(pow(16,x.length()-i-1) + 0.5);
			break;
		case '9':
			result += 9 * (int)(pow(16,x.length()-i-1) + 0.5);
			break;
		case 'A':
			result += 10 * (int)(pow(16,x.length()-i-1) + 0.5);
			break;
		case 'B':
			result += 11 * (int)(pow(16,x.length()-i-1) + 0.5);
			break;
		case 'C':
			result += 12 * (int)(pow(16,x.length()-i-1) + 0.5);
			break;
		case 'D':
			result += 13 * (int)(pow(16,x.length()-i-1) + 0.5);
			break;
		case 'E':
			result += 14 * (int)(pow(16,x.length()-i-1) + 0.5);
			break;
		case 'F':
			result += 15 * (int)(pow(16,x.length()-i-1) + 0.5);
			break;
		}
	}

	return result;
}


