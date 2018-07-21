#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// unite,same: O(A(n))
//
// unite(x, t): x が属する集合と y が属する集合を併合する。
// same(x, y): x と y が同じ集合に属するかどうか判定する。
// root(x): x が属する集合を求める。
// size(x): x が属する集合の要素数を求める。

// THE BEGINNING OF THE LIBRARY.

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

struct Bipartite_Graph: UnionFind {
    vector< int > color;

    Bipartite_Graph(int v): color(v + v, -1), UnionFind(v + v) {}

    bool bipartite_graph_coloring() {
        for(int i = 0; i < color.size() / 2; i++) {
            int a = root(i);
            int b = root(i + (int)color.size() / 2);
            if (a == b) return false;
            if (color[a] < 0) color[a] = 0, color[b] = 1;
        }
        return true;
    }

    bool operator[](int k) {
        return bool(color[root(k)]);
    }
};

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

int main() {

	return 0;
}
