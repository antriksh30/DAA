#include <bits/stdc++.h>
using namespace std;
#define V 4
int travllingSalesmanProblem(int graph[][V], int s)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
 
    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}
int main()
{
    int graph[][V] = { { 0, 20, 25, 10 },
                       { 20, 0, 35, 15 },
                       { 25, 35, 0, 30 },
                       { 20, 15, 30, 0 } };
    int s = 0;
    cout << "Distance Matrix: " << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    cout << "Shortest Path is: " << travllingSalesmanProblem(graph, s);
    return 0;
}
