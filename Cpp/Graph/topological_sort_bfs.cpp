#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// O(V+E)
//
// 入次数が0の頂点vは列の1番左に追加できる。
// 次に、vとvから伸びる辺を取り除く。
// そのとき入次数が0となる頂点は、取り除いて列の末尾に追加できる。
// これをすべての頂点が取り除かれるまで繰り返す。

// THE BEGINNING OF THE LIBRARY.

struct TopologicalSort {
	int n;
	vector< vector<int> > G;
	vector<bool> used;
	vector<int> indeg,order;

	TopologicalSort() {}
	TopologicalSort(int sz):n(sz),G(sz),used(sz),indeg(sz) {};

	void add_edge(int u,int v) {
		G[u].push_back(v);
	}

	vector<int> topological_sort() {
		fill(indeg.begin(),indeg.end(),0);

		for(int v=0;v<n;v++) {
			for(auto u:G[v]) indeg[u]++;
		}
		queue<int> Q;
		for(int v=0;v<n;v++) {
			if(indeg[v]==0) Q.push(v);
		}
		while(!Q.empty()) {
			int v=Q.front();Q.pop();
			order.push_back(v);
			for(auto u:G[v]) {
				if(--indeg[u]==0) Q.push(u);
			}
		}

		return order;
	}
};

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

int main() {

	int V,E;
	cin>>V>>E;
	TopologicalSort tsort(V);
	for(int i=0;i<E;i++) {
		int u,v;
		cin>>u>>v;
		tsort.add_edge(u,v);
	}
	auto order=tsort.topological_sort();
	for(auto v:order) cout<<v<<endl;

	return 0;
}
