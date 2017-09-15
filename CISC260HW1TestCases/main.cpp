/*
 * main.cpp
 *
 *  Created on: Sep 14, 2017
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
int hexToBase10(string x);

int main(){
	cout << "Decimal to Binary Test:" << endl;
	cout << base10ToBinary(10) << " Result" << endl << "00000000000000000000000000001010 Expected" << endl;
	cout << base10ToBinary(4096) << " Result" << endl << "00000000000000000001000000000000 Expected" << endl;
	cout << base10ToBinary(-10) << " Result" << endl << "11111111111111111111111111110110 Expected" << endl;
	cout << base10ToBinary(-4096) << " Result" << endl << "11111111111111111111000000000000 Expected" << endl;

	cout << "Decimal to Hex Test:" << endl;
	cout << base10ToHex(4096) << " Result" << endl << "00001000 Expected" << endl;
	cout << base10ToHex(-4096) << " Result" << endl << "FFFFF000 Expected" << endl;
	cout << base10ToHex(42) << " Result" << endl << "0000002A Expected" << endl;
	cout << base10ToHex(-42) << " Result" << endl << "FFFFFFD6 Expected" << endl;

	cout << "Hex to Decimal Test:" << endl;
	cout << hexToBase10("E7A9") << " Result" << endl << "59305 Expected" << endl;
	cout << hexToBase10("0000E7A9") << " Result" << endl << "59305 Expected" << endl;
	cout << hexToBase10("75BCD15") << " Result" << endl << "123456789 Expected" << endl;
	cout << hexToBase10("2A") << " Result" << endl << "42 Expected" << endl;

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






