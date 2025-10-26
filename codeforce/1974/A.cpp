// #include<bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define _ <<" "<<

// using namespace std;

// void solve(){
//     int n, x, y, s;
//     cin>>x>>y;
//     cout<<max((y+1)/2, (x+4*y+14)/15)<<endl;
// }

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
// }

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, i, j, q;
    cin>>n;
    string s;
    pair< string, int> a[n];
    for(i=0;i<n;i++){
        cin>>s;
        a[i]={s, i};
    }
    sort(a, a+n);
    cin>>q;
    int res=0;
    while(q--){
        res=0;
        cin>>s;
        for(i=0;i<s.size();i++) res+=s[i]-'a'+1;
        cout<<(lower_bound(a, a+n, s)-a)*res<<endl;
    }
    
    return 0;
}
