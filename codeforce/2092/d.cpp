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

void prnt(vector< char >& tst){
    for(char ch:tst){
        cout<<ch;
    }
    cout<<endl;
}

void solve() {
    ll n, i, a=0, b=0, c=0, x, y, z, res=0;
    char cx, cy, cz;
    cin>>n;
    string s;
    vector < char > tst;
    cin>>s;
    if(n==1){
        cout<<-1<<endl;
        return;
    }
    for(i=0;i<n;i++){
        tst.pb(s[i]);
        a+=(s[i]=='T');
        b+=(s[i]=='L');
        c+=(s[i]=='I');
    }
    if(a==b && b==c){
        cout<<0<<endl;
        return;
    }
    if(a>=b && a>=c){
        z = a;
        cz = 'T';
    }
    if(b>=a && b>=c){
        z = b;
        cz = 'L';
    }
    if(c>=b && c>=a){
        z = c;
        cz = 'I';
    }
    if(a<=b && a<=c){
        x = a;
        cx = 'T';
    }
    if(b<=a && b<=c){
        x = b;
        cx = 'L';
    }
    if(c<=b && c<=a){
        x = c;
        cx = 'I';
    }
    y = (a+b+c)-x-z;
    i=1;

    
    queue<int > q;
    cy = ('T'+'L'+'I')-cz-cx;
    // cout<<x _ y _ z<<endl;
    // cout<<cx _ cy _ cz<<endl;

    if(s[0]==cx && s[1]==cy){
        //nothing
    }
    if(s[0]==cx && s[1]==cz){
        y++;
        res++;
        q.push(1);
    }
    if(s[0]==cy && s[1]==cx){
        res+=3;
        x++;
        y++;
        z++;
        q.push(1);
        q.push(1);
        q.push(2);
        i=2;
    }
    if(s[0]==cy && s[1]==cz){
        res+=2;
        x++;
        y++;
        q.push(1);
        q.push(2);
        i=2;
    }
    if(s[0]==cz && s[1]==cx){
        res+=2;
        x++;
        y++;
        q.push(1);
        q.push(1);
        i=2;
    }
    if(s[0]==cz && s[1]==cy){
        res++;
        x++;
        q.push(1);
        i=2;
    }

    while(x<y){
        res+=2;
        q.push(i);
        q.push(i+1);
        i+=2;
        x++;
        z++;
    }
    res++;
    q.push(i);
    z++;
    while(x<z || y<z){
        res+=2;
        q.push(i);
        q.push(i+1);
        i+=2;
        x++;
        y++;
    }
    // cout<<x _ y _ z<<endl;
    cout<<res<<endl;
    // prnt(tst);
    while(!q.empty()){
        cout<<q.front()<<endl;
        // int m=q.front();
        // int sz = tst.size();
        // tst.pb(tst[sz-1]);
        // for(i=sz-1;i>m;i--){
        //     tst[i]=tst[i-1];
        // }
        // tst[m]=('T'+'L'+'I')-tst[m-1]-tst[m+1];
        // prnt(tst);
        q.pop();
    }
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}