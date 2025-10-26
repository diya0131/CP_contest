#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    int n, x, y, i;
    string s;
    cin>>n;
    cin>>s;
    vector < int > a;
    int pos[26], vis[26]={0};
    char ch;
    for(i=0;i<n;i++){
        // cout<<vis[s[i]-'a']<<" ";
        if(vis[s[i]-'a']==0) {
            // cout<<a.size()<<endl;
            a.pb( s[i] - 'a' );
            vis[ s[i] - 'a' ] = 1;
        }
    }
    sort(a.begin(), a.end());
    // cout<<a.size()<<endl;
    for(i=0;i<a.size();i++){
        // cout<<a[i]<<" - ";
        pos[a[i]] = i;
    }
    // cout<<endl;
    for(i=0;i<n;i++){
        ch='a'+a[a.size() - 1 - pos[s[i]-'a']];
        cout<<ch;
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}