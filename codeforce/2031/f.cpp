#include<bits/stdc++.h>
#include<chrono>
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const bool TEST = 0;

bool solve() {
    ll n, t, p, a = -1, b = -1, c, d, i, j, x, y, k, res1=-1, res2=-1;
    cin >> n;
    do {
        a = rng() % n;
        b = rng() % (n);
        if (a == b) b=(b+1)%n;
        cout << "? " << n - 2 << " ";
        for (i = 0;i < n;i++) {
            if (i != a && i != b) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
        cout.flush();
        cin >> c;
        if (c == -1) return 1;
        cin >> d;
        if (d == -1) return 1;

    } while ((c != (n / 2) || d != (n / 2) + 1));

    if (a > b) swap(a, b);

    vector < ll > arr(n - 2);
    j = 0;
    for (i = 0;i < n;i++) {
        if (i != a && i != b) {
            arr[j] = i + 1;
            j++;
        }
    }

    ll ax, ay, xx, yy;

    for (i = 0;i < n - 2;i += 2) {
        if(res1!=-1 && res2!=-1) break;
        c = arr[i];
        d = arr[i + 1];
        cout << "?" _ 4 _ a + 1 _ b + 1 _ c _ d << endl;
        cout.flush();
        cin >> x;
        if (x == -1) return 1;
        cin >> y;
        if (y == -1) return 1;
        if (x == n / 2 || y == n / 2) {
            xx = i;
            // k=arr[(i+2)%(n-2)];
            // cout<<"?" _ 4 _ a+1 _ b+1 _ c _ k<<endl;
            // cout.flush();
            // cin>>x;
            // if(x==-1) return 1;
            // cin>>y;
            // if(y==-1) return 1;
            // if(x==n/2 || y==n/2){
            //     res1=c;
            // } else {
            //     res1=d;
            // }
        }
        if (x == n / 2 + 1 || y == n / 2 + 1) {
            yy = i;
            // k=arr[(i+2)%(n-2)];
            // cout<<"?" _ 4 _ a+1 _ b+1 _ c _ k<<endl;
            // cout.flush();
            // cin>>x;
            // if(x==-1) return 1;
            // cin>>y;
            // if(y==-1) return 1;
            // if(x==n/2+1 || y==n/2+1){
            //     res2=c;
            // } else {
            //     res2=d;
            // }
        }
    }
    if (xx == yy) {
        cout << "! " << arr[xx] << ' ' << arr[xx + 1] << endl;return 0;
    }
    for (int i = 0, o = 1;i < 2 && o;i++)for (int j = 0;j < 2 && o;j++) {
        cout << "? 4 " << a + 1 << ' ' << b + 1 << ' ' << arr[xx + i] << ' ' << arr[yy + j] << endl;
        cout.flush();
        cin >> ax >> ay;
        if (ax == n / 2 && ay == n / 2 + 1)cout << "! " << arr[xx + i] << ' ' << arr[yy + j] << endl, o = 0;
    }
    // cout<<"! "<<res1 _ res2<<endl;
    cout.flush();
    return 0;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        bool bl = solve();
        if (bl) return 0;
    }
}