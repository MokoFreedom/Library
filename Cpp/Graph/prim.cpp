#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// O(E log V)
//
// 無向グラフの最小全域木を構築する。
//
// まず適当な頂点 v を選び、それのみからなる頂点の集合 S を用意する。
// 次に、S から S の外へ伸びる辺の中で最も重みが小さいもので結ばれている頂点を
// S に追加する。
// これを v から到達可能な頂点がすべて S に入るまで繰り返す。
//
// グラフが連結でないなら v から到達不可能な点は無視する。
//
// prim(G, s): グラフ G で s を根とする最小全域木を求める。Dijkstra法のイメージ。

// THE BEGINNING OF THE LIBRARY.

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
T prim(const WeightedGraph< T > &G, int s = 0) {
	using P = pair< T, int >;

	T res = 0;
	vector< bool > visited((int)G.size(), false);
	priority_queue< P, vector< P >, greater< P > > Q;
	Q.emplace(0,0);
	while (!Q.empty()) {
		P p = Q.top(); Q.pop();
		int v = p.second;
		if (visited[v]) continue;
		visited[v] = true;
		res += p.first;
		for (auto e : G[v]) Q.emplace(e.cost, e.to);
	}
	return res;
}

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

using Weight = long long;

int main() {

	int V, E;
	cin >> V >> E;
	WeightedGraph< Weight > G(V);
	for (int i = 0; i < E; i++) {
		int s, t; Weight w;
		cin >> s >> t >> w;
		G[s].emplace_back(t, w);
		G[t].emplace_back(s, w);
	}
	cout << prim(G) << endl;

	return 0;
}
