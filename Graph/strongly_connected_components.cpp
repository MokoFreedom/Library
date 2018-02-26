#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// O(V+E)
//
// G:	  グラフの隣接リスト表現
// rG:	  辺の向きを逆向きにしたグラフ
// edges: 辺の集合
// comp:  属する強連結成分のトポロジカル順序
// order: 帰りがけ順の並び
// used:  既に調べたか

// THE BEGINNING OF THE LIBRARY

typedef pair<int,int> Pii;
typedef vector< vector<int> > Graph;

struct StronglyConnectedComponents {
	Graph G,rG;
	vector<Pii> edges;
	vector<int> comp,order,used;

	StronglyConnectedComponents(size_t v):G(v),rG(v),comp(v,-1),used(v,0) {}

	void add_edge(int x,int y) {
		G[x].push_back(y);
		rG[y].push_back(x);
		edges.emplace_back(x,y);
	}

	void input(int m,int offset=0) {
		int a,b;
		for(int i=0;i<m;i++) {
			cin>>a>>b;
			a--,b--;
			add_edge(a,b);
		}
	}

	int operator[](int k) {
		return (comp[k]);
	}

	void dfs(int v) {
		if(used[v]) return;
		used[v]=1;
		for(auto u:G[v]) dfs(u);
		order.push_back(v);
	}

	void rdfs(int v,int cnt) {
		if(comp[v]!=-1) return;
		comp[v]=cnt;
		for(auto u:rG[v]) rdfs(u,cnt);
	}

	void build(Graph &t) {
		for(int i=0;i<(int)G.size();i++) dfs(i);
		reverse(order.begin(),order.end());
		int cnt=0;
		for(auto idx:order) if(comp[idx]==-1) rdfs(idx,cnt),cnt++;

		t.resize(cnt);
		set<Pii> connect;
		for(auto &e:edges) {
			int v=comp[e.first],u=comp[e.second];
			if(v==u) continue;
			if(connect.count(Pii(v,u))) continue;
			t[v].push_back(u);
			connect.emplace(v,u);
		}
	}
};

// THE ENDING OF THE LIBRARY
// THE FOLLOWING IS AN EXAMPLE OF USE

int main() {

	int n,m;
	cin>>n>>m;
	StronglyConnectedComponents graph(n);
	Graph ans;
	graph.input(m);
	graph.build(ans);

	return 0;
}
