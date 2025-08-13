#include <bits/stdc++.h>
using namespace std;

void solve(){
	int x;
	cin >> x;
	string s = to_string(x);
	int smallest = 9;
	for(auto c : s) smallest = min(smallest, c - '0');
	cout << smallest << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
