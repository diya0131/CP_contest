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

void solve() {
    deque < pair < int, int > > dq;
    pair < int, int > pr;
    ll n, m, k, res=0, i, j, l, r, a, d, c=1, today, t;
    cin>>n>>m>>k;
    for(i=0; i<n;i++){
        cin>>d>>a;
        today=m;
        while(!dq.empty() && c<d){
            pr=dq.back();
            test<<"check" _ pr.ff _ pr.ss _ today _ res<<endl;
            if(pr.ff<=c-k) break;
            dq.pop_back();
            if(pr.ss<today){
                today-=pr.ss;
            } else {
                pr.ss-=today;
                test<<"done-" _ pr.ff _ pr.ss _ c<<endl;
                res++;
                c++;
                test<<pr.ss/m _ pr.ff+k-c _ c _ d-c<<endl;
                t=min(min(pr.ss/m, d-c), pr.ff+k-c);
                // cout<<t _ d-c<<endl;
                res+=t;
                c+=t;
                
                pr.ss-=t*m;
                test<<"done+" _ pr.ff _ pr.ss _ c _ t _ res<<endl;
                today=m;
                dq.push_back(pr);
            }
        }
        test<<"added" _ d _ a<<endl;
        c=d;
        dq.push_back({d, a});
    }
    today=m;
    while(!dq.empty()){
        pr=dq.back();
        test<<"check" _ pr.ff _ pr.ss _ today _ res<<endl;
        if(pr.ff<=c-k) break;
        dq.pop_back();
        if(pr.ss<today){
            today-=pr.ss;
        } else {
            pr.ss-=today;
            test<<"done-" _ pr.ff _ pr.ss _ c<<endl;
            res++;
            c++;
            test<<pr.ss/m _ pr.ff+k-c _ c<<endl;
            t=min(pr.ss/m, pr.ff+k-c);
            res+=t;
            c+=t;
            
            pr.ss=pr.ss%m;
            test<<"done+" _ pr.ff _ pr.ss _ c _ t _ res<<endl;
            today=m;
            dq.push_back(pr);
        }
    }
    cout<<res<<endl;

}

int main() {
    BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}