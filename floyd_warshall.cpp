#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    int m;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<vector<int>> g(n+1, vector<int>(n+1, INT_MAX));
    //Assuming Directed Graph
    for(int i=0; i<m; i++){
        int u, v, w;
        cout << "Enter the edge and weight: ";
        cin >> u >> v >> w;
        g[u][v] = w;
    }
    for(int i=1; i<=n; i++){
        g[i][i] = 0;
    }
    //Floyd Warshall Algorithm
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(g[i][k] != INT_MAX && g[k][j] != INT_MAX && g[i][k] + g[k][j] < g[i][j]){
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    //Printing the distance matrix
    cout << endl;
    cout << "Distance Matrix: " << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}