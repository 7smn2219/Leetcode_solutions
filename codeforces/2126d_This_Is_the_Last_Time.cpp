#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	
	vector<vector<int>> casino(n, vector<int>(3)); //l, r, real
	for (int i=0; i<n; i++){
		cin >> casino[i][0] >> casino[i][1] >> casino[i][2];
	}

	sort(casino.begin(), casino.end(), [&](vector<int> a, vector<int> b){
		if (a[0] != b[0]) return a[0] < b[0];
		if (a[1] != b[1]) return a[1] < b[1];
		return a[2] < b[2];
	});
	
	int cur = k;
	for (int i=0; i<n; i++){
		if (cur < casino[i][0]) break;
		if (cur > casino[i][1]) continue;
		else cur = max(cur, casino[i][2]);
	}

	cout << cur << "\n";

}

int main(){
	int t;
	cin >> t;

	while(t--){
		solve();
	}
	
	return 0;
}
