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



int main() {
    string str;
    cin >> str;
    ll i, j, n = str.size(), k;
    vector < ll > pi(n, 0), cnt(n, 0);
    for (i = 1;i < n;i++) {
        j = pi[i - 1];
        while (j > 0 && str[i] != str[j]) {
            j = pi[j - 1];
        }
        if (str[i] == str[j]) j++;
        pi[i] = j;
    }
    for (i = 0;i < n;i++) {
        cnt[pi[i]]++;
    }
    for (i = n - 1;i > 0;i--) {
        cnt[pi[i - 1]] += cnt[i];
    }
    k=pi[n-1];
    vector < pair<ll,ll> > res;
    while(k>0){
        res.pb({k, cnt[k]+1});
        k=pi[k-1];
    }
    cout<<res.size()+1<<endl;
    for(i=res.size()-1;i>=0;i--){
        cout<<res[i].ff _ res[i].ss<<endl;
    }
    cout<<n _ 1<<endl;
}