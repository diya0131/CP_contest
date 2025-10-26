#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout<<
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = true;

void solve(){
    int a, b, c, i;
    cin>>a>>b>>c;
    for(i=0;i<5;i++){
        if(a<=b && a<=c){
            a++;
        } else if (b<=c && b<=a){
            b++;
        } else {
            c++;
        }
    }
    cout<< a*b*c<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}