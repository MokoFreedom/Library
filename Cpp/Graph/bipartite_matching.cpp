#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// O(VE)
//
// 最小頂点被覆 = 最大マッチング
// - グラフ G = (V, E) において、各辺 e について端点のいずれか少なくとも一方が V' に
//   含まれるような集合 V' のうち、V' の頂点数が最小であるものを、最小頂点被覆という。
// 
// DAGの最小パス被覆 = V - 最大マッチング
// - グラフ G = (V, E) において、そのグラフのすべての頂点が1つ以上のパスに含まれる
//   ようなパスの集合をパス被覆という。
// - 特に、パス被覆の中でパスの数が最小のものを最小パス被覆という。
// - DAGの最小パス被覆は二部グラフの最大マッチング問題に帰着できる。
// - 頂点を倍長して、始点を左側、終点を右側にしたグラフを考える。
//   まず、V 本のパスがあれば被覆できることは自明。
//   このグラフのマッチング1組に対して必要なパスを1つ減らすことができるため、
//     V - (二部グラフの最大マッチング)
//   が最小パス被覆となる。

// THE BEGINNING OF THE LIBRARY.

struct BipartiteMatching {
	using UnWeightedGraph = vector< vector< int > >;

	int n;
	UnWeightedGraph G;
	vector< int > match,used;

	BipartiteMatching() {}
	BipartiteMatching(int sz) : n(sz), G(sz), match(sz), used(sz) {}

	void add_edge(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}

	bool dfs(int v) {
		used[v] = true;
		for (auto u : G[v]) {
			int w = match[u];
			if (w < 0 || (!used[w] && dfs(w))) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}

	int bipartite_matching() {
		int res = 0;
		fill(match.begin(), match.end(), -1);
		for (int v = 0; v < n; v++) {
			if (match[v] < 0) {
				fill(used.begin(), used.end(), 0);
				if (dfs(v)) res++;
			}
		}
		return res;
	}
};

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

int main() {

	int X, Y, E;
	cin >> X >> Y >> E;
	BipartiteMatching bimatch(X + Y);
	for (int i = 0; i < E; i++) {
		int x, y;
		cin >> x >> y;
		bimatch.add_edge(x, X + y);
	}
	cout << bimatch.bipartite_matching() << endl;

	return 0;                               
}
