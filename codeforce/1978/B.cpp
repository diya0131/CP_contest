#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ff first
#define ss second
#define PII pair < int, int >
#define PLL pair < ll, ll >

using namespace std;

void solve(){
    ll n, i, j, k, a, b, s=0, mi=0;
    cin>>n>>a>>b;
    
    k=min(n, b-a);
    k=max(mi, k);
    
    s+=(b-k+1)*k + k*(k-1)/2;
    
    // cout<<s<<endl;
    s+=a*(n-k);
    cout<<s<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}