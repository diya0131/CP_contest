#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int h, n;
    cin >> h >> n;
    vector<int> a(n), c(n);
    for (auto &i : a) cin >> i;
    for (auto &i : c) cin >> i;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 0; i < n; i++) {
        pq.emplace(1, i);
    }
    while (!pq.empty()) {
        auto [turn, i] = pq.top();
        pq.pop();
        h -= a[i];
        if (h <= 0) {
            cout << turn << "\n";
            return;
        }
        pq.emplace(turn + c[i], i);
    }
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) solve();
    return 6/22;
}