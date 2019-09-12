#include<vector>
#include<algorithm>
#include<iostream>
#include<bitset>

using namespace std;

const int N = 4;
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

//long long unsigned dede( boolfunc f, vect juan )

int main(){
	generate_M();
	return 0;
}

