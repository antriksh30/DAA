#include <bits/stdc++.h>
using namespace std;


void solve(int n, vector<int>& v, int target, int i, set<vector<int>>&ans, vector<int> output){
    //base case
    if(target<0) return;
    if(target==0){
        ans.insert(output);
        return;
    }
    if(i>=n) return;
    
    // solve(n,v,target,i+1,ans, output);
    // output.push_back(v[i]);
    // solve(n,v,target-v[i],i+1,ans, output);
       
    //recursive case
    for(int j = i; j < n; j++){
        if(target-v[j]<0) break;
        output.push_back(v[j]);
        solve(n,v,target-v[j],j+1,ans, output);
        output.pop_back();
        while (j + 1 < v.size() && v[j] == v[j + 1]) j++;
    }
    
}   

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin>>n;
    vector<int> v(n);
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++){ 
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int target;
    cout << "Enter the target sum: ";
    cin>>target;
    set<vector<int>> ans;
    vector<int> output;
    solve(n,v,target,0, ans, output);
    
    cout << endl << "The subsets are: " << endl;
    for(auto it: ans){
        cout << "[";
        for(int i=0; i<it.size(); i++){
            cout << it[i];
            if(i!=it.size()-1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}