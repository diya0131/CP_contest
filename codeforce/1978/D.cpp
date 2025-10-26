
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


void solve() {
    ll n, k, i, j, t, x, y, c, ma=-1, mai;
    cin>>n>>c;
    ll a[n];
    for(i=0;i<n;i++){
        cin>>k;
        a[i]=k;
        if(k>ma){
            ma=k;
            mai=i;
        }
    }
    y=mai;
    for(i=0;i<n;i++){
        if(i!=mai){
            if(a[i]+c>=ma){
                cout<<i<<" ";
            }
            else{
                y=min(y, i);
                cout<<i+1<<" ";
            }
            c+=a[i];
        }
        else{
            cout<<y<<" ";
            c+=a[i];
        }
        
    }
    cout<<endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}