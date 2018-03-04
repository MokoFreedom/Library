#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// 0-indexed
//
// LazySegmentTree(n,f,g,h,p,NODE_INIT,LAZY_INIT):
//		n: サイズnのセグ木の初期化。
//		f: 要素と要素のマージ。
//		g: 要素と作用素のマージ。
//		h: 作用素と作用素のマージ。
//		p: 作用素を下に降ろす時に行う演算。(第1引数は作用素の元の値、第2引数は降ろした後の区間の長さ)
//		NODE_INIT: 要素の単位元
//		LAZY_INIT: 作用素の単位元。
// set(k,x): k番目の要素をxで初期化する。
// build(): 構築する。
// query(l,r): 区間[l,r)に対して２項演算した結果を返す。
// update(a,b,x): 区間[a,b)をxで更新する。
// eval(k,len): k番目の要素の遅延評価。

// THE BEGINNING OF THE LIBRARY

template< typename T,typename L=T >
struct LazySegmentTree {
	using F=function< T(T,T) >;
	using G=function< T(T,L) >;
	using H=function< L(L,L) >;
	using P=function< L(L,int) >;

	int sz;
	vector<T> node;
	vector<L> lazy;
	const F f;
	const G g;
	const H h;
	const P p;
	const T NODE_INIT;
	const L LAZY_INIT;

	LazySegmentTree(int n,const F f,const G g,const H h,const P p,
					const T &NODE_INIT,const L &LAZY_INIT):
		f(f),g(g),h(h),p(p),NODE_INIT(NODE_INIT),LAZY_INIT(LAZY_INIT) {
		sz=1;
		while(sz<n) sz<<=1;
		node.assign(2*sz-1,NODE_INIT);
		lazy.assign(2*sz-1,LAZY_INIT);
	}

	void set(int k,const T &x) {
		node[k+sz-1]=x;
	}

	void build() {
		for(int i=sz-2;i>=0;i--) {
			node[i]=f(node[i*2+1],node[i*2+2]);
		}
	}

	void eval(int k,int len) {
		if(lazy[k]!=LAZY_INIT) {
			if(k<sz-1) {
				lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);
				lazy[2*k+2]=h(lazy[2*k+2],lazy[k]);
			}
			node[k]=g(node[k],p(lazy[k],len));
			lazy[k]=LAZY_INIT;
		}
	}

	T update(int a,int b,const T &x,int k,int l,int r) {
		eval(k,r-l);
		if(r<=a||b<=l) return node[k];
		else if(a<=l&&r<=b) {
			lazy[k]=h(lazy[k],x);
			eval(k,r-l);
			return node[k];
		}
		else {
			node[k]=f(update(a,b,x,2*k+1,l,(l+r)/2),update(a,b,x,2*k+2,(l+r)/2,r));
			return node[k];
		}
	}

	T update(int a,int b,const T &x) {
		return update(a,b,x,0,0,sz);
	}

	T query(int a,int b,int k,int l,int r) {
		eval(k,r-l);
		if(r<=a||b<=l) return NODE_INIT;
		else if(a<=l&&r<=b) return node[k];
		else return f(query(a,b,2*k+1,l,(l+r)/2),query(a,b,2*k+2,(l+r)/2,r));
	}

	T query(int a,int b) {
		return query(a,b,0,0,sz);
	}

	void show() {
		for(int i=0;i<sz*2-1;i++) cout<<node[i]<<' ';
		cout<<endl;
	}
};

// THE ENDING OF THE LIBRARY
// THE FOLLOWING IS AN EXAMPLE

typedef int TYPE;

int main() {

	auto add=[](TYPE a,TYPE b){ return a+b; }; // 加算
	auto multipy=[](TYPE a,TYPE b){ return a*b; }; // 乗算

	int n,q;
	cin>>n>>q;

	LazySegmentTree<TYPE> tree(n,add,add,add,multipy,0,0);

	while(q--) {
		int type,s,t;TYPE x;
		cin>>type>>s>>t;
		s--,t--;
		if(type==0) {
			cin>>x;
			tree.update(s,t+1,x);
		}
		else {
			cout<<tree.query(s,t+1)<<endl;
		}
	}

	return 0;
}
