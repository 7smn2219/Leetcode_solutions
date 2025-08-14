#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k; 
	cin >> n >> k;
	
	vector<int>heights(n + 1);
	for (int i=1; i<=n; i++) cin >> heights[i];

	int cur  = heights[k];
	int dist = heights[k];
	bool ans = true;
	sort(heights.begin() + 1 , heights.begin() + n + 1);

	for(int i=1; i<=n; i++){
		if(heights[i] < cur) continue;
		if(heights[i] - cur > dist) ans = false;
		cur = heights[i];
	}
	
	cout << (ans == true ? "YES" : "NO" )<< endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
/* Key idea while you stand on tower of height `h`, you must depart no  
 * later than time `h` - 1 (water hits level `h` at that instant).
 * Therefore, if you arrive at height `h` at global time `t`, you have
 * a slack of
 * 	slack = `h` - 1 - `t`
 *
 * A move to a tallar tower `H` costs `H` - `h` sec. Feasibility cond:
 * 	`t` + (`H` - `h`) <= `h` - 1 <=> `t` + (`H` - `h`) < `h`
 *
 * Greeedy path (monotone asc) Any detour to a lower tower only wastes time
 * and shrink slack, so an optimal route is strictly non-descresing in 
 * height. Thus:
 * 1.	Collect all tower heights, mark your start height `h0`
 * 2.	Sort the heights ascending
 * 3.	Starting with `time` = 0, `cur` = `h0`, walk through every height
 * 	`H` > `cur` in order.
 * 		`time` += `H` - `cur`		(teleport duration)
 * 	if	`time` >= `cur` => drowned => 	answer NO
 * 	else	`cur` = `H`			and continue
 * 4.	If the loop finishes (or you can began on the highest tower)
 * 	Output YES
 */

