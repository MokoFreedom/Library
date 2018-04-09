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

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

int main() {

	int n, q;
	cin >> n >> q;
	UnionFind uf(n);
	while (q--) {
		int type, x, y;
		cin >> type >> x >> y;
		x--, y--;
		if (type == 0) uf.unite(x, y);
		else cout << uf.same(x, y) << endl;
	}

	return 0;
}
