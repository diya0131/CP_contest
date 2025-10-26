#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    if(n>=m && (n-m)%2==0){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    

}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}