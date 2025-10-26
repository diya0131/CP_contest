#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    int n, a, b, x, m, y, s, i, j, k, t;
    cin>>a>>b>>n>>m;
    char ch;
    int arr[a+1][b+1], sum[a][b];
    for(i=0;i<=a;i++){
        for(j=0;j<=b;j++){
            arr[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        cin>>x>>y;
        arr[x][y]=1;
    }
    for(i=0;i<=a;i++){
        s=0;
        for(j=0;j<=b;j++){
            if(arr[i][j]==1) s++;
            arr[i][j]=s;
        }
    }
    for(i=1;i<=a;i++){
        for(j=0;j<=b;j++){
            arr[i][j]+=arr[i-1][j];
        }
    }
    // for(i=0;i<a;i++){
    //     for(j=0;j<b;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int d = a, u = 1, l = 1, r = b;
    ll al=0, bo=0;
    bool isAl = true;
    while(m--){
        cin>>ch>>k;
        switch (ch)
        {
        case 'D':
            t=arr[d][r] - arr[d-k][r] - arr[d][l-1] + arr[d-k][l-1];
            d = d-k;
            break;
        case 'U':
            t=arr[u+k-1][r] - arr[u-1][r] - arr[u+k-1][l-1] + arr[u-1][l-1];
            u= u+k;
            break;

        case 'L':
            t=arr[d][l+k-1] - arr[u-1][l+k-1] - arr[d][l-1] + arr[u-1][l-1];
            l= l+k;
            break;
        case 'R':
            t=arr[d][r] - arr[u-1][r] - arr[d][r-k] + arr[u-1][r-k];
            r= r-k;
            break;
        }
        // cout<<t _ d _ u _ l _ r<<endl;
        if(isAl) al+=t;
        else bo+=t;
        isAl = !isAl;
    }
    cout<<al<<" "<<bo<<endl;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}