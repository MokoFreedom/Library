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

struct UnionFindRange {
	vector< int > data;
    vector< int > left, right;

    UnionFindRange(int size) {
        data.assign(size, -1);
        left.resize(size);
        right.resize(size);
        for (int i = 0; i < size; i++) left[i] = i;
        for (int i = 0; i < size; i++) right[i] = i;
    }

    bool unite(int x, int y) {
		x = root(x), y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y], data[y] = x;
            left[x] = min(left[x], left[y]);
            right[x] = max(right[x], right[y]);
		}
		return x != y;
	}

    pair< int, int > range(int x) {
        x = root(x);
        return make_pair(left[x], right[x]);
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

	return 0;
}
