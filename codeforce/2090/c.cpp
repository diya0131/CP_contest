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
    int n, i, j, s, k, t, x, y;
    cin>>n;
    pair < int, pair < int, int > > pr;
    // zai, x, y
    priority_queue< pair < int, pair < int, int > > > q;
    priority_queue< pair < int, pair < int, int > > > qn;
    map < pair < int, int >, bool > mp;
    k = sqrt(2*n);
    k+=5;
    for(i=0;i<k;i++){
        for(j=0;j<k-i;j++){
            x = 3*i+1;
            y = 3*j+1;
            mp[{-x, -y}] = 1;
            q.push({-x-y, {-x, -y}});
            qn.push({-x-y, {-x, -y}});
            x = 3*i+2;
            y = 3*j+1;
            mp[{-x, -y}] = 1;
            q.push({-x-y, {-x, -y}});
            x = 3*i+1;
            y = 3*j+2;
            mp[{-x, -y}] = 1;
            q.push({-x-y, {-x, -y}});
            x = 3*i+2;
            y = 3*j+2;
            mp[{-x, -y}] = 1;
            q.push({-x-y-2, {-x, -y}});
        }
    }
    for(i=0;i<n;i++){
        cin>>t;
        if(t==1){
            pr = q.top();
            q.pop();
            while(!mp[pr.ss]){
                pr = q.top();
                q.pop();
            }
            if(mp[pr.ss]){
                mp[pr.ss] = 0;
                cout<<-pr.ss.ff _ -pr.ss.ss<<endl;
            } 
        } else {
            pr = qn.top();
            qn.pop();
            while(!mp[pr.ss]){
                pr = qn.top();
                qn.pop();
            }
            if(mp[pr.ss]){
                mp[pr.ss] = 0;
                cout<<-pr.ss.ff _ -pr.ss.ss<<endl;
            } 
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}