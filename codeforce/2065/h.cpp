#include<bits/stdc++.h>
#include<random>
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

const int N=2e5;

struct node {
    int st1cnt, st1sum, st0cnt, st0sum;
    int nd1cnt, nd1sum, nd0cnt, nd0sum;
    int cnt, sum;
};

vector < node > st(N);

void merge(int v){
    node left=st[2*v], right=st[2*v+1], nd;

    nd.st0cnt=left.st0cnt * right.cnt + right.st0cnt;
    nd.st0sum=left.st0sum*right.st1sum + left.st0sum*right.st;
    nd.st1cnt=left.st1cnt * right.cnt + right.st1cnt;
    nd.st1sum=b;
    nd.nd0cnt=right.nd0cnt * left.cnt + left.nd0cnt;
    nd.nd0sum=a;
    nd.nd1cnt=right.nd1cnt * left.cnt + left.nd1cnt;
    nd.nd1sum=b;
    nd.cnt=nd.st0cnt + nd.st1cnt;
    nd.sum=nd.st0sum + nd.st1sum;
    
    st[v]=nd;
}

void build(int v, int tl, int tr, string& s){
    
    node nd;
    int a=1, b=0;
    if(tl==tr){
        if(s[tl]=='1'){
            a=0;
            b=1;
        }
        nd.st0cnt=a;
        nd.st0sum=a;
        nd.st1cnt=b;
        nd.st1sum=b;
        nd.nd0cnt=a;
        nd.nd0sum=a;
        nd.nd1cnt=b;
        nd.nd1sum=b;
        nd.cnt=1;
        nd.sum=1;
        st[v]=nd;
        return;
    }
    int tm = (tl+tr)/2;
    build(2*v, tl, tm, s);
    build(2*v+1, tm+1, tr, s);
    merge(v);
}   

void solve() {
    
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}