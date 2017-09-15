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

string base10ToBinary(int x);
string binaryHelper(int x);
string base10ToHex(int x);

int main(){
	int dec;
	cout << "Base-10 to Binary & Hexadecimal (32-bit)" << endl;
	cout << "Please enter a base-10 integer:" << endl;
	cin >> dec;
	cout << "Binary: " << base10ToBinary(dec) << endl;
	cout << "Hexadecimal: " << base10ToHex(dec) << endl;

	return 0;
}

string binaryHelper(int x){
	string result = "";
	int value = abs(x);

	do{
		result = to_string(value%2) + result;
		value /= 2;
	} while(value>1);

	result = to_string(value%2) + result;

	return result;
}

string base10ToBinary(int x){
	string result;

	if(x<0){
		result = binaryHelper(abs(x));
		bool valChanged = false;

		for(int i=0;i<result.length();i++){
			if(result[i]=='0'){
				result.replace(i,1,"1");
			}
			else{
				result.replace(i,1,"0");
			}
		}


		for(int i=result.length()-1;(i>=-1)&&(!valChanged);i--){
			if(i==-1){
				result = to_string(1) + result;
				result.replace(1,result.length()-1,to_string(0));
				valChanged = true;
			}
			else{
				if(result[i]=='0'){
					result.replace(i,1,to_string(1));
					valChanged = true;
				}
				else{
					result.replace(i,1,to_string(0));
				}
			}
		}


		while(result.length()<32){
			result = to_string(1) + result;
		}
	}
	else{
		result = binaryHelper(x);

		while(result.length()<32){
			result = to_string(0) + result;
		}
	}

	return result;
}

string base10ToHex(int x){
	string result = "";
	string bin = base10ToBinary(x);
	string group;
	int hdigit;

	string hexdigits[16] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

	for(int i=0;i<8;i++){
		hdigit=0;
		group = bin.substr(i*4,4);

		for(int j=0,digit;j<4;j++){
			digit = group[j] - '0';
			if(digit==1){
				switch(j){
				case 0:
					hdigit += 8;
					break;
				case 1:
					hdigit += 4;
					break;
				case 2:
					hdigit += 2;
					break;
				case 3:
					hdigit += 1;
					break;
				}
			}
		}

		result = result + hexdigits[hdigit];
	}

	return result;
}



