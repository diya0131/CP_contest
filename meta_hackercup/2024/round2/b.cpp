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

const bool TEST = 1;

vector < ll > arr;

void go(ll k, ll p, ll i, ll val){
    if(i==k+1){
        // cout<<val<<endl;
        arr.pb(val);
        return;
    }
    if(i==k/2+1) {
        go(k, p, i+1, val*10+p);
        return;
    }
    if(i<=k/2){
        for(int j=max(val%10, 1LL);j<p;j++){
            go(k, p, i+1, val*10+j);
        }
        return;
    } 
    for(int j=min(p-1, val%10);j>0;j--){
        go(k, p, i+1, val*10+j);
    }
}

void solve() {
    ll a, b, m;
    cin>>a>>b>>m;
    ll res=0;
    for(ll num:arr){
        if(a<=num && num<=b && num%m==0) {
            res++;
            // cout<<num<<endl;
        }
    }
    cout<<res<<endl;
}

int main() {
    arr.pb(1);
    ll n;
    for(int i=1;i<=18;i+=2){
        for(int j=2;j<10;j++){
            go(i, j, 1, 0);
        }
    }
    n=arr.size();
    
    // cout<<arr[n-1] _ n<<endl;
   
    freopen("cottontail_climb_part_2_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // BOOST
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
}