#include<bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> Qpos,int c){

    if(c == n){
        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                if(Qpos[j] == i){
                    cout << "Q";
                }
                else{
                    cout << "-";
                }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for(int i=0; i<n; i++){
        //need to decide the if row i of column c is valid or not
        bool canPlace = true;

        for(int j=0; j<c; j++){
            if(Qpos[j] == i || Qpos[j] == i+(c-j) || Qpos[j] == i-(c-j)){
                canPlace = false;
                break;
            }
        }

        if(canPlace){
            Qpos.push_back(i);
            solve(n,Qpos,c+1);
            Qpos.pop_back();
        }
    }
}


int main(){
    int n=4;
    vector<int> Qpos;
    solve(n, Qpos, 0);
    return 0;
}