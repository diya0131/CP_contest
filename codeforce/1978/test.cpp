#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ff first
#define ss second
#define PII pair < int, int >
#define PLL pair < ll, ll >

using namespace std;

int main() {
    ll x, y, x1, y1, a, b, a1, b1;
    cin >> a >> b >> a1 >> b1;

    x = min(a, a1);
    y = min(b, b1);
    x1 = max(a, a1);
    y1 = max(b, b1);
    if ((a + b) % 2 == (a > a1)) {
        cout << (y1 - y) + (x1 - x) / 2 - min(y1 - y + 1, x1 - x) / 2 << endl;
    } else {
        cout<<"hi"<<endl;
        cout << (y1 - y) + (x1 - x + 1) / 2 - (min(y1 - y, x1 - x) + 1) / 2 << endl;
    }

}

const int N = 1e5;
class Solution {
public:
    int st[4*N][2];
    void build(vector < int >&a, int v, int tl, int tr){
        if(tl==tr){
            st[v][0]=a[tl];
            st[v][1]=a[tl];
            return;
        }
        int tm = (tl+tr)/2;
        build(a, 2*v, tl, tm);
        build(a, 2*v+1, tm+1, tr);
        st[v][0]=max(st[2*v][0], st[2*v+1][0]);
        st[v][1]=min(st[2*v][1], st[2*v+1][1]);
    }

    int get(int v, int tl, int tr, int l, int r, bool ma){
        if(l>r) {
            if(ma) return INT_MIN;
            return INT_MAX;
        }
        if(tl==l && tr==r){
            if(ma) return st[v][0];
            return st[v][1];
        }
        int tm = (tl+tr)/2;
        if(ma){
            return max(get(2*v, tl, tm, l, min(r, tm), ma), get(2*v+1, tm+1,tr, max(l, tm+1), r, ma) );
        }
        return min(get(2*v, tl, tm, l, min(r, tm), ma), get(2*v+1, tm+1,tr, max(l, tm+1), r, ma) );
    }

    int longestSubarray(vector<int>& nums, int limit) {
        cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
        int l, r, i, k, mi, ma, n=nums.size(), s=0;
        build(nums, 1, 0, n-1);
        l = r = 0;
        while(r<n){
            while(get(1, 0, n-1, l, r, 1) - get(1, 0, n-1, l, r, 0)>limit){
                l++;
            }
            s=max(s, r-l+1);
            r++;
        }
        return s;
    }
};