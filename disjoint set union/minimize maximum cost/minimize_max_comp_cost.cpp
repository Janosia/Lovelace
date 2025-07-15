#include <iostream>
#include <vector>
class DSU{
public:
    vector<int>Parent, Rank;
    int components;

    DSU(int n ){
        components = n;
        Parent.resize(n);
        Rank.resize(n,0);
        for(int i =0; i<n ; i++) Parent[i] = i;
    }

    int Find(int x){
        return Parent[x] = (x == Parent[x]) ? x : Find(Parent[x]);
    }
    bool Union(int x, int y){
        int xset = Find(x), yset = Find(y);
        if(xset!=yset){
            int rx = Rank[xset], ry = Rank[yset];
            if(rx < ry){
                Parent[xset] = yset;
            }else if(rx > ry){
                Parent[yset] = xset;
            }else{
                Parent[yset] = xset;
                Rank[xset]++;
            }
            components --;
            return true;
        }
        return false;
    }
};
bool condition(int mid, int n , vector<vector<int>>& edges , int k){
    DSU dsu(n);
    for(auto &edge : edges){
        if(edge[2] <= mid)dsu.Union(edge[0], edge[1]);
    }
    // cout << "wt is "<< mid << " components are "<< dsu.components;
    return dsu.components <= k;

}
int minCost(int n, vector<vector<int>>& edges, int k) {
    if(edges.empty() or k > n) return 0;
    auto comp = [&](const vector<int>&i, const vector<int>&j){
        return i[2]<j[2];
    };
    sort(edges.begin(), edges.end(), comp);
    int left = 0 , right = edges.back()[2];
    int out = 0;
    while(left <= right){
        int mid = left +(right-left)/2;
        if(condition(mid, n ,edges, k)){
            out = mid;
            right = mid-1;
        }else {left = mid+1;}
    }
    
    return out;
}
