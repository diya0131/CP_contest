#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

void solve() {
    string s;
    int i, n;
    cin>>s;
    n=s.size();
    if(s[0]=='1' && s[n-1]!='9'){
        for(i=1;i<n-1;i++){
            if(s[i]=='0'){
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
    }
    else {
        
        cout<<"NO"<<endl;
    }
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}