#include<bits/stdc++.h>
#include<chrono>
#include <random>

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const bool TEST = 0;



int main() {
    ll n, i, j, k;
    string s;
    char ch, t;
    cin>>n>>ch>>t;
    cin>>s;
    for(i=0;i<s.size();i++){
        if(s[i]==ch) continue;
        s[i]=t;
    }
    cout<<s<<endl;
}