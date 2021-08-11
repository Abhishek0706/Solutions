#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

signed main(){
  int n,m;
  cin>>n>>m;
  
  //constructing graph
  adj = vector<vector<int>>(n);
  
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  vector<int> visited(n,false);
  // bfs 
  cout<<"bfs"<<endl;
  queue<int> bfs;
  bfs.push(0);
  visited[0]=true;
  while(bfs.empty()==false){
    int front = bfs.front();
    cout<<front<<' ';
    bfs.pop();
    for(int i: adj[front]){
      if(visited[i]==false){
        bfs.push(i);
        visited[i]=true;
      }
    }
  }  cout<<endl;
  
  visited = vector<int>(n,false);
  //dfs
  cout<<"dfs"<<endl;
  stack<int> dfs;
  dfs.push(0);
  visited[0]=true;
  while(dfs.empty()==false){
    int top = dfs.top();
    cout<<top<<' ';
    dfs.pop();
    for(int i : adj[top]){
      if(visited[i]==false){
        dfs.push(i);
        visited[i] = true;
      }
    }
  }  cout<<endl;
  
  return 0;
}
