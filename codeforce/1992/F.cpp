#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = false;


void solve() {
    ll n, t, x, res = 1, q = 1, i, j, k;
    cin >> n >> x;
    set < ll > a;
    set < ll >::iterator it;
    map < ll, int > mp;
    for (i = 1;i * i < x;i++) {
        if (x % i == 0) {
            a.insert(i);
            a.insert(x / i);
        }
    }
    if (i * i == x) {
        a.insert(i);
    }
    // test<<"---------\n";
    // auto ite = a.begin();
    // for(i=0;i<a.size();i++){
    //     test<<(*ite)<<" ";
    //     ite++;
    // }
    // cout<<endl;
    mp.clear();
    mp[1]=1;
    for (i = 0;i < n;i++) {
        cin >> k;
        for (it = a.begin(); it != a.end();it++) {
            t = (*it);
            // cout<<i _ t _ mp[t]<<endl;
            if (t * k > x) break;
            if(mp[t] && mp[t]<i+2){
                if(t*k==x){
                    res++;
                    // test<<i _ " hey " _ t _ mp[t] _ res<<endl;
                    mp.clear();
                    mp[1]=1;
                    mp[k]=1;
                } else {
                    test<<"-" _ t _ k _ mp[t*k]<<endl;
                    if(x%(t*k)==0 && mp[t*k]==0){
                        test<<"added"<<endl;
                        mp[t*k]=i+2;
                    }
                }
            }
        }
    }
    cout<<res<<endl;

}



int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}