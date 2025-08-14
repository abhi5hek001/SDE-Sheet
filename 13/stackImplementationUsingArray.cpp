#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

class Stack{
    int size;
    int *arr;
    int top;
    
public:
    Stack(){
        top = -1;
        size = 1;
        arr = new int[size];
    }
    void push(int x){
        if(top == size-1){
            cout << "\n***** Stack overflow *****\n\n";
            return;
        }
        arr[++top] = x;
    }
    int pop(){
        if(top == -1){
            cout << "\n***** Stack underflo *****w\n\n";
            return -1;
        }
        return arr[top--];
    }
    int Top(){
        if(top == -1){
            cout << "Stack is empty";
            return -1;
        }
        return arr[top];
    }
    int Size(){
        return top+1;
    }
};

void solve() {
    Stack st;
    st.push(10);
    cout << st.Top() << " is top \n";
    cout << st.Size() << endl;
    st.push(5);
    cout << st.pop() << " is popped \n";
    st.push(7);
    st.push(8);
    cout << st.Top() << " is top \n";
    cout << st.Size() << endl;
    cout << st.pop() << " is popped \n";
    st.push(2);
    cout << st.Top() << " is top \n";
    cout << st.Size() << endl;
    st.push(6);
    cout << st.pop() << " is popped \n";
    cout << st.Size() << endl;
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