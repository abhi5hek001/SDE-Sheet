#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> board, int n){
    int duprow = row;
    int dupcol = col;
    // upper left diagonal
    while(row >= 0 && col >= 0){
        if(board[row--][col--] == 'Q') return false;
    }
    
    row = duprow;
    col = dupcol;
    // left row
    while(col >= 0){
        if(board[row][col--] == 'Q') return false;
    }
    
    row = duprow;
    col = dupcol;
    // lower left diagonal
    while(row < n && col >= 0){
        if(board[row++][col--] == 'Q') return false;
    }

    return true;
}

void bruteSolution(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    
    for(int row = 0;row<n;row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            bruteSolution(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

void optimalSolution(int col, vector<string> &board, vector<vector<string>> &ans2, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n){
    if(col == n){
        ans2.push_back(board);
        return;
    }

    for(int row = 0;row<n;row++){
        if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0){
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[n-1+col-row] = 1;
            optimalSolution(col+1, board, ans2, leftRow, upperDiagonal, lowerDiagonal, n);
            // backtracking
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[n-1+col-row] = 0;
        }
    }
}

void solveNQueens(int n, vector<vector<string>> &ans, vector<vector<string>> &ans2) {
    vector<string> board(n);
    string s(n, '.');
    for(int i=0;i<n;i++){
        board[i] = s;
    }

    bruteSolution(0, board, ans, n); 
    
    vector<int> leftRow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
    optimalSolution(0, board, ans2, leftRow, upperDiagonal, lowerDiagonal, n);
}   

signed main() {
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    int t = 1;
    // cin >> t;
    vector<vector<string>> ans;
    vector<vector<string>> ans2;
    int n = 4;
    while (t--) {
        solveNQueens(n, ans, ans2);
    }
    
    cout << "Normal Solution" << endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<n;j++){
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    cout << "Optimal Solution" << endl;
    for(int i=0;i<ans2.size();i++){
        for(int j=0;j<n;j++){
            cout << ans2[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
} 