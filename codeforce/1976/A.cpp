#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    int n, x, y;
    string s;
    char ch='a'-1, di='0'-1;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(s[i]<='z' && s[i]>='a'){
            if(i+1<n){
                if(!(s[i+1]<='z' && s[i+1]>='a')) {
                    cout<<"NO"<<endl;
                    return;
                }
            }
            if(s[i]<ch){
                cout<<"NO"<<endl;
                return;
            }
            else{
                ch = s[i];
            }
        }
        else{
            if(s[i]<di){
                cout<<"NO"<<endl;
                return;
            }
            else{
                di = s[i];
            }
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}