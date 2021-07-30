#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long
 
void run_case(){
  // Taking input
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &it: a)cin>>it;
	
	// sorting the array to apply knapsack
	sort(a.begin(),a.end());
	
	// creating vector for highest sum possible 
	// maxn = 100 , max x = 1000 
	// max sum possible = 100 * 1000 = 1e5
	vector<bool> curr(100001,false);
	
	// we can always create a sum of 0
	curr[0]=true;
	
	// for the first we have only one coin with value a[i]
	// so, sum only sum of a[i] is possible
	curr[a[0]] = true;
	
	// iterating n-1 times to get desired answer
	for(int i =1;i<n;i++){
	  // creating a temp array because we need to update all values simultaneously in a row
	  vector<bool> temp = curr;
	  int coin = a[i];
	  for(int j=0;j<100001;j++){
	    // take that coin
	    curr[j] = temp[j];
	    // checking if we can remove that coin,
	    // only possible if the remaining sum is 
	    // greater than or equal to zero
	    if(j-coin>=0) curr[j] = curr[j] | temp[j-coin];
	  }
	}
	
	// finding all the possible sum we can make
	vector<int> ans;
	for(int i=1;i<100001;i++){
	  if(curr[i])ans.push_back(i);
	}
	
	// printing the answers
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
