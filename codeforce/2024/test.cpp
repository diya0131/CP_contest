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
    string s;
    cin>>s;
    int n=s.size(), i, j;
    vector < int > lps(n, 0), lss(n, 0);
    j=0;
    for(i=1;i<n;i++){
        if(s[j]==s[i]) {
            lps[i]=lps[i-1]+1;
            j++;
        }
        else {
            lps[i]=0;
            j=0;
        }
        // cout<<"lps" _ i _ lps[i]<<endl;
    }
    j=n-1;
    for(i=n-2;i>=0;i--){
        if(s[j]==s[i]) {
            lss[i]=lss[i+1]+1;
            j--;
        }
        else {
            lss[i]=0;
            j=n-1;
        }
        // cout<<"lss" _ i _ lss[i]<<endl;
    }
    for(i=n/2;i<n-1;i++){
        cout<<i _ n-1-i _ lps[i] _ lss[n-1-i] _ 2*i-n+2<<endl;
        if(lps[i]==2*i-n+2 && lss[n-1-i]==2*i-n+2) {
            cout<<"YES\n";
            for(j=0;j<=i;j++) cout<<s[j];
            cout<<endl;
            return;
        }
    }
    cout<<"NO\n";
}

int main() {
    // BOOST
    
    solve();
    
}