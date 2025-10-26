#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    int n, x, y, i, j, k, m;
    string s;
    cin>>n>>s;
    int r[4], h[4];
    for(i=0;i<4;i++){
        r[i]=0;
        h[i]=0;
    }
    for(i=0;i<n;i++){
        switch (s[i])
        {
        case 'N':
             r[0]++;
            break;
        case 'S':
             r[1]++;
            break;
        case 'E':
             r[2]++;
            break;
        case 'W':
             r[3]++;
            break;
        }
    }
    if((r[0]+r[1])%2 || (r[2]+r[3])%2){
        cout<<"NO"<<endl;
        return;
    }
    else{
        h[0]=r[0]/2;
        h[1]=r[1]/2;
        h[2]=(r[2]+1)/2;
        h[3]=(r[3]+1)/2;
    }
    if(h[0]+h[1]+h[2]+h[3]>0 && h[0]+h[1]+h[2]+h[3]!=n){
        for(i=0;i<n;i++){
            switch (s[i])
            {
            case 'N':
                j=0;
                break;
            case 'S':
                j=1;
                break;
            case 'E':
                j=2;
                break;
            case 'W':
                j=3;
                break;
            }
            if(h[j]>0){
                cout<<"H";
                h[j]--;
            }
            else{
                cout<<"R";
            }
        }
    }
    else{
        
        cout<<"NO";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}