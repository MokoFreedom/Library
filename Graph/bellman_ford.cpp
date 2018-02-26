#include <bits/stdc++.h>
using namespace std;

#define INF 1e9+1
#define LINF 1e18+1

// MEMO
//
// O(V E)
// 負辺があっても動く
// 不閉路を検出(n回目にも更新がある)
// Weight: 辺の重み。制約によって変える
// INIT: distの初期化用。制約によって変える。

// THE BEGINNING OF THE LIBRARY

#define INIT INF
typedef int Weight;

struct Edge {
	int to,from;
	Weight cost;
	Edge(int to,int from,Weight cost):to(to),from(from),cost(cost) {}
};

typedef vector<Edge> Graph;

bool operator<(const Edge &e,const Edge &f) {
	return e.cost!=f.cost?e.cost>f.cost:e.from!=f.from?e.from<f.from:e.to<f.to;
}

bool bellman_ford(const Graph &G,int s,vector<Weight> &dist) {
	int n=(int)G.size();
	dist.assign(n,INIT+INIT);
	dist[s]=0;
	bool negative_cycle=false;
	for(int i=0;i<n;i++) {
		for(auto e:G) {
			if(dist[e.from]==INIT+INIT) continue;
			if(dist[e.to]<=dist[e.from]+e.cost) continue;
			dist[e.to]=dist[e.from]+e.cost;
			if(i==n-1) {
				dist[e.to]=-INIT;
				negative_cycle=true;
			}
		}
	}
	return !negative_cycle;
}

// THE ENDING OF THE LIBRARY
// THE FOLLOWING IS AN EXAMPLE OF USE

int main() {

	int n,m,s,g;
	cin>>n>>m;
	s=0,g=n-1;
	Graph G;
	vector<Weight> dist(n);
	for(int i=0;i<m;i++) {
		int a,b;Weight c;
		cin>>a>>b>>c;
		a--,b--;
		G.emplace_back(Edge(a,b,c));
		G.emplace_back(Edge(b,a,c));
	}
	if(bellman_ford(G,s,dist)) cout<<dist[g]<<endl;
	else cout<<-1<<endl;

	return 0;
}
