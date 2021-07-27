#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long
#define mod 1000000007

void run_case(){
	int small = 1;
	int big = 1;
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int _small = 4*small + big;
		int _big = small + 2*big;
		
		small = _small%mod;
		big = _big%mod;
	}
	cout<<(small+big)% mod<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
cin>>tc;
while(tc--)run_case();
return 0;
}
