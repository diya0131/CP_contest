#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ALL(a) a.begin(), a.end()
#define ss second
#define test if(te) cout

using namespace std;

const bool te = 0;

void solve() {
    string s;
    cin >> s;
    if (s.size() < 3) {
        cout << "NO\n";
        return;
    }
    if (s[0] == '1' && s[1] == '0') {
        if (s.size() == 3) {
            if (s[2] - '0' >= 2) {
                cout << "YES\n";
                return;
            } else {
                cout << "NO\n";
                return;
            }
        }
        if (s[2] != '0') {
            cout << "YES\n";
            return;
        } else {
            cout << "NO\n";
            return;
        }
    } else {
        cout << "NO\n";
        return;
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}