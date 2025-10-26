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
    cout<<"----------\n";
    for(char ch:tst){
        cout<<ch;
    }
    cout<<endl;
}

void solve() {
    
    ll n, i, j, a=0, b=0, c=0, x, y, z, res=0, sz, add, m;
    char cx, cy, cz;
    cin>>n;
    string s;
    vector < char > tst(n, 'x'), tst2(n, 'x');
    sz = n;
    cin>>s;
    if(n==1){
        cout<<-1<<endl;
        return;
    }
    for(i=0;i<n;i++){
        tst[i]=s[i];
        tst2[i]=s[i];
        a+=(s[i]=='T');
        b+=(s[i]=='L');
        c+=(s[i]=='I');
    }
    queue < int > q, p;
    // prnt(tst);
    while(!(a==b && b==c)){
        for(i=1;i<tst.size();i++){
            
            if(tst[i-1]!=tst[i]){
                cx = ('T'+'L'+'I') - tst[i-1] - tst[i];
                bool shld=false;
                if(cx == 'T' && a < max(a, max(b, c))){
                    shld=true;
                    a++;
                }
                if(cx == 'L' && b < max(a, max(b, c))){
                    shld=true;
                    b++;
                }
                if(cx == 'I' && c < max(a, max(b, c))){
                    shld=true;
                    c++;
                }
                if(shld){
                    
                    m=i+add;
                    add++;
                    res++;
                    q.push(m);
                    p.push(m);
                    // tst.pb('x');
                    tst2.pb('x');
                    // cout<<m<<endl;
                    // for(i=sz;i>m;i--){
                    //     tst[i]=tst[i-1];
                    // }
                    // sz++;
                    // tst[m]=('T'+'L'+'I')-tst[m-1]-tst[m+1];
                    
                    // prnt(tst);
                }
            }
            if(a==b && a==c) break;
            
        }
        // cout<<a _ b _ c <<endl;
        i=0;
        j=0;
        add=0;
        while(!p.empty()){
            m = p.front();
            // cout<<m _ add _ i<<endl;
            for(;j<m;i++){
                tst2[j]=tst[i];
                j++;
            }
            tst2[m]=('T'+'L'+'I')-tst2[m-1]-tst[i];
            j++;
            add++;
            p.pop();
        }
        for(;i<tst.size();i++){
            tst2[j]=tst[i];
            j++;
        }
        tst.resize(tst2.size());
        for(i=0;i<3*n;i++){
            tst[i]=tst2[i];
        }
        // prnt(tst);
        // break;
    }
    cout<<res<<endl;
    
    while(!q.empty()){
        
        cout<<q.front()<<endl;
        q.pop();
    }
}

int main() {
    BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}