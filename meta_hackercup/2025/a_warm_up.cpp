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

void solve(int idx) {
    
    int n, s=0;
    cin>>n;
    map <int, int>mp;
    bool can = true;
    vector<int>a(n), b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]=i;
        // cout<<a[i] _ i<<" -\n";
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]<a[i]) can = false;
    }
    if(!can){
        cout<<"Case #"<<idx<<": -1\n";
        return;
    }
    vector<pair<int, pair<int, int>>> res;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]) continue;
        s++;
        
        if(mp.find(b[i])==mp.end()){
            can = false;
            break;
        } else{
            res.push_back({a[i], {i+1, mp[b[i]]+1}});
        }
    }
    if(!can){
        cout<<"Case #"<<idx<<": -1\n";
        return;
    }
    cout<<"Case #"<<idx<<": "<<s<<"\n";
    sort(ALL(res));
    for(int i=0;i<s;i++){
        
        cout<<res[i].ss.ss _ res[i].ss.ff<<endl;
    }
}

int main() {
    freopen("input/warm_up_input.txt", "r", stdin);
    freopen("output/warm_up_output.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve(i+1);
    }
}