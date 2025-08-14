#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for( auto &i: a) cin >> i;
	for( auto &i: b) cin >> i;
	
	vector<vector<int>> dp(n+1, vector<int>(m+1));
	vector<vector<pair<int, int>>> par(n+1, vector<pair<int, int>>(m+1));

	auto maxi = [&](int i, int j, int i2, int j2, int cost){
		if (dp[i][j] + cost > dp[i2][j2]){
			dp[i2][j2] = dp[i][j] + cost;
			par[i2][j2] = {i, j};
		}
	};

	for (int i=0; i<=n; i++){
		for (int j=0; j<=m; j++){
			if (i != n && j != m) 
				maxi(i , j, i+1, j+1, a[i] == b[j]);
			if (j != m) maxi(i, j, i, j+1, 0);
			if (i != n) maxi(i, j, i+1, j, 0);
		}
	}
	cout << dp[n][m] << "\n";

	//breadcrumbs / parent array
	int i = n, j = m;
	vector<int> path; 
	while (i>0 || j>0){
		auto [i2, j2]  = par[i][j];
		if (i2 + 1 == i && j2 + 1 == j && a[i2] == b[j2]){
			path.push_back(a[i2]);
		}
		i = i2;
		j = j2;
	}
	reverse(path.begin(), path.end());

	for (int x: path) cout << x << " ";
	
	return 0;
}
