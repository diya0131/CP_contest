#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ <<" "<<

using namespace std;

struct node{
    ll val;
    ll sum=0;
    node* left;
    node* right;

};

vector < vector < pair < ll, ll > > > path;
vector < node* > trash;
node *etree, *otree;
vector < bool > vis;
vector < ll > odd, even, deep, xval;

void create(ll k, node *nd){
    // cout<<k  _ "starting\n";
    ll pow =1;
    for(int i=0; i<30; i++) pow*=2;
    while(pow>0){
        nd->sum++;
        if( (k & pow) ){
            if(nd->right==nullptr){
                // cout<<"new right " _ pow << endl;
                node* nw = new node();
                trash.pb(nw);
                nw->sum = 0;
                nd->right= nw;
                nw->val = -1;
                nd= nw;
            }
            else{ 
                // cout<<"go right " _ pow << endl;
                
                nd=nd->right;
            }
        }
        else{
            if(nd->left==nullptr){
                // cout<<"new left" _ pow << endl;
                node* nw = new node();
                trash.pb(nw);
                nd->left= nw;
                nw->val = -1;
                nw->sum = 0;
                nd= nw;
            }
            else {
                // cout<<"go left " _ pow << endl;
                nd=nd->left;
            }
        }
        pow/=2;
    }
    nd->sum++;
    nd->val = k;
}

void remove(ll k, node *nd){
    // cout<<k  _ "removing\n";
    ll pow =1;
    for(int i=0; i<30; i++) pow*=2;
    while(pow>0){
        nd->sum--;
        // cout<<pow<<endl;
        if( (k & pow) ){
            nd = nd->right;
        }
        else{
            nd=nd->left;
        }
        pow/=2;
    }
    nd->sum--;
}

ll find(ll k, node* nd){
    ll pow =1;
    // cout<<"finding\n"<<endl;
    for(int i=0; i<30; i++) pow*=2;
    if(nd->sum==0) return -1;
    while(pow>0){
        // cout<<pow _ nd->sum<<endl;
        
        if( !(k & pow) ){
            if(nd->right==nullptr || nd->right->sum==0){
                nd=nd->left;
            }
            else nd=nd->right;
        }
        else{
            if(nd->left==nullptr || nd->left->sum==0){
                nd=nd->right;
            }
            else nd=nd->left;
        }
         pow/=2;
    }
    
    return (nd->val ^ k);
}

void dfs(ll nd, ll lvl, ll val, ll par){
    deep[nd]=lvl;
    xval[nd]=val;
    if(lvl%2){
        odd.pb(val);
    }
    else{
        even.pb(val);
    }
    for(auto pr: path[nd]){
        if( pr.ff != par ){
            dfs(pr.ff, lvl+1, ( val ^ pr.ss ) , nd);
        }
    }
}

void solve(){
    path.clear();
    trash.clear();
    vis.clear();
    odd.clear();
    even.clear();
    deep.clear();
    xval.clear();
    etree = new node();
    otree = new node();
    etree->sum = 0;
    otree->sum = 0;
    etree->val = -1;
    otree->val = -1;
    ll n, m, k, w, u, v, t, s, i, j, y;
    char ch;
    vector < pair < ll, ll > > tmp;
    cin>>n>>m;
    y=0;
    for(i=0;i<n;i++){
        path.pb(tmp);
        vis.pb(0);
        deep.pb(0);
        xval.pb(0);
    }
    for(i=0;i<n-1;i++){
        cin>>u>>v>>w;
        u--;
        v--;
        path[u].pb({v, w});
        path[v].pb({u, w});
    }
    dfs(0, 0, 0, -1);

    for(i=0;i<odd.size();i++){
        create(odd[i], otree);
    }
    for(i=0;i<even.size();i++){
        create(even[i], etree);
    }

    for(i=0;i<m;i++){
        cin>>ch;
        if(ch=='?'){
            cin>>k>>w;
            k--;
            
            if(deep[k]%2){
                remove(xval[k], otree);
                u = find(w ^ y ^ xval[k], etree);
                v = find(w ^ xval[k], otree);
                // cout<<"even: "<<u _ (w ^ y ^ xval[k])<<endl;
                // cout<<"odd: "<<v _ (w ^ xval[k])<<endl;
                create(xval[k], otree);
            }
            else{
                remove(xval[k], etree);
                u = find(w ^ xval[k], etree);
                v = find(w ^ y ^ xval[k], otree);
                // cout<<"even: "<<u _ (w ^ xval[k])<<endl;
                // cout<<"odd: "<<v _ (w ^ y ^ xval[k])<<endl;
                create(xval[k], etree);
            }
            
            cout<<max(u, v)<<" "<<endl;
        }
        else{
            cin>>k;
            y= (y^ k);
        }
    }
    cout<<endl;
    for(i=0;i<trash.size();i++){
        delete trash[i];
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}


