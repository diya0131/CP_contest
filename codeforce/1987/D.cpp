#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ff first
#define ss second
#define PLL pair < ll, ll >

using namespace std;


void solve() {
    ll n, k, i;
    cin >> n ;
    ll a[n];
    map < ll, ll > mp;
    for(i=0;i<n;i++){
        cin>>k;
        if(mp.find(k)==mp.end()) mp[k]=1;
        else mp[k]++;
    }
    ll s=0, t=0, ts = 0;
    set< pair < ll, ll > > st;
    set< pair < ll, ll > >::iterator ite;
    pair < ll, ll >  pr;
    for(auto it=mp.begin();it!=mp.end();it++){
        pr = *it;
        if(s - t >= ts + pr.ss){
            t++;
            ts+=pr.ss;
            st.insert({pr.ss, pr.ff});
            // cout<<pr.ff _ pr.ss _ t _ ts _ "added"<<endl;
        } else {
            if(st.size()>0){
                ite = prev(st.end());
                // cout<<(*ite).ff _ (*ite).ss<<endl;
                
                if((*ite).ff>pr.ss){
                    ts-=(*ite).ff;
                    ts+=pr.ss;
                    // cout<<(*ite).ff _ (*ite).ss _ pr.ff _ pr.ss _ t _ ts _ "switched"<<endl;
                    st.erase(ite);
                    st.insert({pr.ss, pr.ff});
                }
            }
        }
        s++;
    }
    cout<<s-t<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}