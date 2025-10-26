#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ss second
#define test if(te) cout

using namespace std;

const bool te = 0;

ll take(ll a, ll b, ll v){
    if(a>b) swap(a, b);
    ll i, j, k, res=LLONG_MAX/2, t, s;
    for(i=-b+1;i<b;i++){
        if(i!=0 && (v-a*i)!=0 && (v-a*i)%b==0){
            res=min(res, abs(i)+abs(v-a*i)/b);
        }
    }

    return res;
}

ll take3(ll a1, ll b1, ll c1, ll v){
    ll i, j, k, res=LLONG_MAX/2;
    ll a=min(a1, min(b1, c1)), c=max(a1, max(b1, c1)), b=(a1+b1+c1)-a-c;
    for(i=-b+1;i<b;i++){
        for(j=-c+1;j<c;j++){
            if(i!=0 && j!=0 && (v-i*a-j*b)!=0 && (v-i*a-j*b)%c==0){
                res=min(res, abs(i)+abs(j)+abs(v-i*a-j*b)/c);
            }
        }
    }

    return res;
}

ll take31(ll a1, ll b1, ll c1, ll v){
    ll i, j, k, res=LLONG_MAX/2;
    ll a=min(a1, min(b1, c1)), c=max(a1, max(b1, c1)), b=(a1+b1+c1)-a-c;
    for(i=-b+1;i<b;i++){
        for(j=-c+1;j<c;j++){
            if((v-i*a-j*b)%c==0){
                res=min(res, abs(i)+abs(j)+abs(v-i*a-j*b)/c);
            }
        }
    }

    return res;
}

void solve(){
    ll a, b, c, i, j, k, x, y, xmi, ymi;
    cin>>a>>b>>c>>x>>y;
    x=abs(x);
    y=abs(y);
    if(x==0 && y==0) {
        cout<<0<<endl;
        return;
    }
    ll res=LLONG_MAX;
    if(x==0 && y%(b+c)==0){
        res=min(res, (y/(b+c)));
    }
    if(y==0 && x%(a+c)==0){
        res=min(res, (x/(a+c)));
    }
    
    if(x%(a+c)==0 && y%(a+b)==0){
        res=min(res, (y/(a+b)+x/(a+c)));
    }
    if(y%(c+b)==0 && x%(b+a)==0){
        res=min(res, (x/(b+a)+y/(c+b)));
    }

    if(x%(a+b)==0 && y%gcd((a+c), (b+c))==0){
        res=min(res, x/(a+b) + (take((a+c), (b+c), y)));
    }
    if(y%(a+b)==0 && x%gcd((a+c), (b+c))==0){
        res=min(res, y/(a+b) + (take((a+c), (b+c), x)));
    }
    if(x%gcd((a+c), (b+c))==0 && y%gcd((a+c), (b+a))==0){
        res=min(res, (take((a+c), (b+c), x)) + (take((a+c), (b+a), y)));
    }
    if(y%gcd((b+c), (c+a))==0 && x%gcd((a+b), (b+c))==0){
        res=min(res, (take((a+b), (b+c), x)) + (take((b+c), (c+a), y)));
    }
    ll xv = take3(a+b, b+c, c+a, x), yv = take3(a+b, b+c, c+a, y), gall=gcd(a+b, gcd(b+c, a+c));
    if(x%gcd((b+c), (b+a))==0 && y%gall==0){
        res=min(res, (take((b+c), (b+a), x)) + yv);
    }
    if(y%gcd((a+c), (b+a))==0 && x%gall==0){
        res=min(res, xv + (take((a+c), (b+a), y)));
    }
    if(y%gall==0 && x%gall==0) res=min(res, xv+yv);
    
    if(y%(c+b)==0 && x%(c+a)==0){
        res=min(res, (x/(c+a)+y/(c+b)));
    }
    if(y%(c+b)==0 && x%gcd((a+c), (b+a))==0){
        res=min(res, y/(c+b) + (take((a+c), (b+a), x)));
    }
    if(x%gcd((a+c), (b+a))==0 && y%gcd((a+c), (b+c))==0){
        res=min(res, (take((a+c), (b+a), x)) + (take((a+c), (b+c), y)));
    }
    if(y%gcd((a+c), (b+c))==0 && x%gall==0){
        res=min(res, xv + (take((a+c), (b+c), y)));
    }

    if(x%(c+a)==0 && y%gcd((b+c), (b+a))==0){
        res=min(res, x/(c+a) + (take((b+c), (b+a), y)));
    }
    if(x%gcd((a+c), (b+a))==0 && y%gcd((a+b), (b+c))==0){
        res=min(res, (take((a+c), (b+a), x)) + (take((a+b), (b+c), y)));
    }
    if(x%gcd((a+c), (b+a))==0 && y%gall==0){
        res=min(res, yv + (take((a+c), (b+a), x)));
    }

    if(x%gcd((a+c), (b+c))==0 && y%gcd((a+b), (b+c))==0){
        res=min(res, (take((a+c), (b+c), x)) + (take((a+b), (b+c), y)));
    }
    if(y%gcd((a+b), (b+c))==0 && x%gall==0){
        res=min(res, xv + (take((a+b), (b+c), y)));
    }
    if(x%gcd((a+c), (b+c))==0 && y%gall==0){
        res=min(res, yv + (take((a+c), (b+c), x)));
    }
    xmi=take31((a+b), (b+c), (a+c), x-a);
    xmi=min(xmi,take31((a+b), (b+c), (a+c), x-a));
    xmi=min(xmi,take31((a+b), (b+c), (a+c), x-a));
    xmi=min(xmi,take31((a+b), (b+c), (a+c), x-a));
    xmi=min(xmi,take31((a+b), (b+c), (a+c), x-a));
    res = min(res, 6+min(take31((a+b), (b+c), (a+c), x-a)))

    if(res==LLONG_MAX) {
        cout<<"impossible\n";
        return;
    }
    cout<<res*2<<endl;
}


int main(){
    
    int t;
    solve();
}