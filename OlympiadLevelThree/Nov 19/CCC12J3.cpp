#include <iostream>
using namespace std;

int main() {
	int scaleRatio;
	cin >> scaleRatio;
	for (int i = 0; i < scaleRatio; i++) {
		for (int j = 0; j < scaleRatio; j++) {
			cout << "*";
		}
		for (int j = 0; j < scaleRatio; j++) {
			cout << "x";
		}
		for (int j = 0; j < scaleRatio; j++) {
			cout << "*";
		}
		cout <<endl;
	}
	for (int i = 0; i < scaleRatio; i++) {
		for (int j = 0; j < scaleRatio; j++) {
			cout << " ";
		}
		for (int j = 0; j < scaleRatio; j++) {
			cout << "x";
		}
		for (int j = 0; j < scaleRatio; j++) {
			cout << "x";
		}
		cout <<endl;
	}
	for (int i = 0; i < scaleRatio; i++) {
		for (int j = 0; j < scaleRatio; j++) {
			cout << "*";
		}
		for (int j = 0; j < scaleRatio; j++) {
			cout << " ";
		}
		for (int j = 0; j < scaleRatio; j++) {
			cout << "*";
		}
		cout <<endl;
	}
	return 0;
}