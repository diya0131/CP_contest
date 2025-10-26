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
    int a, b, c;
    string s;
    cin>>s;
    a=s.size()-1;
    b=0;
    while(s[b]!='.'){
        cout<<s[b];
        b++;
    }
    if(s[a]=='0'){
        if(s[a-1]=='0'){
            if(s[a-2]=='0'){
            } else {
                cout<<"."<<s[a-2];
            }
        } else {
            cout<<"."<<s[a-2]<<s[a-1];
        }
    }else {
        cout<<"."<<s[a-2]<<s[a-1]<<s[a];
    }
}