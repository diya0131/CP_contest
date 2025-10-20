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

void solve() {
    ll n, i, j, t, k, c=0, l=0;
    cin>>n;
    string s;
    cin>>s;
    queue< int > q;
    for(i=0;i<n;i++){
        if(s[i]=='1'){
            if(c==1){
                cout<<"NO\n";
                return;
            }
            j=1;
            while(c){
                q.push(i-j);
                c--;
                j++;
            }
            q.push(i);
        } else {
            c++;
        }
    }
    if(c==1){
        cout<<"NO\n";
        return;
    }
    j=1;
    while(c){
        q.push(i-j);
        c--;
        j++;
    }
    cout<<"YES\n";
    while(!q.empty()){
        cout<<q.front()+1<<" ";
        q.pop();
    }
    cout<<endl;
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}