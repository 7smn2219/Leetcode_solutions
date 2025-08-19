#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	int x, a, b, c;
	cin >> x >> a >> b >> c;

	// x1 = x
	// xi = (a*xi-1 + b) mod c
	
	long long ans = 0, xlast = x, sum=x;
	for(int i=1; i<k; i++){
		int num = (a * xlast + b)% c;
		xlast = num;
		sum += num;
	}
	ans ^= sum;
	long long i = k;
	long long klast = x;
	while(i < n){
		// cout << ans << "\n"; 
		xlast = (a * xlast + b)% c;
		sum -= klast;
		sum += xlast;
		
		klast = (a * klast + b )% c;
		ans ^= sum;
		i++;
	}

	cout << ans << "\n";

	return 0;
}
