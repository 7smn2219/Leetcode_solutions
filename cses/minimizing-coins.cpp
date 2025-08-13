#include <bits/stdc++.h>
using namespace std;

int const MOD = 1e9 + 7;
vector<int> dp;

int recur(vector<int>& coins, int x){
	if (x < 0) return INT_MAX;
	if (x == 0) return 0;
	if (dp[x] != -1) return dp[x];
	
	int ans = INT_MAX;
	for(int i=0; i < coins.size(); i++){
		if(x - coins[i] >= 0){
			int sub = recur(coins, x - coins[i]);
			if (sub != INT_MAX) ans = min(ans, sub + 1);
		}
	}
	return dp[x] = ans;
	
}

int main(){
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for(auto &i : coins) cin >> i;
	dp.assign(x + 1, -1);

	int mincoins = -1;
	mincoins = recur(coins, x);

	cout << (mincoins == INT_MAX ? -1 : mincoins) << "\n";
	return 0;
}
