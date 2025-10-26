#include<bits/stdc++.h>
#include<chrono>
#include <random>

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ << " " <<
// #define debug(a) cout << #a << "=" << a << endl;
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define BOOST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define test if(TEST) cout

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const bool TEST = 0;

void solve() {
    string s, t;
    ll i, j, k, n, m, res;
    cin >> s >> t;
    n = s.size();
    m = t.size();
    vector < ll > pref(26, -1), suff(26, -1);
    for (i = 1;i < n;i++) {
        if(pref[s[i]-'a']==-1) pref[s[i]-'a']=i;
    }
    for (i = m-2;i >=0 ;i--) {
        if(suff[t[i]-'a']==-1) suff[t[i]-'a']=i;
    }
    k=-1;
    res = LLONG_MAX;
    for(i=0;i<26;i++){
        if(pref[i]!=-1 && suff[i]!=-1){
            if(res> (pref[i]+(m - suff[i]))){
                res = (pref[i]+(m - suff[i]));
                k = i;
            }
        }
    }
    if(k==-1) cout<<-1<<endl;
    else{
        for(i=0;i<pref[k];i++){
            cout<<s[i];
        }
        for(i=suff[k];i<m;i++){
            cout<<t[i];
        }
        cout<<endl;
    }
}

int main() {
    solve();
}