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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

const bool TEST = 0;

vector < vector< ll > > st;

vector< ll > combine(vector< ll >& left, vector< ll >&right){
    vector < ll > res(4);
    res[0] = left[0]+right[0];
    res[1] = max(right[1], left[1]+right[0]);
    res[2] = max(left[2], right[2]+left[0]);
    res[3] = max(max(right[3], left[3]), right[1]+left[2]);
    return res;
}

void update(ll v, ll tl, ll tr, ll idx, ll k){
    if(tl==tr){
        st[v][0] = k;
        if(k>=0){
            st[v][1]=st[v][2]=st[v][3]=k;
        } else {
            st[v][1]=st[v][2]=st[v][3]=0;
        }
        return;
    }
    ll tm = ( tl+tr)/2;
    if(tm<idx) update(2*v+1, tm+1, tr, idx, k);
    else update(2*v, tl, tm, idx, k);
    st[v] = combine(st[2*v], st[2*v+1]);
}

vector< ll > get(ll v, ll tl, ll tr, ll l, ll r){
    cout<<"get" _ tl _ tr _ l _ r<<endl;
    if(l>r) return {0, 0, 0, 0};
    if(tl==l && tr ==r){
        return st[v];
    }
    ll tm = (tl+tr)/2;
    vector < ll > left, right, res;
    left = get(2*v, tl, tm, l, min(r, tm));
    right = get(2*v+1, tm+1, tr, max(l, tm+1), r);
    return combine(left, right);
}

void solve() {
    ll n, m, i, j, k, s, t, l, r, c=1;
    cin>>n>>m;
    vector < vector< pair < ll, ll > > > op(n+1);
    for(int i=0; i<m; i++){
        cin>>l>>r>>k;
        op[l].pb({i, k});
        op[r].pb({i+1, 0});
    }
    ll q;
    cin>>q;
    vector < vector< ll > > qu(q, vector< ll> (4));
    vector< ll > res(q);
    
    for(i=0;i<q;i++){
        cin>>l>>r>>k;
        qu[i][0]=k;
        qu[i][1]=l-1;
        qu[i][2]=r-1;
        qu[i][3]=i;
    }
    sort(ALL(qu));
    cout<<"done\n";
    st.clear();
    st.resize(4*m, vector< ll> (4, 0));
    for(i=0;i<q;i++){
        cout<<"i: "  _ i <<endl;
        while(c<=qu[i][0]){
            for(j=0;j<op[c].size();j++){
                // update(1, 0, m-1, op[c][j].ff, op[c][j].ss);
            }
            c++;
        }
        res[qu[i][3]] = get(1,0, m-1, qu[i][1], qu[i][2])[3];
    }
    for(i=0;i<q;i++) cout<<res[i]<<" ";
    cout<<endl;
}

int main() {
    // BOOST
    solve();
}