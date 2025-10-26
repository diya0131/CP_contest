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
const ll N = 10000001;

bool isp[N];
ll res[N];

void solve() {
    ll n;
    cin>>n;
    cout<<res[n]<<endl;
}

int main() {
    ll j;
    for(ll i=0;i<N;i++){
        isp[i]=1;
        res[i]=0;
    }
    for(ll i=2;i<N;i++){
        if(isp[i]){
            j=i*2;
            while(j<N){
                isp[j]=0;
                j+=i;
            }
        }
    }
    ll s=1;
    for(ll i=5;i<N;i++){
        if(isp[i] && isp[i-2]) s++;
        res[i]=s;
    }
    freopen("prime_subtractorization_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
}