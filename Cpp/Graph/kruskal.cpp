#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// O(E log V)
// 
// すべての辺の重みを昇順にソート。
// 辺を前から(重みの小さい順に)処理する。
// その辺によって連結される2頂点が既に連結されている場合はスキップ。
// そうでなければその2頂点を同一連結成分にする。
//
// 頂点が連結かどうかの判定には Union-Find木 を使用する。
// グラフが連結なら最小全域木、連結でないなら最小全域森が求まる。
//
// add_edge(u, v, c): u と v を繋ぐ重み c の無向辺を edges に追加する。
// input(m): m 本の辺を読み込んで add_edge() で追加する。
// kruskal(): 最小全域木(もしくは最小全域森)を求めてコストの和を返す。
//            使われる辺も知りたい場合は、返り値の型を pair< T, Edges > にし、
//            辺を unite する度に Edges に追加していく。

// THE BEGINNING OF THE LIBRARY.

template< typename T >
struct Kruskal {

	// Kruskalに必要なライブラリ開始。

	struct Edge {
		int from, to;
		T cost;

		Edge(int to, T cost) : from(-1), to(to), cost(cost) {}
		Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

		bool operator<(const Edge &e) const {
			return cost < e.cost;
		}
	};

	using Edges = vector< Edge >;

	struct UnionFind {
		vector< int > data;
		UnionFind(int size) : data(size, -1) {}
		bool unite(int x, int y) {
			x = root(x), y = root(y);
			if (x != y) {
				if (data[y] < data[x]) swap(x, y);
				data[x] += data[y], data[y] = x;
			}
			return x != y;
		}
		bool same(int x, int y) {
			return root(x) == root(y);
		}
		int root(int x) {
			return data[x] < 0 ? x : data[x] = root(data[x]);
		}
		int size(int x) {
			return -data[root(x)];
		}
	};

	// Kruskalに必要なライブラリ終了。

	int n;
	Edges edges;

	Kruskal() {}
	Kruskal(int size) : n(size) {}

	void add_edge(int u, int v, T c) {
		edges.emplace_back(u, v, c);
	}

	void input(int m) {
		int a, b; T c;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			add_edge(a, b, c);
		}
	}

	T kruskal() {
		sort(edges.begin(), edges.end());
		UnionFind uf(n);
		T res = 0;
		for (auto &e : edges) {
			if (!uf.same(e.from, e.to)) {
				uf.unite(e.from, e.to);
				res += e.cost;
			}
		}
		return res;
	}
};

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

int main() {

	int n, m;
	Kruskal< int > G(n);
	G.input(m);
	cout << G.kruskal() << endl;

	return 0;
}
