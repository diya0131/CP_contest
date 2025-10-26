#include<bits/stdc++.h>
#include <random>

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

const int test_count = 40;

void solve() {
    ll n, i, j, x, y, k, m, cnt = 0;
    cin >> n;
    vector < pair < ll, ll> > pts(n);
    for (i = 0;i < n;i++) {
        cin >> x >> y;
        pts[i] = { x, y };
    }
    m = n - n / 2;
    // i need m pts in line or answer is n
    // cout<<"sz: "  _ n<<endl;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, n - 1);
    for (int i1 = 0;i1 < test_count;i1++) {
        x = dis(gen);
        y = dis(gen);
        if(x==y){
            x=(y+1)%n;
        }
        cnt = 0;
        for (i = 0;i < n;i++) {
            if ((pts[i].ff - pts[x].ff) * (pts[i].ss - pts[y].ss) == (pts[i].ff - pts[y].ff) * (pts[i].ss - pts[x].ss)) cnt++;
        }
        if (cnt >= m) {
            cout << n - cnt << endl;
            return;
        }
    }
    cout << n << endl;


}

int main() {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1;i <= t;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
// Case #1: 0
// Case #2: 2
// Case #3: 3
// Case #4: 5000
// Case #5: 1978
// Case #6: 5000
// Case #7: 4767
// Case #8: 3927
// Case #9: 3
// Case #10: 2
// Case #11: 4
// Case #12: 15
// Case #13: 8
