#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// 前計算: O(n r)

// THE BEGINNING OF THE LIBRARY.

template <typename T>
vector< vector<T> > get_comb_dp(int n) {
	vector< vector<T> > dp(n+1,vector<T>(n+1));

	for(int i=0;i<=n;i++) {
		for(int j=0;j<=i;j++) {
			if(j==0||j==i) dp[i][j]=1;
			else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}
	return dp;
}

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IF AN EXAMPLE OF USE.

int main() {
	return 0;
}
