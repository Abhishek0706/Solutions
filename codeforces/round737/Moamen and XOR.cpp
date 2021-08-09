#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

const int M = 1000000007;
const int N = 200001ll;
vector<int> fact(N,0);
vector<int> rfact(N,0);

int pow_mod(int a, int n){
	if(n==0) return 1ll;
	if(n%2==0){
		int temp = pow_mod(a,n/2);
		return (temp*temp)%M;
	}
	return (a * pow_mod(a,n-1ll))%M;
}

void fact_rfact_calc(){
	fact[0]=1ll;
	rfact[0]=1ll;
	for(int i=1ll;i<N;i++){
		fact[i]=(i*fact[i-1ll])%M;
		rfact[i]=(rfact[i-1ll]*pow_mod(i,M-2))%M;
	}
}

int choose(int n, int r){
	if (r < 0 || r > n) return 0;
	int temp = fact[n];
	temp *= rfact[r]; temp %= M;
	temp *= rfact[n-r]; temp %= M;
	return temp;
}

int pow2(int n){
  if(n==0)return 1ll;
  if(n%2==0){
    int temp = pow2(n/2);
    return (temp*temp)%M;
  }
  return (2*pow2(n-1ll))%M;
}

void odd(int n,int k){
  int temp = 0;
  for(int i=0;i<n;i+=2){
    temp += choose(n,i);
    temp %=M;
  }
  int ans = 1ll;
  
  for(int i=0;i<k;i++){
    ans *= (1ll + temp);
    ans %=M;
  }
  cout<<ans<<endl;
  return;
}

void even(int n, int k){
  
  int temp = 0;
  for(int i=0;i<n;i+=2){
    temp += choose(n,i);
    temp %=M;
  }
  
  int ans = 1ll;
  for(int i=0;i<k;i++){
    ans *= temp;
    ans %=M;
  }
  
  vector<int> equal(k);
  equal[0] = temp;
  for(int i =1;i<k;i++){
    equal[i] = (equal[i-1]*temp)%M;
  }
  int pow2n = pow2(n);
  temp =1ll;
  for(int i=0;i<k;i++){
    if(k-i-2>=0 && k-i-2<k)
      ans += equal[k-i-2]*temp;
    else 
      ans += temp;
    ans %=M;
    temp *= pow2n;
    temp %=M;
  }
  cout<<ans<<endl;
  return;
}


void run_case(){
	int n,k;
	cin>>n>>k;
	
	if(k==0){
	  cout<<1<<endl;
	  return;
	}
	
	if(n%2)
	  odd(n,k);
	else 
	  even(n,k);
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1ll;
fact_rfact_calc();
cin>>tc;
while(tc--)run_case();
return 0;
}

// need equal or greater

/*
n = odd
case 1 : all of the bits are 1
then 'and' will give 1
and 'xor' will also give 1(n is odd)

in this case 'and' = 'xor'

case 2 : some of bits are 0
then 'and' will give 0 
and 'xor' will give 0 if(cnt of 1 = even)
and 'xor' will give 1 if(cnt of 1 = odd)
we need even cnt of 1
so number of ways = nC0 + nC2 + ...... + nC(n-1)
n-1 is last even number

we will do this for each bit from 1 to k


n = even
case 2: some of bits are 0
'and' will give 0 
to get 0 from xor,
the number of ways are nC0 + nC2 + ..... nCn-2 
we do not have nCn because it would be our case 1 where all bits are 1
we will do this for each bit from 1 to k



case 1 : all bits are 1 
then and will give 1 
      xor will give 0
      
      and :1 0 1 0 0 0 1 -> 4
      xor :1 0 0 1 0 1 0
      
      x 
      x * x 
      x * x * x
      
      2 
      2 * 2 = 2 n
      
after this bit we can have any combination of 0 and 1s (2^y, y is remaining number of bits) 
because our and has already become greater than xor
In this case what will be added in the answer,
ways to make previous bits equal (0 in both and and xor/ 1 in both and and xor) * (2^y), where y is the number of next remaining bits


*/
