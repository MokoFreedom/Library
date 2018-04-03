#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// O(FE)
// Fは最大流の流量。最悪F回深さ優先探索。
// 容量が無理数の場合、有限回の操作で終了しない。
// ソース->集合A->集合B->シンク、と容量1の辺を張ると最大流が最大マッチングに。

// THE BEGINNING OF THE LIBRARY.

template< typename T >
struct FordFulkerson {

	struct FlowEdge {
		int to;
		T cap,rev;
		FlowEdge() {}
		FlowEdge(int to,T cap,T rev):to(to),cap(cap),rev(rev) {}
	};

	vector< vector<FlowEdge> > G;
	vector<int> used;
	const T INF;
	int timestamp;

	FordFulkerson() {}
	FordFulkerson(int n):INF(numeric_limits<T>::max()),timestamp(0) {
		G.resize(n);
		used.assign(n,-1);
	}

	void add_edge(int from,int to,T cap) {
		G[from].emplace_back(to,cap,(int)G[to].size());
		// undirected
		// G[to].emplace_back(from,cap,(int)G[from].size()-1);
		// directed
		G[to].emplace_back(from,0,(int)G[from].size()-1);
	}

	T dfs(int v,const int t,T flow) {
		if(v==t) return flow;
		used[v]=timestamp;
		for(auto &e:G[v]) {
			if(used[e.to]==timestamp||e.cap<=0) continue;
			T d=dfs(e.to,t,min(flow,e.cap));
			if(d>0) {
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
		return 0;
	}

	T max_flow(int s,int t,T lim) {
		T flow=0;
		for(T f;(f=dfs(s,t,lim))>0;timestamp++) flow+=f;
		return flow;
	}

	T max_flow(int s,int t) {
		return max_flow(s,t,INF);
	}
};

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

int main() {

	int V,E;
	cin>>V>>E;
	FordFulkerson<int> F(V);
	while(E--) {
		int u,v,c;
		cin>>u>>v>>c;
		F.add_edge(u,v,c);
	}
	cout<<F.max_flow(0,v-1)<<endl;

	return 0;
}
