#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

void run_case(){
	int x,y;
	cin>>x>>y;
	if(__gcd(x,y)>1){
	  cout<<0<<endl;
	  return;
	}
	if(__gcd(x+1,y)>1 || __gcd(x,y+1)>1){
	  cout<<1<<endl;
	  return;
	}
	cout<<2<<endl;
	
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
cin>>tc;
while(tc--)run_case();
return 0;
}
