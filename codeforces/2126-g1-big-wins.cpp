#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;

	vector<int> arr(n+1);
	for (int i=1; i<=n; i++)cin >> arr[i];
	
	int ans = 0;
	for (int i=1; i<=100; i++){
		vector<int> brr(n+1);
		for (int j=1; j<=n; j++){
			if(arr[j] >= i) brr[j]=1;
			else brr[j] = -1;
		}

		vector<int> pref(n+1);
		for (int j=1; j<=n; j++){
			pref[j] = pref[j-1] + brr[j];
		}

		vector<int> prefmin(n+2), suffmax(n+1);
		prefmin[0] = 0, suffmax[n] = pref[n];
		for (int j=1; j<=n; j++){
			prefmin[j] = min(prefmin[j-1], pref[j]);
		}
		for (int j=n-1; j>=1; j--){
			suffmax[j] = max(suffmax[j+1], pref[j]);
		}
		for(int j=1; j<=n; j++){
			if(prefmin[j-1] <= pref[j] || pref[j-1] <= suffmax[j]){
				ans = max(ans, i - arr[j]);
			}
		}
	}
	cout << ans << "\n";
}

int main(){
	int t;
	cin >> t;
	while(t--)solve();
	return 0;
}
