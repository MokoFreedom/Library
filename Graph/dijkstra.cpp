#include <bits/stdc++.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18

// MEMO
//
// O(E log V)
// Weight: 辺の重み。制約によって変える。
// INIT: distの初期化用。制約によって変える。

// THE BEGINNIG OF THE LIBRARY.

#define INIT INF
typedef int Weight;
typedef pair<Weight,int> P;

struct Edge {
	int to;
	Weight cost;
	Edge(int to,Weight cost):to(to),cost(cost) {}
};

typedef vector< vector<Edge> > Graph;

bool operator<(const Edge &e,const Edge &f) {
	return e.cost!=f.cost?e.cost>f.cost:e.to<f.to;
}

void dijkstra(const Graph &G,int s,vector<Weight> &dist) {
	int n=(int)G.size();
	dist.assign(n,INIT);
	dist[s]=0;
	priority_queue< P,vector<P>,greater<P> > Q;
	Q.push(P(0,s));
	while(!Q.empty()) {
		P p=Q.top();Q.pop();
		int v=p.second;
		if(dist[v]<p.first) continue;
		for(auto &e:G[v]) {
			if(dist[e.to]<=dist[v]+e.cost) continue;
			dist[e.to]=dist[v]+e.cost;
			Q.push(P(dist[e.to],e.to));
		}
	}
}

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,m,s,g;
	cin>>n>>m;
	s=0;g=n-1;
	Graph G(n);
	vector<Weight> dist(n);
	for(int i=0;i<m;i++) {
		int a,b;Weight c;
		cin>>a>>b>>c;
		a--,b--;
		G[a].emplace_back(Edge(b,c));
		G[b].emplace_back(Edge(a,c));
	}
	dijkstra(G,s,dist);
	cout<<dist[g]<<endl;

	return 0;
}
