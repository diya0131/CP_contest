#include<bits/stdc++.h>

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

const bool TEST = 0;

ll n;

vector < ll > a, b, prefa, prefb, c, prefc;

ll get(ll st, ll end){
    ll rs=prefb[end]-prefb[st-1];
    test<<"st" _ rs _ st _ end<<endl;
    rs-=(prefa[end]-prefa[st-1])*(n-end);
    test<<"=" _ rs _ prefa[end] _ prefb[st-1] _ n _ end<<endl;
    return rs;
}

void solve() {
    ll i, j, k, s, sa, sb, res;
    cin>>n;
    a.resize(n+1);
    b.resize(n+1);
    prefa.resize(n+1);
    prefb.resize(n+1);
    prefc.resize(n+1);
    c.resize(n+1);
    for(i=1; i<=n; i++) cin>>a[i];
    s=0; sa=0; sb=0;
    prefa[0]=0;
    prefb[0]=0;
    prefc[0]=0;
    for(i=1; i<=n;i++){
        b[i]=a[i]*(n-i+1);
        sa+=a[i];
        sb+=b[i];
        prefa[i]=sa;
        prefb[i]=sb;
    }
    s=0;
    sa=0;
    vector < ll > ri(n);
    vector < ll >::iterator it;
    ri[0]=0;
    for(i=1;i<=n;i++){
        sa+=(n-i+1);
        ri[i]=sa;
        c[i]=get(i, n);
        s+=c[i];
        prefc[i]=s;
    }
    ll q,l, r, x, y, xri, yri,xv, yv;
    // test<<"here\n";
    for(i=0;i<=n;i++){
        test<<"b" _ i _ b[i] _ prefb[i] _ ri[i]<<endl;
    }
    cin>>q;
    while(q--){
        cin>>l>>r;
        // test<<"here\n";
        res=0;
        it=lower_bound(ALL(ri), l);
        xri=(*it);
        x=(it-ri.begin());
        it=lower_bound(ALL(ri), r);
        yri=(*it);
        y=(it-ri.begin());
        xv=n-xri+l;
        yv=n-yri+r;
        if(x==y){
            test<<"same" _ x _ y _ xri _ yri <<endl;
            
           
            res=get(xv, yv);
            test<<xv _ yv _ res<<endl;
            res+=(prefa[xv-1]-prefa[x-1])*(yv-xv+1);
            cout<<res<<endl;
            continue;
        }
        test<<"not" _ x _ y _ xri _ yri _ xv _ yv<<endl;
        res+=get(xv, n);
        test<<"get" _ res _ xv _ n<<endl;
        res+=(prefa[xv-1]-prefa[x-1])*(n-xv+1);
        test<<"wtf" _ xv-1 _ x-1 _ prefa[xv-1] _ prefa[x-1] <<endl;
        test<<xv _ yv _ res _ (prefa[xv-1]-prefa[x-1]) _ (n-xv+1)<<endl;
        res+=get(y, yv);
        test<<"y" _ res _ y _ yv<<endl;
        res+=prefc[y-1]-prefc[x];
        cout<<res<<endl;
    }
    
}

int main() {
    // BOOST
    
    solve();
    
}