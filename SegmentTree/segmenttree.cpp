#include <bits/stdc++.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18

// MEMO
//
// 0-indexed
//
// build: O(N)
// query,update: O(log N)
//
// SegmentTree(n,f,INIT): サイズnのセグ木の初期化。fは2つの要素をマージする2項演算。INITは単位元。
// set(k,x): k番目の要素をxで初期化する。
// build(): 構築する。
// query(l,r): 区間[l,r)に対して２項演算した結果を返す。
// update(k,x): k番目の要素をxに変更する。

// THE BEGINNING OF THE LIBRARY

template< typename T >
struct SegmentTree {
	using F=function< T(T,T) >;

	int sz;
	vector<T> node;

	const F f; // 比較関数
	const T INIT; // 初期化値

	SegmentTree(int n,const F f,const T &INIT):f(f),INIT(INIT) {
		sz=1;
		while(sz<n) sz<<=1;
		node.assign(2*sz-1,INIT);
	}

	void set(int k,const T &x) {
		node[k+sz-1]=x;
	}

	void build() {
		for(int k=sz-2;k>=0;k--) {
			node[k]=f(node[2*k+1],node[2*k+2]);
		}
	}

	void update(int k,const T &x) {
		k+=sz-1;
		node[k]=x;
		while(k>0) {
			k=(k-1)/2;
			node[k]=f(node[k*2+1],node[k*2+2]);
		}
	}

	T query(int a,int b,int k,int l,int r) {
		if(r<=a||b<=l) return INIT;
		if(a<=l&&r<=b) return node[k];
		T vl=query(a,b,k*2+1,l,(l+r)/2);
		T vr=query(a,b,k*2+2,(l+r)/2,r);
		return f(vl,vr);
	}

	T query(int a,int b) {
		return query(a,b,0,0,sz);
	}

	// デバッグ用。nodeの値を全て表示して改行。
	void show() {
		for(int i=0;i<sz*2-1;i++) cout<<node[i]<<' ';
		cout<<endl;
	}
};

// THE ENDING OF THE LIBRARY
// THE FOLLOWING IS AN EXAMPLE OF USE

int main() {

	auto range_min=[](int a,int b){ return min(a,b); }; //区間min
	auto range_max=[](int a,int b){ return max(a,b); }; //区間max
	auto range_sum=[](int a,int b){ return a+b; }; //区間sum

	int n,q;
	cin>>n>>q;
	SegmentTree<int> min_tree(n,range_min,INF);
	SegmentTree<int> max_tree(n,range_max,0);
	SegmentTree<int> sum_tree(n,range_sum,0);

	while(q--) {
		int type,a,b;
		cin>>type>>a>>b;
		if(type==0) {
			min_tree.update(a,b);
			max_tree.update(a,b);
			sum_tree.update(a,b);
			//cout<<"min: ";min_tree.show();
			//cout<<"max: ";max_tree.show();
			//cout<<"sum: ";sum_tree.show();
		}
		else {
			cout<<min_tree.query(a,b+1)<<endl;
			cout<<max_tree.query(a,b+1)<<endl;
			cout<<sum_tree.query(a,b+1)<<endl;
		}
	}


	return 0;
}
