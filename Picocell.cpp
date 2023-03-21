#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll num,m,q,u,v,t,sz[100010],par[100010],tu,tv,maxi=1;
    
vector <tuple <ll,ll,ll>> dat;
vector <pair <ll,ll>> temp;    

ll fp(ll cur){
    if(par[cur]==cur){
        return cur;
    }
    return par[cur]=fp(par[cur]);
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>num>>m>>q;
    for(int i=0;i<m;i++){
        cin>>u>>v>>t;
        dat.push_back({t,u,v});
    }
    for(int i=1;i<=num;i++){
        sz[i]=1;
        par[i]=i;
    }
    sort(dat.begin(),dat.end());
    temp.push_back({0,1});
    //t , max group
    //cout<<endl;
    for(int i=0;i<m;i++){
        tie(t,u,v)=dat[i];
        tu=fp(u),tv=fp(v);
        //cout<<u<<" "<<v<<" "<<t<<endl;
        if(tu!=tv){
            par[tv]=par[tu];
            sz[tu]+=sz[tv];
            //cout<<sz[tu]<<endl;
            if(maxi<sz[tu]){
                temp.push_back({t,sz[tu]});
                maxi=sz[tu];
            }
        }
    }
    while(q--){
        cin>>u;
        cout<<temp[upper_bound(temp.begin(),temp.end(),make_pair(u,LLONG_MAX))-temp.begin()-1].second<<endl;
    }
    /*for(int i=0;i<temp.size();i++){
        cout<<temp[i].first<<" "<<temp[i].second<<endl;
    }*/
    return 0;
}
/*
0 1
2 2
3 3
6 4
10 6
12 8
/*
8 9 5
1 8 2
8 3 25
8 2 10
2 3 6
3 4 3
6 7 8
7 3 17
5 6 12
3 5 3
3
1
10
30
7
*/
