#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

void run_case(){
  int n;cin>>n;
	vector<int> a(n,0);
	for(int i =0;i<n;i++)cin>>a[i];
	vector<int> b = a;
	vector<bool> overall_bit(32,false);

	int ans =a[0];
	for(int i =1;i<n;i++)ans = ans & a[i];
	
	cout<<ans<<' ';
	for(int i =0;i<n;i++){
	  b[i] = (b[i] ^ ans);
	}
	ans = b[0];
	for(int i =1;i<n;i++) ans = ans | b[i];
	cout<<ans<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
cin>>tc;
while(tc--)run_case();
return 0;
}
