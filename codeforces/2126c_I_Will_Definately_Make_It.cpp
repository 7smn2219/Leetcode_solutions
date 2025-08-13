#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k; 
	cin >> n >> k;
	
	vector<int>heights(n);
	for(auto &h : heights) cin >> h;

	int cur = heights[k-1];
	sort(heights.begin(), heights.end());
	int i = 0, flag = 0;
	for(; i<n; i++)if(heights[i] == cur) break;
	for(; i<n; i++){
		if(cur >= n) {
			flag=1;
			break;
		}
		while(heights[i] == cur && i<n)i++;
		i++;
		if( heights[i] - cur < cur) {
			flag = 0;
			break;
		}
		cur = heights[i];
	}
	if(flag)
		cout << "YES" << endl;
	else cout<< "NO" << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
