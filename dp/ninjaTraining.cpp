#include <bits/stdc++.h>
using namespace std;
#include <chrono>

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// Memoization
int findPoints(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    
    if (dp[day][last] != -1)
    return dp[day][last];
    
    int maxi = 0;
    
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + findPoints(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return findPoints(n - 1, 3, points, dp);
}

// Tabulation
int ninjaTrainingTabulation(int n, vvi &points){
    vvi dp(n, vi(4,-1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max((points[0][1]), points[0][2]));

    for(int day = 1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last] = 0;
            for(int task=0;task<3;task++){
                int point = points[day][task] + dp[day-1][task];
                dp[day][last] = max(dp[day][last], point);
            }
        }
    }
    return dp[n-1][3];
}

// Space Optimization
int ninjaTrainingSpaceOptimisation(int n, vvi &points){
    vi prev(4,-1);
    prev[0] = max(points[0][1], points[0][2]);
    prev[0] = max(points[0][0], points[0][2]);
    prev[0] = max(points[0][0], points[0][1]);
    prev[0] = max(points[0][0], max((points[0][1]), points[0][2]));

    for(int day = 1;day<n;day++){
        vi temp(4, 0);
        for(int last=0;last<4;last++){
            temp[last] = 0;
            for(int task=0;task<3;task++){
                int point = points[day][task] + prev[task];
                temp[last] = max(temp[last], point);
            }
        }
        prev = temp;
    }
    return prev[3];
}

void solve()
{
    auto start = chrono::high_resolution_clock::now();

    vvi points = {
        {1,2,5},
        {3,1,1},
        {3,3,3}
    };
    cout << "Result from Memoization: " << ninjaTraining(points.size(), points) << endl;
    cout << "Result from Tabulation: " << ninjaTrainingTabulation(points.size(), points) << endl;
    cout << "Result from Space Optimisation: " << ninjaTrainingSpaceOptimisation(points.size(), points) << endl;

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout << "\n\nTime taken: " << duration.count() << " ns\n";
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}