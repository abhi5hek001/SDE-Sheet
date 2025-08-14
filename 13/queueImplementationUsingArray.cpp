#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

class Queue{
    int *arr;
    int size;
    int front;
    int back;

public:
    Queue(){
        size = 100;
        front = 0;
        back = 0;
        arr = new int[size];
    }
    void push(int x){
        if(back == size){
            cout << "Queue overflow";
            return;
        }
        arr[back++] = x;
    }
    int pop(){
        if(front == back){ //queue is empty
            cout << "Queue is empty ";
            return -1;
        }
        return arr[front++];
    }
    int Size(){
        return (back - front);
    }
    int Top(){
        if(front == back){
            cout << "Queue is empty ";
            return -1;
        }
        return arr[front];
    }
};

void solve() {
    Queue q;
    q.push(10);
    cout << q.Top() << " is top \n";
    cout << q.Size() << endl;
    q.push(5);
    cout << q.pop() << " is popped \n";
    q.push(7);
    q.push(8);
    cout << q.Top() << " is top \n";
    cout << q.Size() << endl;
    cout << q.pop() << " is popped \n";
    q.push(2);
    cout << q.Top() << " is top \n";
    cout << q.Size() << endl;
    q.push(6);
    cout << q.pop() << " is popped \n";
    cout << q.Size() << endl;
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