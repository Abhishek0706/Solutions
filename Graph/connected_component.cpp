#include <bits/stdc++.h>
using namespace std;

vector<int> visited;
vector<vector<int>> adjacent;

vector<int> connected;

void dfs(int v){
  visited[v]=true;
  connected.push_back(v);
  for(int x:adjacent[v]){
    if(visited[x] == false){
      dfs(x);
    }
  }
}

signed main(){
  int n,m;
  cin>>n>>m;
  
  visited = vector<int> (n, false);
  adjacent = vector<vector<int>>(n);
  
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adjacent[u].push_back(v);
    adjacent[v].push_back(u);
  }
  
  for(int i =0;i<n;i++){
    if(visited[i]==false){
      connected.clear();
      dfs(i);
      for(int j:connected){
        cout<<j<<' ';
      }
      cout<<endl;
    }
  }
  return 0;
}
/*
Test Case: 
8 6
0 1 
1 2
1 3
0 4 
5 6
5 7
*/
