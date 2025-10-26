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
    ll n, k, t, c, b, i, res=0;
    cin>>n>>k;
    map < ll, ll > mp;
    map < ll, ll >::iterator it;
    for(i=0; i<k; i++){
        cin>>b>>c;
        mp[b]+=c;
    }
    multiset < ll > st;
    multiset < ll >:: iterator ite;
    for(it=mp.begin();it!=mp.end();it++){
        st.insert(it->ss);
    }
    ite=st.end();
    do{
        ite=prev(ite);
        res+=*ite;
        n--;
    }while(n>0 && ite!=st.begin());
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