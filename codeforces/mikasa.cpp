// problem : https://codeforces.com/problemset/problem/1554/C

#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

void run_case(){
	int n,m;
	cin>>n>>m;
	m++;
	string bits_n = bitset<32>(n).to_string();
	string bits_m = bitset<32>(m).to_string();
	string ans(32,0);
	
	bool b = false;
	for(int i=0;i<32;i++){
	  
	  if(b){
	    ans[i]='0';
	    continue;
	  }
	  
	  if(bits_m[i]=='1'){
	    if(bits_n[i]=='0'){
	      ans[i]='1';
	    }else{
	      ans[i]='0';
	    }
	  }else{
	    // m = '0'
	    if(bits_n[i]=='1'){
	      ans[i]='0';
	      b=true;
	    }else{
	      ans[i]='0';
	    }
	  }
	}

	cout<<stoll(ans,0,2)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
cin>>tc;
while(tc--)run_case();
return 0;
}
/*

a ^ a = 0
a ^ 0 = a
a ^ b = b ^ a

n ^ x = k
n ^ x ^ x = k^x
n = k ^ x
n ^ k = k ^ x ^ k = x ^ k ^k = x
n ^ k = x

0 0 0 1 0 0 0 1 0 1
1 0 1 0 0 0 0 0 0 0 
-----------------------
1 0 1 1 0 0 0 1 0 1
-----------------------
1 0 1 0 1 1 1 0 0 1

*/
