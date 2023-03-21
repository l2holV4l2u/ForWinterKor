#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    ll num,x,y,coor[2]={1,1},temp;
    cin>>num>>x>>y;
    temp=pow(2,num-1);
    for(int i=1;i<num;i++,temp/=2){
        if(x>=coor[0]+temp&&y<coor[1]+temp){
            coor[0]+=temp;
        }
        else if(x<coor[0]+temp&&y>=coor[1]+temp){
            coor[1]+=temp;
        }
        else if(x>=coor[0]+temp&&y>=coor[1]+temp){
            coor[1]+=temp;
            coor[0]+=temp;
            cout<<"W\n";
            return 0;
        }
    }
    if(coor[0]==x&&coor[1]==y){
        cout<<"R\n";
    }
    else if(coor[0]==x&&coor[1]+1==y){
        cout<<"O\n";
    }
    else if(coor[0]+1==x&&coor[1]==y){
        cout<<"Y\n";
    }
    else{
        cout<<"W\n";
    }
    //cout<<coor[0]<<" "<<coor[1]<<" "<<temp;
    return 0;
}
