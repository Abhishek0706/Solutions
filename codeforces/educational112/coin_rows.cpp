#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

void run_case(){
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int &it:a)cin>>it;
	for(int &it:b)cin>>it;
	
	if(n==1){
	  cout<<0<<endl;
	  return;
	}
	
	for(int i=1;i<n;i++)b[i]+=b[i-1];
	for(int i=n-2;i>=0;i--)a[i]+=a[i+1];
	
	int ans = INT_MAX;
	
	for(int i=0;i<n;i++){
	  if(i==0){
	    ans = min(ans,a[i+1]);
	  }
	  if(i==n-1){
	    ans = min(ans,b[i-1]);
	  }
	  ans = min(ans, max(a[i+1],b[i-1]));
	}
	cout<<ans<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
cin>>tc;
while(tc--)run_case();
return 0;
}
