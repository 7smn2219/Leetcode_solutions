#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return ;
	}
	if (n<4) {
		cout << "NO SOLUTION";
		return ;
	}
	if (n%2==0){
		for (int i=2; i<=n; i+=2)
			cout << i << " ";
		for (int i=1; i<=n; i+=2)
			cout << i << " ";
	}
	else {
		for (int i=n-1; i>0; i-=2)
			cout << i << " ";
		for (int i=n; i>0; i-=2)
			cout << i << " ";
	}
	
}

int main(){
	solve();
	return 0;
}
