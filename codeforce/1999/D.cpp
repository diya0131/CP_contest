#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout<<
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = true;

void solve() {
    ll n, m, i, j, k, u, v;
    string s, t;
    cin >> s >> t;
    j = 0;
    for (i = 0;i < s.size();i++) {
        if (j < t.size()) {
            if (s[i] == t[j] || s[i] == '?') {
                s[i] = t[j];
                j++;
            }
        } else {
            if(s[i]=='?') s[i]='a';
        }


    }
    if (j == t.size()) {
        cout << "YES\n" << s << endl;
        return;
    }
    cout << "NO\n";
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}