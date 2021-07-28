#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

void run_case(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
	  cin>>a[i];
	}
	int minval = *min_element(a.begin(),a.end());
	
	bool can = true;
	
  int cnt = 0;
  for(auto i : a){
    if(i == minval)cnt++;
  }
  
	for(auto i : a){
	  if(i != minval){
	    if(minval>= (i+1)/2)can = false;
	  }
	}
	
  if(can){
    cout<<n-cnt<<endl;
  }else{
    cout<<n<<endl;
  }
	
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
cin>>tc;
while(tc--)run_case();
return 0;
}
