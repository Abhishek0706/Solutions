#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

void run_case(){
	int n;
	cin>>n;
	int ans = 0;
	int x = n/6;
	int y = n%6;
	ans = x*15;
	
	if(y==0)ans += 0;
	else if(y<=2)ans +=5; // replace one 6 with 8
	else if(y<=4)ans +=10; // replate one 6 with 10
	else ans += 15; // add one 6
	
	// in case of less than 6 slices we need spend atleast 15 coins 
	// to get a pizza of 6 slices(min val)
	cout<<max(15ll,ans)<<endl;
	
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
cin>>tc;
while(tc--)run_case();
return 0;
}
