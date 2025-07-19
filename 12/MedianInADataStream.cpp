#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

class MedianFinder
{
public:
    vi nums;
    MedianFinder() {}

    //////////////////////////////////////////////////////
    // Using STL
    // Binary search insertion to maintain sorted order
    // void addNum(int num) {
    //     auto pos = lower_bound(nums.begin(), nums.end(), num); // O(log n)
    //     nums.insert(pos, num); // O(n)
    // }
    //////////////////////////////////////////////////////

    //////////////////////////////////////////////////////
    // Without using STL
    // Manually perform binary search to find insert position
    int findInsertPosition(int num)
    {
        int low = 0, high = nums.size();

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < num)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low; // Position where num should be inserted
    }

    // Insert while maintaining sorted order
    void addNum(int num)
    {
        int pos = findInsertPosition(num);

        // Make space for insertion by shifting right
        nums.push_back(0);
        // O(n)
        for (int i = nums.size() - 1; i > pos; --i)
        {
            nums[i] = nums[i - 1];
        }

        nums[pos] = num;
    }
    //////////////////////////////////////////////////////

    double findMedian()
    {
        double median;
        int n = nums.size();
        if (n % 2 == 0)
        {
            median = (nums[n / 2] + nums[(n / 2) - 1]) / 2.0;
        }
        else
        {
            median = nums[n / 2] * 1.0;
        }
        return median;
    }
};

void findMedianBrute()
{
    MedianFinder mobj;
    // MedianFinder* mobj = new MedianFinder();
    // mobj->addNum(1);
    mobj.addNum(1);
    mobj.addNum(2);
    mobj.addNum(5);
    mobj.addNum(6);
    cout << mobj.findMedian() << endl;
    mobj.addNum(3);
    mobj.addNum(7);
    mobj.addNum(8);
    cout << mobj.findMedian() << endl;
}

int signum(int a, int b){
    if(a == b) return 0;
    else if(a > b) return 1;
    else return -1;
}

void callMedian(int elem, vi &nums, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap, double &median){
    switch (signum(maxHeap.size(), minHeap.size()))
    {
    case 0:
        if(elem > median){
            minHeap.push(elem);
            median = minHeap.top();
        }else {
            maxHeap.push(elem);
            median = maxHeap.top();
        }
        break;
    
    case 1:
        if(elem > median){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(elem);
            median = (maxHeap.top() + minHeap.top())/2.0;
        }else{
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(elem);
            median = (maxHeap.top() + minHeap.top())/2.0;
        }
        break;
        
        case -1:
        if(elem > median){
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(elem);
            median = (maxHeap.top() + minHeap.top())/2.0;
        }else {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(elem);
            median = (maxHeap.top() + minHeap.top())/2.0;
        }
        break;
    
    default:
        break;
    }
}

// finding median on running stream
vector<double> findMedianOptimal(vi &nums, int n){
    vector<double> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median = -1;
    for(int i=0;i<n;i++){
        callMedian(nums[i], nums, maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}

void solve()
{
    findMedianBrute();

    vi nums = {2,4,7,3,5,1,4};
    vector<double> ans = findMedianOptimal(nums, nums.size());
    cout << "Optimal Approach" << endl;
    for(auto it: ans){
        cout << it << " ";
    } cout << endl;
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