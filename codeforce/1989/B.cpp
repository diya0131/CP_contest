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
    string s, t;
    cin>>s>>t;
    int n=s.size(), m = t.size(), i, j, res=0, sum=0, idx;

    for(i=0;i<m;i++){
        sum=0;
        idx = i;
        for(j=0;j<n;j++){
            if(s[j]==t[idx]) idx++;
            if(idx==m) break;
        }
        res=max(res, idx-i);
    }
    cout<<n+m-res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}