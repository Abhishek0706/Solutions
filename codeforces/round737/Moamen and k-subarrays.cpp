#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

void run_case(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(auto &it:a)cin>>it;
	
	vector<int> b = a;
	sort(b.begin(),b.end());
	
	map<int,int> index;
	for(int i=0;i<n;i++)index[a[i]]=i;
	
	
	for(int i=0;i<n-1;i++){
	  int i1 = index[b[i]];
	  int i2 = index[b[i+1]];
	  if(i1+1!=i2)k--;
	}
	
	cout<<(k>0?"YES":"NO")<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
cin>>tc;
while(tc--)run_case();
return 0;
}

/*

2 5 4 7 8
sorted
2 4 5 7 8

index of 4 = index of 2 + 2 -> cnt++
index of 5 = index of 4 - 1 -> cnt++
index of 7 = index of 5 + 2 -> cnt++
index of 8 = index of 7 + 1 -> no increment

final breakage
[2], [4], [5], [7,8] -> 4
[2], [4], [5], [7],[8] -> 5
