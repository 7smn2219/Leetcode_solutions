#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector<string> grid(n);
	for (int i=0; i<n; i++) cin >> grid[i];
	
	queue<pair<int, int>> q;
	int i=0, j=0;
	q.push({i, j});

	while(i < n && j < n){
		cout << grid[i][j] << " ";
				
		int size = q.size();
		vector<pair<char, pair<int, int>>> ele;

		while(size--){
			auto [i, j] = q.front();
			q.pop();

			if (i+1 < n) ele.push_back({grid[i][j], {i+1, j}});
			if (j+1 < n) ele.push_back({grid[i][j], {i, j+1}});
		}

		for(auto& [i, j]: ele)cout << i << "\n";
		i= n, j=n;	
	}

	return 0;
}
