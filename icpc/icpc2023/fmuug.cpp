#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define ll long long
#define _ <<' '<<
#define mp make_pair
#define ALL(x) x.begin(), x.end()
#define LLA(x) x.rbegin(), x.rend()
#define PII pair < int , int >
#define PLL pair < ll , ll >
#define debug(n) cout << #n << " = " << n << endl;
#define int ll

const int N = 3e5 + 7;
const int MOD = 1e9 + 7;
const int moveX[] = { -1, 0, 1, 0 };
const int moveY[] = { 0, 1, 0, -1 };
const int INFI = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);

class UnionFind {
public:
    vector<int> parent;
    vector<int> union_size;
    int len;
    UnionFind(int n) {
        len = n;
        parent = vector<int>(n);
        union_size = vector<int>(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int Find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = Find(parent[x]);
    }
    bool Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x == y) {
            return 0;
        }
        parent[y] = x;
        union_size[x] += union_size[y];
        union_size[y] = union_size[x];
        len--;
        return 1;
    }
    bool IsHead(int x) {
        return parent[x] == x;
    }
    int Size(int x) {
        return union_size[Find(x)];
    }
};

signed main() {
    int n, n2;
    cin >> n2;
    n = n2 * 2;
    vector<PII> a(n);
    vector<vector<int>> dist;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            dist.push_back({ (a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second), i, j });
        }
    }
    sort(ALL(dist));
    int d = dist.size();
    int l = 0;
    int r = d - 1;
    int m;
    double ans = 0;
    vector<int> team = { 0 };
    while (l <= r) {
        m = (l + r) / 2;
        UnionFind uf(n);
        for (int i = 0; dist[i][0]<dist[m][0]; i++) {
            uf.Union(dist[i][1], dist[i][2]);
        }
        vector<int> g;
        for (int i = 0; i < n; i++) {
            if (uf.IsHead(i)) {
                g.push_back(i);
            }
        }
        vector<int> dp(n2 + 1, -1), dp1(n2 + 1, -1);
        dp[0] = 0;
        dp1[0] = 0;
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j <= n2 - uf.Size(g[i]); j++) {
                if (dp1[j] > -1 && dp[j + uf.Size(g[i])] == -1) {
                    dp[j + uf.Size(g[i])] = i;
                }
            }
            if (dp[n2] > -1) {
                break;
            }
            dp1 = dp;
        }
        // cout << "g:\t";
        // for (int i = 0; i < g.size(); i++) {
        //     cout << g[i] << " ";
        // }
        // cout << endl;
        // debug(dp[n2]);
        // cout << "\t" << m _ dist[m][0] << endl;
        // for (int i = 0; i <= n2; i++) {
        //     cout << dp[i] << " \n"[i == n2];
        // }
        if (dp[n2] == -1) {
            r = m - 1;
            continue;
        }
        
        if (ans < sqrt(dist[m][0])) {
            
            ans = sqrt(dist[m][0]);
            vector<int> cur;
            int c = n2;
            vector<vector<int>> nums(n + 1, vector<int>());
            for (int i = 0; i < n; i++) {
                nums[uf.Find(i)].push_back(i);
            }
            // for (int i = 0; i < n; i++) {
            //     if (nums[i].size()) {
            //         debug(i);
            //         for (int j = 0; j < nums[i].size(); j++) {
            //             cout << nums[i][j] << " \n"[j == nums[i].size() - 1];
            //         }
            //     }
            // }
            while (c) {
                for (int num : nums[g[dp[c]]]) {
                    cur.push_back(num);
                }
                c -= uf.Size(g[dp[c]]);
            };
            team = cur;
        }
        l = m + 1;
    }
    printf("%.6lf\n", ans);
    for (int t : team) {
        cout << t + 1 << endl;
    }
}
