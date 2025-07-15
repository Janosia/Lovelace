#include<vectors>
#include <iostream>

using namespace std;
class DSU{
public:
    vector<int>Parent, Rank;
    int components;
        
    DSU(int n){
        Rank.resize(n,0);
        Parent.resize(n);
        for(int i = 0; i<n ; i++)Parent[i] = i;
        components=n;
    }

    int Find(int x){
        return Parent[x] ==  x ? x: Find(Parent[x]);
    }

    bool Union(int x, int y){
        int xset = Find(x), yset = Find(y);
        if(xset != yset){
            int rx = Rank[xset], ry = Rank[yset];
            if(rx < ry){
                Parent[xset] = yset;
            }else if (ry < rx){
                Parent[yset] = xset;
            }else{
                Parent[yset] = xset;
                Rank[xset]++;
            }
            components--;
            return true;
        }
        return false;
    }
};
int condition(int &time, int &n ,int &k, vector<vector<int>>& edges){
    DSU dsu(n);
    for(auto &edge:edges){
        //  only include edges having timestamp greater than current time
        if(edge[2] > time ){ 
            dsu.Union(edge[0], edge[1]);
        }
    }
    return dsu.components >= k;
}
int minTime(int n, vector<vector<int>>& edges, int k) {
    if(k>n) return -1;
    
    auto comp = [&](const vector<int>& i, const vector<int>& j){
        return i[2] > j[2];
    };
    sort(edges.begin(), edges.end(), comp);
    DSU dsu(n);
    for(auto &edge : edges){
        int u = edge[0], v = edge[1], time = edge[2];
        dsu.Union(u, v) ;
        if(dsu.components <k) return time;
    }
    return 0;
}
