#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    int n, m, i, s;
    cin>>n>>m;
    string str;
    cin>>str;
    int arr[7];
    for(i=0;i<7;i++) arr[i]=0;
    for(i=0;i<n;i++){
        arr[str[i]-'A']++;
    }
    s=0;
    for(i=0;i<7;i++){
        if(arr[i]<m) s+=m-arr[i];
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


