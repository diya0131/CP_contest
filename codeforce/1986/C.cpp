#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

void solve(){
    int n, m, i, j, t, k;
    cin>>n>>m;
    string s, p;
    cin>>s;
    
    set < int > a;
    char b[m];
    for(i=0;i<m;i++){
        cin>>k;
        a.insert(k-1);
    }
    for(i=0;i<m;i++){
        cin>>b[i];
    }
    sort(b, b+m);
    i=0;
    for(auto it = a.begin(); it!=a.end();it++){
        s[*it]=b[i];
        i++;
    }
    cout<<s<<endl;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}