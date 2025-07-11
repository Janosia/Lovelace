#include <iostream>
#include <vector>

using namespace std;

class DSU{
    public:
        vector<int>Parent, Rank;
        int components;
        DSU(int n){
            Parent.resize(n);
            Rank.resize(n,0);
            for(int i =0; i<n; i++)Parent[i] = i;
            components = n;
        }
        int Find(int x){
            return Parent[x] == x ? x : Find(Parent[x]);
        }
        bool Union(int x, int y){
            int xset = Find(x), yset = Find(y);

            if(xset != yset){
                int rx = Rank[xset], ry = Rank[yset];

                if(rx > ry){
                    Parent[yset] = xset;
                }else if(ry < rx){
                    Parent[xset] = yset;
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

vector<int> main(vector<vector<int>>edges){
    DSU dsu(n);
    for(auto edge : edges){
        if(!dsu.union(edge[0], edge[1])) return edge;
    }
    return {};
}