using namespace std;
#include <bits/stdc++.h>

class Heap
{
public:
    int arr[100];
    int size = 0;

    // O(log n)
    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    // O(log n)
    void deleteRootNode()
    {
        if (size == 0)
            return;
        // last element to root node
        arr[1] = arr[size];
        // delete last element
        size--;

        // propagate root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftInd = 2 * i;
            int rightInd = (2 * i) + 1;

            if (leftInd < size && arr[i] < arr[leftInd])
            {
                swap(arr[i], arr[leftInd]);
                i = leftInd;
            }
            else if (rightInd < size && arr[i] < arr[rightInd])
            {
                swap(arr[i], arr[rightInd]);
                i = rightInd;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// O(log n)
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left])
        largest = left;
    if (right <= n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void solve()
{
    // class based implementation
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    cout << "Printing Heap: ";
    h.print();
    h.deleteRootNode();
    cout << "After deleting the root node: ";
    h.print();
    
    // heapify (stand-alone function) based implementation
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // building heap - O(N)
    for (int i = n / 2; i > 0; i--)
        heapify(arr, n, i);

    cout << "printing the array: ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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