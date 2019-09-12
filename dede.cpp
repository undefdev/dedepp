#include<vector>
#include<algorithm>
#include<iostream>
#include<bitset>

using namespace std;

const int N = 7;
typedef bitset<N> vect;
typedef bitset<1<<N> boolfunc;
vector<boolfunc> M;

void generate_M(){
	M = vector<boolfunc>();
	for(int i=0; i<(1<<N); ++i) {
		boolfunc row;
		for (int j=0; j<(1<<N); ++j) {
			if ( (vect(i)&~vect(j)) ==0) {
				row |= boolfunc(1<<j);
				cout<<"1";
			}
			else cout<<"0";
		}
		M.push_back(row);
		cout<<endl;
	}
}

long long unsigned dede( boolfunc f, int i ) {
	long long unsigned res = 1;
	//cout<<f<<endl;
	vect juan = vect(i);
	for (int j=i+1; j<(1<<N); ++j) {
		if ( (f&boolfunc( 1<<j )) == 0 )
			res += dede( f | M[j], j );
	}
	return res;
}

int main(){
	generate_M();
	cout<<dede(boolfunc(0), 0)+1;
	return 0;
}

