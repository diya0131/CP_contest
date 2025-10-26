
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
    ll n, k, i, j, t, x, y;
    cin >> n >> k;
    if (k % 2) {
        cout << "NO" << endl;
        return;
    }

    if(k>2*( ((n)/2) * ((n+1)/2) )){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    ll ma=n, s=0, even, odd;
    int b[n+1];
    for(i=1;i<=n;i++) b[i]=i;
    for(i=1;i<=n;i++){
        if(k>0){
            odd = sqrt((k/2));
            if(odd*odd<k/2) odd++;
            even = sqrt(k/2);
            if(even*(even+1)<k/2) even++;
            odd=odd*2-1;
            even=2*even;
            // cout<<odd _ even<<endl;
            t=min(odd, even);
            cout<<t+i<<" ";
            b[t+i]=i;
            k-=2*t;
        }
        else{
            cout<<b[i]<<" ";
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