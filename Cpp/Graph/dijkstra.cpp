#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// O(E log V)
//
// 負辺が無いと仮定すると、各時点で最も近いところから距離が確定していく。
// したがって距離順でソートされたヒープを用いると効率よく次々と各点の距離を
// 確定していくことができる。
//
// WeightedGraph: to, costしか使用しない。負辺は無いものとする。
// s, g: それぞれ始点と終点。
//
// dijkstra(G, s): 重み付き有向グラフ G 上で、頂点 s からすべての頂点への最短期間を求め、
//                 その配列を返す。

// THE BEGINNIG OF THE LIBRARY.

template< typename T >
struct Edge {
	int from, to;
	T cost;

	Edge(int to, T cost) : from(-1), to(to), cost(cost) {}
	Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

template< typename T >
using Edges = vector< Edge< T > >;

template< typename T >
using WeightedGraph = vector< Edges< T > >;

template< typename T >
vector< T > dijkstra(WeightedGraph< T > &G, int s) {
	const auto INIT = numeric_limits< T >::max();
	vector< T > dist(G.size(), INIT);
	dist[s] = 0;

	using P = pair< T, int >;
	priority_queue< P, vector< P >, greater< P > > Q;
	Q.push(P(0, s));
	while (!Q.empty()) {
		P p = Q.top(); Q.pop();
		int v = p.second;
		if (dist[v] < p.first) continue;
		for (auto &e : G[v]) {
			if (dist[e.to] <= dist[v] + e.cost) continue;
			dist[e.to] = dist[v] + e.cost;
			Q.push(P(dist[e.to], e.to));
		}
	}
	return dist;
}

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

using Weight = long long;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m, s, g;
	cin >> n >> m;
	s = 0,g = n - 1;
	WeightedGraph< Weight > G(n);
	vector< Weight > dist(n);
	for (int i = 0; i < m; i++) {
		int a, b; Weight c;
		cin >> a >> b >> c;
		a--, b--;
		G[a].emplace_back(b, c);
		G[b].emplace_back(a, c);
	}
	dist = dijkstra(G, s);
	cout << dist[g] << endl;

	return 0;
}
