#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    ll num,q,w,a,b,c,temp;
    cin>>num;
    char d,cmp[6]={'U','D','R','L','F','B'};
    vector <ll> dp[6];
    for(int i=0;i<6;i++){
        dp[i].push_back(0);
    }
    for(int i=0;i<num;i++){
        cin>>d>>w;
        for(int j=0;j<6;j++){
            if(d==cmp[j]){
                dp[j].push_back(dp[j][dp[j].size()-1]+w);
                break;
            }
        }
    }
    // U,D,R,L,F,B
    cin>>q;
    while(q--){
        cin>>a>>b>>c;
        if(a<0){
            temp=dp[3].size();
            cout<<dp[3][min(-a,temp-1)]<<endl;
        }
        else if(a>0){
            temp=dp[2].size();
            cout<<dp[2][min(a,temp-1)]<<endl;
        }
        else if(b<0){
            temp=dp[1].size();
            cout<<dp[1][min(-b,temp-1)]<<endl;
        }
        else if(b>0){
            temp=dp[0].size();
            cout<<dp[0][min(b,temp-1)]<<endl;
        }
        else if(c<0){
            temp=dp[5].size();
            cout<<dp[5][min(-c,temp-1)]<<endl;
        }
        else{
            temp=dp[4].size();
            cout<<dp[4][min(c,temp-1)]<<endl;
        }
    }
    return 0;
}
/*
3
D 2
L 5
U 1
1
-1 0 0
*/
