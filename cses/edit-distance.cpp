#include <bits/stdc++.h>
using namespace std;

/*
vector<vector<int>> dp;

int recur(string a, string b, int i, int j){
	if (i == a.size()) return dp[i][j] = b.size() - j;
	if (j == b.size()) return dp[i][j] = a.size() - i;

	if (dp[i][j] != -1 ) return dp[i][j];

	int ans = INT_MAX;
	if (a[i] == b[j]) ans = min(ans, recur(a, b, i+1, j+1)) ;
	else ans = min(ans, recur(a, b, i+1, j+1)) + 1;
	int skip_a = recur(a, b, i+1, j) + 1;
	int skip_b = recur(a, b, i, j+1) + 1;
	
	ans = min({ ans, skip_a, skip_b});

	return dp[i][j] = ans;
}
*/

int main(){
	string a, b;
	cin >> a >> b;
	
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	//Base case
	for (int i=0; i <= n; i++) dp[i][m] = n - i;
	for (int j=0; j <= m; j++) dp[n][j] = m - j;

	// Above recur function
	for (int i = n-1; i>=0; i--){
		for (int j = m-1; j >= 0; j--){
			if (a[i] == b[j])
				dp[i][j] = dp[i+1][j+1];
			else {
				int replace = dp[i+1][j+1] + 1;
				int skip_a  = dp[i+1][j] + 1;
				int skip_b  = dp[i][j+1] + 1;
				dp[i][j] = min({replace, skip_a, skip_b});
			}
		}
	}

	cout << dp[0][0] <<  "\n" ;
	return 0;
}
