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
    int i, j, s, k;
    string s1, s2;
    cin>>s1>>s2;
    int n=s1.size(), m=s2.size();
    i=0;
    j=0;
    while(i<n && j<m && s1[i]==s2[j]){
        i++;
        j++;
    }
    if(i>0) cout<<n+m-i+1<<endl;
    else cout<<n+m<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}