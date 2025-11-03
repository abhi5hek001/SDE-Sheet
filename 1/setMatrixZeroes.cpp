#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

void print(vvi nums){
    cout << endl;
    for(auto it: nums){
        for(auto j: it){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void markRow(vvi &nums, int r, int c){
    for(int j=0;j<c;j++){
        if(nums[r][j] != 0)
            nums[r][j] = -1;
    }
}

void markCol(vvi &nums, int r, int c){
    for(int i=0;i<r;i++){
        if(nums[i][c] != 0)
            nums[i][c] = -1;
    }
}

void brute(vvi &nums, int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(nums[i][j] == 0){
                markRow(nums, i, c);
                markCol(nums, r, j);
            }
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(nums[i][j] == -1)
                nums[i][j] = 0;
        }
    }
}

void better(vvi &nums, int r, int c){
    vi row(r, 0);
    vi col(c, 0);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(nums[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(row[i] == 1 || col[j] == 1)
            nums[i][j] = 0;
        }
    }
}

void optimal(vvi &nums, int r, int c){
    int col0 = 1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(nums[i][j] == 0){
                // mark the i'th row -> in 1st col
                nums[i][0] = 0;
                // mark the j'th col -> in 1st row
                if(j!=0)
                    nums[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // for non-markers in nums array
    for(int i = 1;i<r;i++){
        for(int j=1;j<c;j++){
            if(nums[i][j] != 0){
                if(nums[0][j] == 0 || nums[i][0] == 0){
                    nums[i][j] = 0;
                }
            }
        }
    }

    // for markers -> first row will be dependent on nums[0][0]
    if(nums[0][0] == 0){
        for(int j=0;j<c;j++) nums[0][j] = 0;
    }

    // for markers -> first col will be dependent on col0
    if(col0 == 0){
        for(int i=0;i<r;i++) nums[i][0] = 0;
    }
}

void solve() {
    vvi nums = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    cout << "Nums";
    print(nums);

    int r = nums.size();
    int c = nums[0].size();
    // When you're modifying a matrix in-place, changing 1s to 0s immediately can corrupt your original data and unintentionally spread zeros. So instead, you can mark the affected cells with a placeholder (like -1) on the first pass. In the second pass, you then convert all -1s to 0s. This ensures the original matrix structure is preserved during marking.
    brute(nums, r, c);
    cout << "======================\n";
    cout << "Brute Approach\n";
    cout << "TC : O(n*m)*(n+m) + O(n*m)\n";
    cout << "SC : O(1)\n";
    print(nums);
    
    nums = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    // Trying to reduce the extra time taken while marking across the rows and columns for every 0
    // Instead of marking rows and columns immediately when we see a 0 (as in brute),
    // we first record which rows and columns need to be zeroed using two separate marker arrays.
    // Then we update the matrix based on these markers in a second pass.
    better(nums, r, c);
    cout << "======================\n";
    cout << "Better Approach\n";
    cout << "TC : 2*O(n*m)\n";
    cout << "SC : O(n+m)\n";
    print(nums);
    
    nums = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    
    // Scan first row and column to check if they should be zeroed later (row0, col0 flags).
    // Use first row and first column as markers:
    // If nums[i][j] == 0, then mark nums[i][0] = 0 and nums[0][j] = 0.
    // Iterate over the non-marker part (i = 1 to r-1, j = 1 to c-1) and apply zeroes based on markers.
    // Finally, update first row and column if needed.
    optimal(nums, r, c);
    cout << "======================\n";
    cout << "Optimal Approach\n";
    cout << "TC : 2*O(n*m)\n";
    cout << "SC : O(1) [just col0]\n";
    print(nums);
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}