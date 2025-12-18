#include<bits/stdc++.h>
using namespace std;

int random_min_cut(int n,vector<pair<int,int>> edgeLlist){

    while(n-->2){
        int r = (rand()%(edgeLlist.size()-1));
        auto edge = edgeLlist[r];
        edgeLlist.erase(edgeLlist.begin()+r);

        for(auto &i: edgeLlist){
            if(i.second==edge.second) i.second = edge.first;
            if(i.first==edge.second) i.first = edge.first;
        }

        for(auto it=edgeLlist.begin(); it!=edgeLlist.end(); ){
            if(it->first==it->second) it=edgeLlist.erase(it);
            else ++it;
        }
    }

    return edgeLlist.size();
}

int main(){
    int n, e; cin>>n>>e;
    vector<pair<int,int>> edgeList(e);
    for(auto &i: edgeList) cin>>i.first>>i.second;
    int ans=random_min_cut(n,edgeList);
    cout<<"Min cut cost: "<<ans<<endl;
}