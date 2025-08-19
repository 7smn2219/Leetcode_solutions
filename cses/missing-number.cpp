#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;	
	int xor1=0, xor2=0;
	for (int i=0; i<n; i++){
		int tmp = 0;
		cin >> tmp;
		xor1 ^= tmp;
		xor2 ^= i;
	}
	xor2 ^= n;
	cout << (xor2^xor1) << "\n";
	return 0;
}
