#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
#define _ << " " <<
#define debug if(de) cout
#define ff first
#define ss second
#define PLL pair < ll, ll >

using namespace std;

vector < ll > a;

vector < vector < ll > > path;

const bool de = false;

ll res;



vector < ll > dfs(ll k, ll par, ll lvl) {
   
    vector < ll > vc, vec;
    if (path[k].size() == 1 && k != 0) {
        vc.pb(-1);
        return vc;
    }
    vc.pb(0);
    ll s = 0, t, l;
    for (int i = 0;i < path[k].size();i++) {
        if (path[k][i] != par) {
            vec = dfs(path[k][i], k, lvl + 1);
            if(vec.size()+1>vc.size()) vc.resize(vec.size()+1);
            for(int j=0;j<vec.size();j++){
                if(vc[j+1]!=-1){
                    if(vec[j]==-1) vc[j+1]=-1;
                    else vc[j+1]+= vec[j];
                }
            }
            s += a[path[k][i]];
        }
    }
    debug << k _ s _ a[k] _ lvl << endl;
    if (s < a[k]) {
        t = a[k] - s;
        l = 1;
        while (t > 0) {
            if (vc[l] == -1) {
                debug << "done leaf " _ l  _ t _ l<< endl;
                res += t * l;
                t = 0;
            } else {
                if (vc[l] >= t) {
                    debug << "done " _ l _ t _ l<< endl;
                    vc[l] -= t;
                    res += t * l;
                    t = 0;
                } else {
                    debug << "taken " _ l _ vc[l] _ l<< endl;
                    t -= vc[l];
                    res += vc[l] * l;
                    vc[l] =0;
                }
            }
            l++;
        }
    } else {
        debug << "added " _ lvl _ s - a[k] << endl;
        vc[0] = s - a[k];
        
    }
    return vc;
}


void solve() {
    ll n, k, i, s = 0;
    cin >> n;
    a.clear();
    a.resize(n);
    path.clear();
    path.resize(n);
    for (i = 0;i < n;i++) {
        cin >> a[i];
    }
    for (i = 1;i < n;i++) {
        cin >> k;
        k--;
        path[i].pb(k);
        path[k].pb(i);
    }
    res = 0;
    dfs(0, -1, 0);
    debug<<"res: ";
    cout << res << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}