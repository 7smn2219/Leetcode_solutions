#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<long long> p(n), s(n), a(n);
	for (auto &i:p) cin>>i; 
	for (auto &i:s) cin>>i;

	// p <- prefix GCD of a
	// s <- sufix GCD of a
	
	bool ans = true;
	for (int i=0; i<n; i++){
		a[i] = lcm(p[i], s[i]);
	}

	if (a[0] != p[0])     ans = false;
	if (a[n-1] != s[n-1]) ans = false;

	for (int i=1; i<n; i++) {
		if (__gcd(p[i-1], a[i]) != p[i]) ans = false;
	}

	for (int i=n-1; i>0; i--){
		if (__gcd(s[i], a[i-1]) != s[i-1]) ans = false; 
	}

	cout << (ans == true ? "YES" : "NO") << "\n";
}

int main()
{
	int t;
	cin >> t;
	while(t--)solve();
	return 0;
}
