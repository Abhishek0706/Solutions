#include <bits/stdc++.h>
using namespace std;

// input
int n,m;
vector<string> a;

// index of A and B
int starti, startj,endi, endj;

// Validator for inside the grid and visited 
bool valid(int i, int j){
	return i>=0 && j>=0 && i<n && j<m && a[i][j]=='.';
}

void run_case(){
	// Taking input
	cin>>n>>m;
	a = vector<string>(n);
	for(int i =0;i<n;i++)cin>>a[i];
	
	// Storing position of A and B 
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			if(a[i][j]=='A'){
				starti = i;
				startj = j;
			}
			if(a[i][j]=='B'){
				endi = i;
				endj = j;
			}
		}
	}
	
	// Making B as visitable 
	a[endi][endj]= '.';
	
	// Creating and initialising bfs with first node = A(starti, startj)
	queue<pair<int,int>> bfs;
	bfs.push({starti,startj});
	
	// if we find solution, set this to true
	bool found = false;
	
	// loop until we find a solution, or go out of range
	while(!found && !bfs.empty()){
		
		// typical bfs method
		auto f = bfs.front();
		bfs.pop();
		int i = f.first;
		int j = f.second;
		
		// going to all neighbour if possible
		// and storing which type of step we have taken to go there
		// D / U / R / L
		// and setting found = true if we react B(endi , endj)
		if(valid(i+1,j)){
			bfs.push({i+1,j});
			a[i+1][j] = 'D';
			if(i+1==endi && j==endj)found = true;
		}
		if(valid(i-1,j)){
			bfs.push({i-1,j});
			a[i-1][j] = 'U';
			if(i-1==endi && j==endj)found = true;
		}
		if(valid(i,j+1)){
			bfs.push({i,j+1});
			a[i][j+1] = 'R';
			if(i==endi && j+1==endj)found = true;
		}
		if(valid(i,j-1)){
			bfs.push({i,j-1});
			a[i][j-1] = 'L';
			if(i==endi && j-1==endj)found = true;
		}
	}
	
	// Printing No if we do not find any solution
	if(!found){
		cout<<"NO"<<endl;
		return;
	}
	
	// Solution has been found 
	// Now track back
	
	// Initialising ans string
	string ans = "";
	
	// Starting from B to track back
	int curri = endi, currj = endj;
	
	// loop until we react A(starti, startj)
	while(!(curri==starti && currj==startj)){
		
		// storing direction in our answer where we have come
		// it is opposite as while doing bfs
		// because we are going from B to A now
		ans += a[curri][currj];
		switch(a[curri][currj]){
			case 'D':
				curri--;
				break;
			case 'U':
				curri++;
				break;
			case 'R':
				currj--;
				break;
			case 'L':
				currj++;
				break;
		}
	}
	
	// Reverse ans to get path from A to B
	reverse(ans.begin(),ans.end());
	
	// Printing the answer
	cout<<"YES"<<endl;
	cout<<ans.size()<<endl;
	cout<<ans<<endl;
	
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
while(tc--)run_case();
return 0;
}
