#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

void run_case(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &i: a)cin>>i;
	sort(a.begin(),a.end());
	
	// max value = max ai * max n = 1000 * 100 = 1e5
	vector<bool> curr(100001,false);
	
	// initialising the first row
	curr[a[0]] = true;
	curr[0]=true;
	
	for(int i=1;i<n;i++){
	  vector<bool> temp = curr;
	  int coin = a[i];
	  for(int j=0;j<100001;j++){
	    curr[j] = temp[j];// do not take that coin
	    if(j-coin>=0) curr[j] = curr[j] | temp[j-coin]; // take that coin
	  }
	}
	
	// finding possible answers
	vector<int> ans;
	for(int i=1;i<100001;i++){
	  if(curr[i])ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i<<' ';
	cout<<endl;
	
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
while(tc--)run_case();
return 0;
}
