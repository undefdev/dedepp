#include<vector>
#include<algorithm>
#include<iostream>
#include<bitset>

using namespace std;

const int N = 4;
typedef bitset<N> vect;
typedef bitset<1<<N> boolfunc;
vector<boolfunc> M;
int res[1<<N][1<<N];

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


// That's a loooong unsigned long y'have there...
long unsigned long dede( boolfunc f, int i ) {
	long long unsigned res = 1;
	//cout<<f<<endl;
	for (int j=i+1; j<(1<<N); ++j) {
		if ( (f&boolfunc( 1<<j )) == 0 )
			res += dede( f | M[j], j );
	}
	return res;
}

void generate_res();
  for (int i=0; i<(1<<N); ++i) for (int j=i+1; j<(1<<N); ++j) {
      if((M[i] & boolfunc(1<<j))==0)
        res[i][j]= dede(M[i]|M[j], j);
  }
}

int main(){
	generate_M();
	cout<<dede(boolfunc(0), 0)+1<<endl<<endl;
  generate_res();

  for (int i=0; i<(1<<N); ++i) {
    for (int j=0; j<(1<<N); ++j)
      cout<<res[i][j]<<" ";
    cout<<endl;
  }



	return 0;
}

