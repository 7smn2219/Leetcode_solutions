#include <bits/stdc++.h>
using namespace std;

int main(){
	string dna;
	cin >> dna;

	int ans = 1, cnt = 1;
	int n = dna.size();
	for (int i=1; i<n; i++){
		if (dna[i-1] == dna[i])cnt++;
		else cnt = 1;
		ans = max(cnt, ans);
	}

	cout << ans << "\n";
	return 0;
}
