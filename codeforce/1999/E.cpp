#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

#include <random>



using namespace std;

random_device rd;     // Only used once to initialise (seed) engine
mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
uniform_int_distribution<int> uni(1,1e5); // Guaranteed unbiased

const bool te = false;

ll get(ll k) {
    if (k < 3) return k;
    ll a = 2, n = 1, res = 2;
    while ((a + 1) * 3 - 1 <= k) {
        res += 2 * (a + 1) * (n + 1);
        a = (a + 1) * 3 - 1;
        n++;
    }
    res += (k - a) * (n + 1);
    test << "get" _ k _ a _ n _ res << endl;
    return res;
}
ll take(ll k) {
    ll a = 2, n = 1;
    while (a < k) {
        a = (a + 1) * 3 - 1;
        n++;
    }
    test << "take " _ k _ n << endl;
    return n;
}

int solve(int l, int r) {
    ll n, m, i, j, k;
    
    k = take(l);
    return get(r) - get(l - 1) + k ;
    
}

int bd(int l, int r){
	
    
    int ans=0, k=12;
   
    int ma = 177147;
    while(r>=l){
        while(ma > r){
            ma=ma/3;
            k--;
        }
        while(r>=l && r>=ma){
            ans+=k;
            r--;
        }
    }
    return ans+k;
	
}



int main() {
    int t;
    cout<<10000<<endl;
    for(ll i=0;i<10000;i++){
        cout<<1 _ 2e5<<endl;
    }
   
}