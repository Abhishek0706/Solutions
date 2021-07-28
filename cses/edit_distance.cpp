#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

void run_case(){
	string str1, str2;
	cin>>str1>>str2;
	int n = str1.size(), m = str2.size();
	
	vector<vector<int>> dp(n+1, vector<int>(m+1,0));
	
	for(int i =0;i<=n;i++){
		for(int j = 0;j<=m;j++){
		  
			if(i==0){ 
				dp[i][j] = j; // insert all remaining characters
			}
			else if(j==0){ 
				dp[i][j] = i; // delete all remaining characters
			}
			
			else if(str1[i-1]==str2[j-1]){ 
				dp[i][j] = dp[i-1][j-1]; // no operations
			}
			else{
				dp[i][j] = 1 + min({
					dp[i][j-1], // insert
					dp[i-1][j], //delete
					dp[i-1][j-1] //update
				});
			}
		}
	}
	cout<<dp[n][m]<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
while(tc--)run_case();
return 0;
}
