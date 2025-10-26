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

void solve() {
    ll n, k, i, s=0, t, res=0, c=0, p, k1;
    cin>>n>>k1;
    map < ll, ll > mp;
    map < ll, ll >::iterator le, it;
    for(i=0;i<n;i++){
        cin>>k;
        if(mp.find(k)==mp.end()) mp[k]=0;
        mp[k]++;
    }
    le=mp.begin();
    p=0;
    for(it=mp.begin();it!=mp.end();it++){
        if((*it).ff>p+1){
            c=1;
            s=(*it).ss;
            le=it;
        } else {
            c++;
            s+=(*it).ss;
            if(c>k1){
                c--;
                s-=(*le).ss;
                le++;
            }
        }
        // cout<<p _ (*it).ff _ (*le).ff _ s<<endl;
        res=max(res, s);
        p=(*it).ff;
    }
    cout<<res<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}