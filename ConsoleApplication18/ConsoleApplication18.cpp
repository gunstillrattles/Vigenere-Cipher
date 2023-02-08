#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
	string text = "ATTACKATDAWN";
	string key = "LEMON";
	int keyLen = key.length();
	for (int i = key.length(); i < text.length(); i++) {
		key += ' ';

	}
	int numOfCycles = 0;
	for (int i = keyLen; i < text.length(); i++) {
		for (int j = numOfCycles; j < text.length(); j++) {
			key[i] = key[j];
			numOfCycles++;
			break;
		}
	}
	string encodeResult = key;
	string decodeResult = key;
	cout << key << endl;
	for (int i = 0; i < text.length(); i++) {
		encodeResult[i] = ((text[i] + key[i]) % 26) + 65;
	}
	int temp;
	for (int i = 0; i < text.length(); i++) {
		temp = encodeResult[i] - key[i];
		if (temp < 0) {
			temp = (temp * 1) + 26;
		}
		decodeResult[i] = temp % 26 + 65;
	}
	cout << encodeResult << endl;
	cout << decodeResult << endl;
}