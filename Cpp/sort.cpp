#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// バブルソート
// - O(n^2)
// - 配列の中から「大きさが逆転している部分があったらswapする」を繰り返す。
// - 内部ソートかつ安定ソート。
//
// 選択ソート
// - O(n^2)
// - 配列の中から「残っているもののうち一番小さいものを前に持ってくる」を繰り返す。
// - 内部ソート。安定ソートではない。

// THE BEGINNING OF THE LIBRARY.

void bubble_sort(vector< int > &a) {
    for (int i = 0; i < (int)a.size() - 1; i++) {
        for (int j = (int)a.size() - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
            }
        }
    }
} 

void selention_sort(vector< int > &a) {
	for (int i = 0; i < (int)a.size(); i++) {
		int min_index = i;
		for (int j = min_index; j < (int)a.size(); j++) {
			if (a[j] < a[min_index]) {
				min_index = j;
			}
		}
		swap(a[i], a[min_index]);
	}
}

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

int main() {
    return 0;
}
