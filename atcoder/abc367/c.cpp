#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ALL(a) a.begin(), a.end()
#define ss second
#define test if(te) cout

using namespace std;

const bool te = 0;

int n, s, k;
vector < int > r, path;

void dfs(int m) {
    // cout<<"dfs"<<m<<endl;
    if (m == n) {
        if (s % k == 0) {
            for (int i = 0;i < n;i++) {
                cout << path[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 1;i <= r[m];i++) {
        s += i;
        path.pb(i);
        dfs(m + 1);
        path.pop_back();
        s -= i;
    }
}

int main() {
    int i, j;
    cin >> n >> k;
    r.resize(n);
    for (i = 0;i < n;i++) {
        cin >> r[i];
    }
    s = 0;
    dfs(0);
}