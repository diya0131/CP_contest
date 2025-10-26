#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

void solve() {
    int n, i, j, mi = INT_MAX, ma = INT_MIN, s, mii=0, mai=0;
    cin >> n;
    if (n < 3) {
        cout << "NO" << endl;
        return;
    }
    for (i = 0;i < n;i++) {
        cin >> s;
        if(mi > s){
            mi=s;
            mii=i;
        }
        if(ma<s){
            ma=s;
            mai=i;
        }
    }
    // cout<<mi _ ma _ mii _ mai<<endl;
    if(mi==ma){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        bool p = false;
        for(i=0;i<n;i++){
            if(i!=mii && i!=mai && !p){
                cout<<"R";
                p=true;
            }
            else{
                cout<<"B";
            }
        }
        cout<<endl;
    }
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}