#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}

	long long ans = 0, last = arr[0];
	for (auto ele: arr){
		if (ele < last)
			ans += last - ele;
		else last = ele;
	}

	cout << ans << "\n";
	return 0;
}
