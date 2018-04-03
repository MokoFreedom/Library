#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// O(E log V)

// THE BEGINNING OF THE LIBRARY.

template< typename T >
struct Kruskal {

	// Kruskalに必要なライブラリ開始。

	struct Edge {
		int from,to;
		T cost;

		Edge(int to,T cost):from(-1),to(to),cost(cost) {}
		Edge(int from,int to,T cost):from(from),to(to),cost(cost) {}

		bool operator<(const Edge &e) const {
			return cost<e.cost;
		}
	};

	using Edges=vector< Edge >;

	struct UnionFind {
		vector<int> data;
		UnionFind(int size):data(size,-1) {}
		bool unite(int x,int y) {
			x=root(x),y=root(y);
			if(x!=y) {
				if(data[y]<data[x]) swap(x,y);
				data[x]+=data[y],data[y]=x;
			}
			return x!=y;
		}
		bool same(int x,int y) {
			return root(x)==root(y);
		}
		int root(int x) {
			return data[x]<0?x:data[x]=root(data[x]);
		}
		int size(int x) {
			return -data[root(x)];
		}
	};

	// Kruskalに必要なライブラリ終了。

	int n;
	Edges edges;

	Kruskal() {}
	Kruskal(int size):n(size) {}

	void add_edge(int u,int v,T c) {
		edges.emplace_back(u,v,c);
	}

	void input(int m) {
		int a,b;T c;
		for(int i=0;i<m;i++) {
			cin>>a>>b>>c;
			add_edge(a,b,c);
		}
	}

	T kruskal() {
		sort(edges.begin(),edges.end());
		UnionFind uf(n);
		T res=0;
		for(auto &e:edges) {
			if(!uf.same(e.from,e.to)) {
				uf.unite(e.from,e.to);
				res+=e.cost;
			}
		}
		return res;
	}
};

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

int main() {

	int n,m;
	Kruskal<int> G(n);
	G.input(m);
	cout<<G.kruskal()<<endl;

	return 0;
}
