#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// O(V E)
// 負辺があっても動く
// 不閉路を検出(n回目にも更新がある)

// THE BEGINNING OF THE LIBRARY

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
bool bellman_ford(Edges< T > &edges, int s, vector< T > &dist) {
	const auto INIT = numeric_limits< T >::max();
	int n = (int)dist.size();
	dist.assign(n, INIT);
	dist[s] = 0;
	bool negative_cycle = false;
	for (int i = 0; i < n; i++) {
		for (auto e : edges) {
			if (dist[e.from] == INIT) continue;
			if (dist[e.to] <= dist[e.from] + e.cost) continue;
			dist[e.to] = dist[e.from] + e.cost;
			if (i == n-1) {
				dist[e.to] = -INIT;
				negative_cycle = true;
			}
		}
	}
	return !negative_cycle;
}

// THE ENDING OF THE LIBRARY
// THE FOLLOWING IS AN EXAMPLE OF USE

int main() {

	int n, m, s, g;
	cin >> n >> m;
	s = 0, g = n - 1;
	Edges< Weight > edges;
	vector< Weight > dist(n);
	for (int i = 0; i < m; i++) {
		int a, b; Weight c;
		cin >> a >> b >> c;
		a--, b--;
		edges.emplace_back(Edge(a, b, c));
		edges.emplace_back(Edge(b, a, c));
	}
	if (bellman_ford(edges, s, dist)) cout << dist[g] << endl;
	else cout << -1 << endl;

	return 0;
}
