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
    ll n, i, j, k;
    cin>>n;
    ll ma=0;
    for(i=0;i<n-1;i++){
        cin>>k;
        ma=max(ma, k);
    }
    cin>>k;
    cout<<ma+k<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}