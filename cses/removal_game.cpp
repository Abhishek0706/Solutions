#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

void run_case(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int &it:a)cin>>it;
	
	vector<vector<int>> dp (n,vector<int> (n,0));
	vector<vector<int>> choose(n,vector<int>(n,-1));
	
	for(int len=1;len<=n;len++){
	  for(int i=0;i<n;i++){
	    int j = i+len-1;
	    if(j>=n)continue;
	    //base case
	    if(len==1){
	      dp[i][j] = a[i];
	      choose[i][j] = i;
	      continue;
	    }
	    if(len==2){
	      //only two elements
	      if(a[i]>=a[j]){
	        dp[i][j] = a[i];
	        choose[i][j]=i;
	      }else{
	        dp[i][j]=a[j];
	        choose[i][j]=j;
	      }
	      continue;
	    }
	    // len >=3
	    
	    int choose_first = a[i] + (choose[i+1][j]==i+1 ? dp[i+2][j] : dp[i+1][j-1]);
	    int choose_last = a[j] + (choose[i][j-1]==i ? dp[i+1][j-1] : dp[i][j-2]);
	    
	    if(choose_first >= choose_last){
	      dp[i][j]=choose_first;
	      choose[i][j] = i;
	    }else{
	      dp[i][j]=choose_last;
	      choose[i][j] = j;
	    }
	  }
	}

	cout<<dp[0][n-1]<<endl;
	
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
while(tc--)run_case();
return 0;
}

/*

4   5   1   3
i  i+1 i+2  j
i  j-2 j-1  j

4 5 1 3

if P1 choose 4 
  then p2 will choose optimal in [5 1 3]
    if choosing 5 is optimal in [5 1 3], then P2 will choose 5
    and final ans for P1 would be 4 + optimal[1 3]
    and if choosing 3 is optimal in [5 1 3], then P2 will choose 3
    and final ans for P1 would be 4 + optimal[5 1]
    
if P1 choose 3
  then P2 will choose optimal in [4 5 1]
    if choosing 4 is optimal in [4 5 1], then P2 will choose 4
    and final ans for P1 would be 3 + optimal [5 1]
    and if choosing 1 is optimal in [4 5 1], then  P2 will choose 1
    and final ans for P1 would be 3 + optimal[4 5]



base cases:
if we have only one element i.e len = 1
then the optimal as is itself

if we have only two element i.e len =2
then optimal ans is choosing max between the two elements
    
    
  
In the above case final ans of P1 is 
= 7 if he choose 4
= 8 if he choose 3

so P1 will choose 3 
now P2 will choose optimal in [4 5 1]
so he choose 4 (both are equivalent choose any)
then P1 will choose optimal between [5 1]
so P1 will choose max(5,1) = 5

so final ans of P1 = 3+5 = 8
    
  


*/
