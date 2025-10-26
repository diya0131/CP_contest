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

const ll M=1e9+7;

bool comp(ll a, ll a1, ll b, ll b1){
    ll k;
    if(a1>b1){
        k=a1-b1;
        while(a<=b && k>0){
            a*=2;
            k--;
        }
        return a<b;
    } 
    k=b1-a1;
    while(a>=b && k>0){
        b*=2;
        k--;
    }
    return a<b;
}

ll pow(ll k){
    ll q=2, res=1;
    while(k>0){
        if(k%2) res=(res*q)%M;
        q=(q*q)%M; 
        k/=2;
    }
    return res;
}

void solve() {
    ll n, i, j, s=0, k, mx=0, p=0, t, kp, ts=0, res=0;
    cin>>n;
    stack< pair < ll, ll > > q;
    pair < ll, ll > pr;
    for(i=0;i<n;i++){
        cin>>k;
        test<<"cin" _ k _ "--------------\n";
        kp=0;
        ts=0;
        while(k%2==0){
            kp++;
            k/=2;
        }
        while(!q.empty()){
            pr = q.top();
            if(pr.ff<=k || comp(pr.ff, 0, k, ts+kp)){
                q.pop();
                ts+=pr.ss;
                res=(res-(pr.ff*pow(pr.ss)%M-pr.ff)%M)%M;
                test<<"cut" _ pr.ff _ pr.ss _ k _ ts+kp<<endl;
            } else {
                test<<"brk" _ pr.ff _ k _ ts+kp<<endl;
                break;
            }
        }
        q.push({k, ts+kp});
        test<<"test" _ q.top().ff _ q.top().ss<<endl;
        test<<"added" _ k _ ts+kp<<endl;
        res=(res+k*pow(ts+kp)%M)%M;
        res=(res+M)%M;
        test<<"res: ";
        cout<<res<<" ";
        test<<endl;
    }
    cout<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}