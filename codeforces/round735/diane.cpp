#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

void run_case(){
	int n;
	cin>>n;
  string mid;
  
  if(n==1){
    cout<<'a'<<endl;
    return;
  }
  if(n==2){
    cout<<"ab"<<endl;
    return;
  }
  
	if(n%2==0){
	  mid = "x";
	  n -=1;
	}else {
	  mid = "xy";
	  n -=2;
	}
	for(int i=0;i<(n/2);i++){
	  cout<<'a';
	}
	cout<<mid;
	for(int i = 0;i<(n+1)/2;i++){
	  cout<<'a';
	}
	cout<<endl;
	
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
cin>>tc;
while(tc--)run_case();
return 0;
}
