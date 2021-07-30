#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

void run_case(){
	int W,H;
	cin>>W>>H;
	
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	
	int w,h;
	cin>>w>>h;
	
	int a = x1;
	int b = W-x2;
	int c = y1;
	int d = H-y2;
	
	if(c+d<h && a+b <w){
	  cout<<-1<<endl;
	  return;
	}
	
	int adj_hor,adj_ver;
	
	if(c+d>=h)
	  adj_ver = min(max(0ll,h-d),max(0ll,h-c));
	else 
	  adj_ver = INT_MAX;
	  
  if(a+b>=w)
	  adj_hor = min(max(0ll,w-a),max(0ll,w-b));
	else 
	  adj_hor = INT_MAX;
	  
  
	std::cout << std::fixed;
  std::cout << std::setprecision(9);
	
	cout<< double(min(adj_hor,adj_ver))<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
cin>>tc;
while(tc--)run_case();
return 0;
}
