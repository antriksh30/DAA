#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string>&board, int n){
    int x = row, y = col;
    //check row
    while(y>=0){
        if(board[x][y]=='Q') return false;
        y--;
    }

    //top left diagonal
    x = row, y = col;
    while(x<n && y>=0){
        if(board[x][y]=='Q') return false;
        x++;
        y--;
    }

    //bottom left diagonal
    x = row, y = col;
    while(x>=0 && y>=0){
        if(board[x][y]=='Q') return false;
        x--;
        y--;
    }
    return true;
}

void solve(int col, vector<string> &board, int n,  vector<vector<string>> &ans){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0; row<n; row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1, board, n, ans);
            board[row][col]='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    string s;
    for(int i=0; i<n; i++) s+='.';
    vector<string> board(n,s);
    vector<vector<string>> ans;
    solve(0, board, n, ans);
    return ans;
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<vector<string>> ans = solveNQueens(n);
    int cnt=1;
    for(auto i: ans){
        cout<<"\nSolution no. "<<cnt++<<endl;
        for(auto j: i){
            cout<<j<<endl;
        }
        cout<<endl;
    }
    return 0;
}
