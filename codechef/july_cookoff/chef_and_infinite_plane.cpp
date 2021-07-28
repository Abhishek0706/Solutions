#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

void run_case(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	// ai --> 1e5
	vector<int> cnt(100001,0);
	for(int i=0;i<n;i++)cnt[a[i]]++;
	int ans = 0;
	for(int i=2;i<100001;i++){
	  ans += min(cnt[i], i-1);
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
