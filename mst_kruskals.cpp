#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b){
  return a[2]<b[2];
}

int findParent(vector<int> &parent, int node){
  if(parent[node]==node){
    return node;
  }
  return parent[node] = findParent(parent, parent[node]);
}


void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
  u = findParent(parent,u);
  v = findParent(parent,v);

  if(rank[u] < rank[v]) 
    parent[u] = v;
  else if(rank[v] < rank[u]) 
    parent[v] = u;
  else{
    parent[v] = u;
    rank[u]++;
  }
  
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  sort(edges.begin(),edges.end(),cmp);
  vector<int> parent(n);
  vector<int> rank(n,0);
  for(int i=0; i<n; i++){
    parent[i] = i;
  }
  int minWeight = 0;
  cout << endl << "Following are the edges in the constructed MST - " << endl;
  for(int i=0; i<edges.size(); i++){
    int u = findParent(parent,edges[i][0]);
    int v = findParent(parent,edges[i][1]);
    int wt = edges[i][2];
    if(u!=v){
      minWeight += wt;
      unionSet(u, v, parent, rank);
      cout << edges[i][0] << " " << edges[i][1] << endl;
    }    

  }
  cout << endl;
  return minWeight;

}

int main(){
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    int m;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<vector<int>> g;
    for(int i=0; i<m; i++){
        int u, v, w;
        cout << "Enter the edge and weight: ";
        cin >> u >> v >> w;
        g.push_back({u,v,w});
    }
    cout << "Cost of Minimum Spanning Tree: " << minimumSpanningTree(g,n) << endl;
}
