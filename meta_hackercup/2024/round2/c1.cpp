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

const bool TEST = 1;

ll pw[9];
char a[6][7];

pair < bool, bool > check(ll k) {
    char b[6][7];
    int i, j, t, s, c=0, ca=0;
    bool connie = 0, forrest = 0;
  
    for (int j = 0;j < 7;j++) {
        t = (k / pw[j]) % 7;
        ca+=t;
        for (i = 0;i < 6;i++) {
            
            if (i >= 6-t) {
                b[i][j] = a[i][j];
                if(a[i][j]=='C') c++;
            }
            else {
                b[i][j] = '*';
            }
           
        }

    }
    if(c!=(ca+1)/2) return {0, 0};
    for(i=0;i<6;i++){
        for(j=0;j<7;j++) {
            cout<<b[i][j];
        }
        cout<<endl;
    }
  
    for (i = 0;i < 6;i++) {
        for (j = 0;j + 3 < 7;j++) {
            if (b[i][j] == 'C' && b[i][j + 1] == 'C' && b[i][j + 2] == 'C' && b[i][j + 3] == 'C') connie = 1;
            if (b[i][j] == 'F' && b[i][j + 1] == 'F' && b[i][j + 2] == 'F' && b[i][j + 3] == 'F') forrest = 1;
        }
    }
    for (i = 0;i + 3 < 6;i++) {
        for (j = 0;j < 7;j++) {
            if (b[i][j] == 'C' && b[i + 1][j] == 'C' && b[i + 2][j] == 'C' && b[i + 3][j] == 'C') connie = 1;
            if (b[i][j] == 'F' && b[i + 1][j] == 'F' && b[i + 2][j] == 'F' && b[i + 3][j] == 'F') forrest = 1;
        }
    }
    for (i = 0;i + 3 < 6;i++) {
        for (j = 0;j + 3 < 7;j++) {
            if (b[i][j] == 'C' && b[i + 1][j + 1] == 'C' && b[i + 2][j + 2] == 'C' && b[i + 3][j + 3] == 'C') connie = 1;
            if (b[i][j] == 'F' && b[i + 1][j + 1] == 'F' && b[i + 2][j + 2] == 'F' && b[i + 3][j + 3] == 'F') forrest = 1;
        }
    }
    for (i = 0;i + 3 < 6;i++) {
        for (j = 3;j < 7;j++) {
            if (b[i][j] == 'C' && b[i + 1][j - 1] == 'C' && b[i + 2][j - 2] == 'C' && b[i + 3][j - 3] == 'C') connie = 1;
            if (b[i][j] == 'F' && b[i + 1][j - 1] == 'F' && b[i + 2][j - 2] == 'F' && b[i + 3][j - 3] == 'F') forrest = 1;
        }
    }
    cout<<connie _ forrest<<endl;
    return { connie, forrest };
}

void solve() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> a[i][j];
        }
    }
    check(823206);
    // pair < bool, bool > pr, res;
    // res={0, 0};
    // for (ll i = 0;i < pw[7];i++) {
    //     pr = check(i);
    //     if(pr.ff==0 && pr.ss==1) {
    //         cout<<i _ "forr"<<endl;
    //         res.ss=1;
    //     }
    //     if(pr.ff==1 && pr.ss==0) {
    //         cout<<i _ "conn"<<endl;
    //         res.ff=1;
    //     }
    // }
    // if(res.ff ==1 && res.ss==1) cout<<"?\n";
    // else {
    //     if(res.ff+res.ss==0) cout<<"0\n";
    //     else {
    //         if(res.ff==1) cout<<"C\n";
    //         else cout<<"F\n";
    //     }
    // }
}

int main() {
    
    ll q = 1;
    for (int i = 0;i <= 7;i++) {
        pw[i] = q;
        q *= 7;
    }
    
    freopen("cottontail_climb_part_2_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // BOOST
    int t;
    cin >> t;
    for (int i = 1;i <= t;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}