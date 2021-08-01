#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long
const int mod = 1e9 + 7;

void run_case(){
  int n;
  cin>>n;
  
  // total sum would be n*(n+1)/2
  int sum = n*(n+1)/2;
  if(sum%2!=0){
    cout<<0<<endl;
    return;
  }
  // half of total sum = n*(n+1)/4 = sum/2
  int target = sum/2;
  
  // leaving coin with value = n
  // coz {1,3,4,6}{2,5,7}
  // and {2,5,7}{1,3,4,6}
  // are two same ans and we need to count it as one
  // so we are saying if we need coin=n then
  // take it only in second set 
  // and we will calculate number of first set
  // thats why we are calculating target with only coin in set[1,n-1]
  vector<int> a;
  for(int i=0;i<n-1;i++)a.push_back(i+1);
  
  // kind of knapsack problem 
  // in which instead of T/F we need to find the number if ways
  
  vector<int> curr(target+1,0);
  curr[0]=1;
  curr[a[0]]=1;
  for(int i=1;i<n-1;i++){
    vector<int> temp = curr;
    int coin = a[i];
    for(int j=0;j<=target;j++){
      
      //leave that coin 
      //req target will be same
      //take value from above column
      curr[j] = temp[j];
      
      //checking if we can take that coin
      //only possible if the remaining target is
      //greater than or equal to zero
      if(j-coin>=0)curr[j] += temp[j-coin];
      curr[j] %= mod;
    }
  }
  // printing number of ways to get req target
  cout<< curr[target]<<endl;
  
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
while(tc--)run_case();
return 0;
}
