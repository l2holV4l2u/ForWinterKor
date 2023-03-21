	#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

ll cnt(ll num,ll div){
    ll sum=0,temp,dig=1,i;
    for(i=10;i<=num;i*=10,dig++){
        temp=i/10;
        if((i/10)%div){
            temp+=(div-((i/10)%div));
        }
        if(temp>=i){
            continue;
        }
        sum+=(((i-1-temp)/div)+1)*dig;
    }
    temp=i/10;
    if((i/10)%div){
        temp+=(div-((i/10)%div));
    }
    if(num>=temp){
        sum+=(((num-temp)/div)+1)*dig;
    }
    return sum;
}

ll check(ll num){
    return cnt(num,3)+cnt(num,5)-cnt(num,15);    
}

void solve(ll x){
    ll l=0,r=INT_MAX;
    while(l<r){
        ll mid=(l+r)/2,temp=check(mid);
        if(temp>=x){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    string str=to_string(l);
    ll ind=x-(check(l)-str.length()+1);
    cout<<str[ind]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    ll q,x;
    cin>>q;
    /*for(int i=1;i<=q;i++){
        cout<<i<<" "<<check(i)<<endl;
    }*/
    while(q--){
        cin>>x;
        solve(x);
    }
    return 0;
}
/*
30
1 0
2 0
3 1
4 1
5 2
6 3
7 3
8 3
9 4
10 6
11 6
12 8
13 8
14 8
15 10
16 10
17 10
18 12
19 12
20 14
21 16
22 16
23 16
24 18
25 20
26 20
27 22
28 22
29 22
30 24
*/
