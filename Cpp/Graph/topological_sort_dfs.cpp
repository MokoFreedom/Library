#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// O(V+E)
//
// YET: 未訪問, VISITED: 訪問済みかつリスト未追加, DONE: リスト追加済み
//
// 有向グラフの位相的順序とは、頂点の順序付けuであって、u[i]からu[j]に辺がある
// -> i<j が成立するものをいう。
// ある頂点vから到達可能かつ未到達の頂点をすべてリストに追加したあとにvを追加することを
// すべての頂点を訪問するまで繰り返すと、トポロジカル順序と逆順の列ができる。
//　dfsだとスタックオーバーフローの可能性がある。

// THE BEGINNING OF THE LIBRARY.

struct TopologicalSort {
	int n;
	vector< vector< int > > G;
	vector< int > flg, order;

	enum { YET, VISITED, DONE };

	TopologicalSort() {}
	TopologicalSort(int sz) : n(sz), G(sz), flg(sz) {};

	void add_edge(int u, int v) {
		G[u].push_back(v);
	}

	bool dfs(int v) {
		flg[v] = VISITED;
		for (auto u : G[v]) {
			if (flg[u] != DONE && (flg[u] == VISITED || !dfs(u))) return false;
		}
		flg[v] = DONE;
		order.push_back(v);
		return true;
	}

	vector< int > topological_sort() {
		fill(flg.begin(), flg.end(), 0);

		for (int v = 0; v < n; v++) {
			if (flg[v] == YET && !dfs(v)) return {};
		}
		reverse(order.begin(), order.end());

		return order;
	}
};

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

int main() {

	int V, E;
	cin >> V >> E;
	TopologicalSort tsort(V);
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		tsort.add_edge(u, v);
	}
	auto order = tsort.topological_sort();
	for (auto v : order) cout << v << endl;

	return 0;
}
