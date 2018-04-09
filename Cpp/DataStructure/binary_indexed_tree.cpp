#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// O(log N)
//
// 1-indexed
//
// ある要素に値を加える操作と、区間和を求める操作をそれぞれ対数時間で
// 行うことができるデータ構造。
// セグ木と比べて実装が単純で定数倍が軽い。
//
// 和のように逆元が存在する演算なら任意の区間に対して使えるが、min の
// ような演算に対しては左端からしか使えない。
//
// sum(k): k までの和を求める。
// add(k, x): k に x を加える。

// THE BEGINNING OF THE LIBRARY

template< typename T >
struct BinaryIndexedTree {
	vector< T > data;

	BinaryIndexedTree(int size) : data(size + 1, 0) {}

	T sum(int k) {
		T res = 0;
		for (++k; k > 0; k -= (k & -k)) res += data[k];
		return res;
	}

	void add(int k, T x) {
		for (++k; k < (int)data.size(); k += (k & -k)) data[k] += x;
	}
};

// THE ENDING OF THE LIBRARY
// THE FOLLOWING IS AN EXAMPLE OF USE

int main() {

	int n, q;
	cin >> n >> q;
	BinaryIndexedTree< long long > tree(n + 1);
	while (q--) {
		int type, x, y;
		cin >> type >> x >> y;
		if (type == 0) {
			tree.add(x, y);
		}
		else {
			cout << tree.sum(y) - tree.sum(x - 1) << endl;
		}
	}

	return 0;
}
