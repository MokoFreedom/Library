#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// gcd(a,b): 最大公約数
// lcm(a,b): 最小公倍数
// extgcd(a,b,x,y)
// - ax+by=gcd(a,b) となるx,yをユークリッドの互除法を用いて求める。
// - ユークリッドの互除法では
//		g = gcd(a,b) = gcd(b,a%b)
//   という事実に基づいてgを求める。
// - この再帰の前後で、あるx,y,x',y'が存在して、
//		ax+by = bx'+(a%b)y' = g
//   を満たす。
// - a%b = a-b|a/b| を代入すると、
//		ax+by = bx'+(a-b|a/b|)y' = ay'+b(x'-|a/b|y')
// - 係数を比較して
//		x = y',y = x'-|a/b|y'
//   を得る。
//
// 計算量
// 全て: O(log(min(a,b)))

// THE BEGINNING OF THE LIBRARY.

template< typename T >
T gcd(T a,T b) {
	return b ? gcd(b,a%b) : a;
}

template< typename T >
T lcm(T a,T b) {
	return a / gcd(a,b) * b;
}

template< typename T >
T extgcd(T a,T b,T &x,T &y) {
	T g=a;
	x=1,y=0;
	if(b) {
		g = extgcd(b,a%b,y,x);
		y -= (a/b)*x;
	}
	return g;
}

template< typename T >
T mod_inv(T a,T m) {
	T x,y;
	extgcd(a,m,x,y);
	return (m+ x%m)%m;
}

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

int main() {

	ll a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	cout<<lcm(a,b)<<endl;
	ll x,y;
	ll g=extgcd(a,b,x,y);
	cout<<x<<' '<<y<<' '<<g<<endl;

	return 0;
}
