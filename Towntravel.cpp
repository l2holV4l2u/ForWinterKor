#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll num,m,q,u,v,w,cur=0,dis[300010]={0},ind=0,ci;
vector <tuple <ll,ll,ll>> edge;
vector <tuple <ll,ll,ll,ll>> query;
vector <ll> pa;
    
ll fp(ll cur){
    if(pa[cur]==cur){
        return cur;
    }
    return pa[cur]=fp(pa[cur]); 
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>num>>m>>q;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        edge.push_back({w,u,v});
    }
    for(int i=0;i<q;i++){
        cin>>u>>v>>w;
        query.push_back({w,u,v,i});
    }
    for(int i=0;i<num;i++){
        pa.push_back(i);
    }
    sort(edge.begin(),edge.end());
    sort(query.begin(),query.end());
    while(get<0>(edge[0])>get<0>(query[ind])){
        ind++;
    }
    for(int i=0;i<edge.size();i++){
        tie(w,u,v)=edge[i];
        cur=w;
        while(cur==w&&i<edge.size()){
            ll a=fp(u),b=fp(v);
            if(a!=b){
                pa[b]=pa[a];
            }
            i++;
            tie(w,u,v)=edge[i];
        }
        if(i==edge.size()){
            for(;ind<q;ind++){
                tie(w,u,v,ci)=query[ind];
                if(cur<=w){
                    dis[ci]=(fp(u)==fp(v));
                }    
                else{
                    break;
                }
            }
            break;
        }
        while(w<cur){
            ind++;
        }
        for(;ind<q;ind++){
            tie(w,u,v,ci)=query[ind];
            if(cur<=w&&w<get<0>(edge[i])){
                dis[ci]=(fp(u)==fp(v));
            }
            else{
                break;
            }
        }
        i--;
    }
    for(int i=0;i<q;i++){
        cout<<(dis[i] ? "Yes":"No")<<"\n";
    }
    return 0;
}
/*
7 8 3
0 1 4
2 5 6
4 2 4
3 1 7
4 1 3
2 1 11
3 5 10
6 5 4
5 3 1
1 6 5
0 6 7
0
0 1 2 3 4 5 6
3
0 4 2 3 4 5 6
4
0 4 0 3 0 6 6
6
0 4 0 3 0 6 0
7
3 4 0 3 0 6 0
10
3 4 0 3 0 6 0
11
3 4 0 3 0 6 0
Yes
No
Yes
*/
