#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// Edges: 重み付き辺の集合。
// WeightedGraph: 重み付きグラフ。
// UnWeitedGraph: 重みなしグラフ。
// Dist: 始点からの距離。
// Matrix: 距離行列。

// THE BEGINNING OF THE LIBRARY

template< typename T >
struct Edge {
	int from, to;
	T cost;

	Edge(int to, T cost) : from(-1), to(to), cost(cost) {}
	Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

bool operator<(const Edge &e, const Edge &f) {
	return e.cost != f.cost ? e.cost > f.cost :
           e.from != f.from ? e.from < f.from :
                              e.to < f.to;
}

template< typename T >
using Edges = vector< Edge< T > >;

template< typename T >
using WeightedGraph = vector< Edges< T > >;

using UnWeightedGraph = vector< vector< int > >;

template< typename T >
using Matrix = vector< vector< T > >;

// 左上を(0,0)とすると、↓,↑,→,←,↘,↙,↗,↖,の順番に移動。
int dx[] = {  0,  0,  1, -1,  1, -1,  1, -1};
int dy[] = {  1, -1,  0,  0,  1,  1, -1, -1};

// THE ENDING OF THE LIBRARY

int main() {
	return 0;
}
