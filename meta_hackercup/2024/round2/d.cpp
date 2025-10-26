#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define BOOST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define test if(TEST) cout

using namespace std;

const bool TEST = 0;

class FenwickTree2D {
    int n, m;
    vector<vector<map<int, int>>> bit;  // 2D Fenwick Tree structure storing counts for each number

    void update(int x, int y, int num, int delta) {
        for (int i = x; i < n; i |= i + 1) {
            for (int j = y; j < m; j |= j + 1) {
                bit[i][j][num] += delta;
            }
        }
    }

    int query(int x, int y, int num) {
        int sum = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
                sum += bit[i][j][num];
            }
        }
        return sum;
    }

public:
    FenwickTree2D(int n, int m) : n(n), m(m), bit(n, vector<map<int, int>>(m)) {}

    void build(const vector<vector<int>>& matrix) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                update(i, j, matrix[i][j], 1);
            }
        }
    }

    int query(int x1, int y1, int x2, int y2, int num) {
        return query(x2, y2, num) - query(x1 - 1, y2, num) - query(x2, y1 - 1, num) + query(x1 - 1, y1 - 1, num);
    }
};


ll check(int k, int n, int m, FenwickTree2D& tree, vector < vector< int>>& a) {
    ll res = 0, all;
    for (int i = 0; i < n;i++) {
        for (int j = 0;j < m;j++) {
            all = (min(n - 1, i + k) - max(0, i - k)+1) * (min(m - 1, j + k) - max(0, j - k)+1);
            int val = tree.query(max(0, i - k), max(0, j - k), min(n - 1, i + k), min(m - 1, j + k), a[i][j]);
            res += all - val;
            // cout<<i _ j _ all _ val _ a[i][j]
        }
    }
    return res;
}

void solve() {
    int n, m, i, j, k, s, mid, cnt;
    cin >> n >> m >> k;
    vector a(n, vector(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    FenwickTree2D tree(n, m);
    tree.build(a);
    int l = 1, r = min(n, m) - 1;
    while (l < r) {
        mid = (l + r) / 2;
        cnt = check(mid, n, m, tree, a);
        cout<<mid _ cnt<<endl;
        if (cnt < k) l = mid + 1;
        else r = mid;
    }
    cout << l << endl;
}

int main() {
    // freopen("bunny_hopscotch_input (1).txt", "r", stdin);
    freopen("in.txt", "r", stdin);

    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1;i <= t;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    // std::vector<int> vec;
    // std::cout << "Maximum size of vector on this system is: " << vec.max_size() << std::endl;
    return 0;
}