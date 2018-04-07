#include <bits/stdc++.h>
using namespace std;

// MEMO
//
//

// THE BEGINNING OF THE LIBRARY

template< typename T >
struct BinaryIndexedTree {
	vector<T> data;

	BinaryIndexedTree(int size):data(size+1,0) {}

	T sum(int k) {
		T res=0;
		for(++k;k>0;k-=(k&-k)) res+=data[k];
		return res;
	}

	void add(int k,T x) {
		for(++k;k<data.size();k+=(k&-k)) data[k]+=x;
	}
};

// THE ENDING OF THE LIBRARY
// THE FOLLOWING IS AN EXAMPLE OF USE

int main() {

	int n,q;
	cin>>n>>q;
	BinaryIndexedTree<long long> tree(n+1);
	while(q--) {
		int type,x,y;
		cin>>type>>x>>y;
		if(type==0) {
			tree.add(x,y);
		}
		else {
			cout<<tree.sum(y)-tree.sum(x-1)<<endl;
		}
	}

	return 0;
}
