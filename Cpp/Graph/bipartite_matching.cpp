#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// O(VE)

// THE BEGINNING OF THE LIBRARY.

struct BipartiteMatching {
	using UnWeightedGraph=vector< vector<int> >;

	int n;
	UnWeightedGraph G;
	vector<int> match,used;

	BipartiteMatching() {}
	BipartiteMatching(int sz):n(sz),G(sz),match(sz),used(sz) {}

	void add_edge(int u,int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}

	bool dfs(int v) {
		used[v]=true;
		for(auto u:G[v]) {
			int w=match[u];
			if(w<0||(!used[w]&&dfs(w))) {
				match[v]=u;
				match[u]=v;
				return true;
			}
		}
		return false;
	}

	int bipartite_matching() {
		int res=0;
		fill(match.begin(),match.end(),-1);
		for(int v=0;v<n;v++) {
			if(match[v]<0) {
				fill(used.begin(),used.end(),0);
				if(dfs(v)) res++;
			}
		}
		return res;
	}
};

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

int main() {

	int X,Y,E;
	cin>>X>>Y>>E;
	BipartiteMatching bimatch(X+Y);
	for(int i=0;i<E;i++) {
		int x,y;
		cin>>x>>y;
		bimatch.add_edge(x,X+y);
	}
	cout<<bimatch.bipartite_matching()<<endl;

	return 0;
}
