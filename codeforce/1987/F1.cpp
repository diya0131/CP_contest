#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
#define _ << " " <<
#define debug if(de) cout
#define ff first
#define ss second
#define PLL pair < ll, ll >

using namespace std;
const bool de = false;


void solve() {
    vector< pair < int, int > > st;
    vector< pair < int, int > >::iterator it, nxt, ite;
    int n, i, j, k, s, res=0, idx;
    bool b;
    cin>>n;
    s=n;
    for(i=0;i<n;i++){
        cin>>k;
        st.pb({i, k});
    }
    while(true){
        debug<<s _ "again"<<endl;
        if(s<2) break;
        it = st.end();
        it = prev(it);
        idx = s;
        b=true;
        do{
            
            nxt = it+1;
            
            if(nxt!=st.end()){
                if((*it).ss == idx){
                    ite = it;
                    debug<<"sub" _ idx<<endl;
                    if(s==2){
                        res++;
                        st.erase(nxt);
                        s-=2;
                        b=false;
                        idx =0;
                    }
                    else{
                        ite=it;
                        it = prev(it);
                        idx--;
                        st.erase(ite);
                        st.erase(nxt);
                        res++;
                        s-=2;
                        b=false;
                    }
                }
                else {
                    debug<<"nah" _ idx _ (*it).ss<<endl;
                    idx--;
                    it=prev(it);}
            }
            else {
                idx--;
                it = prev(it);
            }
        }while(idx>0);
        if(b) break;
    }
    debug<<"res: ";
    cout<<res<<endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}