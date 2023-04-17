#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //create adj list
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i=0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    vector<int> key(n+1,INT_MAX);
    vector<bool> mst(n+1,false);
    vector<int> parent(n+1,-1);

    //algorithm
    key[1] = 0;
    
    for(int i=1; i<=n; i++){
        int mini = INT_MAX;
        int u;
        for(int v=1; v<=n; v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }
        mst[u] = true;
        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && key[v] > w ){
                key[v] = w;
                parent[v] = u;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> ans;

    for(int i=2; i<=n; i++){
      ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    int m;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<pair<pair<int, int>, int>> g;
    for(int i=0; i<m; i++){
        int u, v, w;
        cout << "Enter the edge and weight: ";
        cin >> u >> v >> w;
        g.push_back({{u,v},w});
    }
    vector<pair<pair<int, int>, int>> ans = calculatePrimsMST(n, m, g);
    cout << endl;
    cout << "MST edges are: " << endl;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << endl;
    }

    return 0;
}