#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// MOD素数での組み合わせを求めるのに使う構造体
//
// init(): 階乗とその逆元を前計算する。
// fact(n): nの階乗。
// inv_fact(n): nの階乗の逆元。
// inv(n): nの逆元。
// pow(n,a): nのa乗。
// - 冪乗を高速に求める。全ての自然数は2の冪乗和の組み合わせで表すことができるという性質を利用。
// - nは2の冪乗和で表すことができ、　n=2^k1+2^k2+2^k3+... となる。
// - よって、aのビットが立つ部分iについて、解にx^iを掛けていく。
// perm(n,r): 順列。nPr。
// comb(n,r): コンビネーション。nCr。
// homo(n,r): 重複組み合わせ。n-r+1Cr。
//
// -計算量-
// init: O(N + log MOD)
// pow: O(log N)
// その他: O(1) (多分)

// THE BEGINNING OF THE LIBRARY.

template< typename T >
struct Combination {
	vector<T> fc,ifc;
	T MOD;
	int sz;

	Combination(T MOD,T sz):fc(sz+1),ifc(sz+1),MOD(MOD),sz(sz) {}

	void init() {
		fc[0]=1;
		for(int i=1;i<=sz;i++) fc[i]=fc[i-1]*i%MOD;
		ifc[sz]=inv(fc[sz]);
		for(int i=sz-1;i>=0;i--) ifc[i]=ifc[i+1]*(i+1)%MOD;
	}

	// 階乗
	T fact(int n) {
		return fc[n];
	}
	// 階乗の逆元
	T inv_fact(int n) {
		return ifc[n];
	}
	//逆元
	T inv(int n) {
		return pow(n,MOD-2);
	}
	// 冪乗
	T pow(T n,int a) {
		T res=1;
		while(a>0) {
			if(a&1) (res*=n)%=MOD;
			(n*=n)%=MOD;
			a>>=1;
		}
		return res;
	}
	// 順列
	T perm(T n,T r) {
		if(r<0||n<r) return 0;
		return fc[n]*ifc[n-r]%MOD;
	}
	// 組み合わせ
	T comb(T n,T r) {
		if(r<0||n<r) return 0;
		return fc[n]*ifc[r]%MOD*ifc[n-r]%MOD;
	}
	// 重複組み合わせ
	T homo(T n,T r) {
		if(n<0||r<0) return 0;
		return r==0?1:comb(n+r-1,r);
	}
};

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

int main() {
	return 0;
}
