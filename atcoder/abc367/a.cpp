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



int main() {
    ll a, b, c, i, p, r = 0;
    for (i = 0;i < 1e1;i++) {
        p = i;
        // p += 1e5 * (p / (10000) % 10);
        // p += 1e4 * (p / (1000) % 10);
        // p += 1e5 * (p / (100) % 10);
        // p += 1e2 * (p / (10) % 10);
        p += 1e1 * (p / (1) % 10);
        if(p%7==0){
            r=max(p, r);
        }
    }
    cout<<r<<endl;
}

switch(k){
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;

    case 5:
        break;

    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    
}