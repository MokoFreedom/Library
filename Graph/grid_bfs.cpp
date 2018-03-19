#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// O(WH)

// THE BEGINNING OF THE LIBRARY.

vector< vector<int> > bfs(vector<string> &fld,int sx,int sy,char wall,int dir) {
	int h=fld.size(),w=fld.front().size();
	vector< vector<int> > dp(h,vector<int>(w,-1));
	using P=pair<int,int>;
	queue<P> Q;

	dp[sy][sx]=0;
	Q.emplace(sx,sy);

	int dx[]={ 0, 0, 1,-1, 1,-1, 1,-1};
	int dy[]={ 1,-1, 0, 0, 1, 1,-1,-1};

	while(!Q.empty()) {
		P p=Q.front();Q.pop();
		for(int i=0;i<dir;i++) {
			int nx=p.first+dx[i],ny=p.second+dy[i];
			if(nx<0||nx>=w||ny<0||ny>=h) continue;
			if(dp[ny][nx]!=-1) continue;
			if(fld[ny][nx]==wall) continue;
			dp[ny][nx]=dp[p.second][p.first]+1;
			Q.emplace(nx,ny);
		}
	}

	return dp;
}

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

int main() {

	int h,w;
	cin>>h>>w;
	vector<string> fld(h);
	for(int i=0;i<h;i++) cin>>fld[i];
	auto dp=bfs(fld,0,0,'#',4);
	cout<<dp[h-1][w-1]<<endl;

	return 0;
}
