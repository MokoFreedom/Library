#include <bits/stdc++.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18

// MEMO
//
// O(E log V)

// THE BEGINNIG OF THE LIBRARY.

template< typename T >
struct Edge {
	int from,to;
	T cost;

	Edge(int to,T cost):from(-1),to(to),cost(cost) {}
	Edge(int from,int to,T cost):from(from),to(to),cost(cost) {}
};

template< typename T >
using Edges=vector< Edge<T> >;

template< typename T >
using WeightedGraph=vector< Edges<T> >;

template< typename T >
vector<T> dijkstra(WeightedGraph<T> &G,int s) {
	const auto INIT=numeric_limits<T>::max();
	vector<T> dist(G.size(),INIT);
	dist[s]=0;

	using P=pair<T,int>;
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
	return dist;
}

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

using Weight=long long;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,m,s,g;
	cin>>n>>m;
	s=0;g=n-1;
	WeightedGraph<Weight> G(n);
	vector<Weight> dist(n);
	for(int i=0;i<m;i++) {
		int a,b;Weight c;
		cin>>a>>b>>c;
		a--,b--;
		G[a].emplace_back(b,c);
		G[b].emplace_back(a,c);
	}
	dist=dijkstra(G,s);
	cout<<dist[g]<<endl;

	return 0;
}
