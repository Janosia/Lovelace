#include <iostream>
#include <vector>
using namespace std;
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    int len = equations.size();
    using  T = tuple<string, double>;
    map<string, vector<T>>adj;
    for(int i =0; i<len; i++){
        string u = equations[i][0], v = equations[i][1];
        double wt = values[i];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, 1/wt});
    }
    vector<double>out;
    for(auto &q : queries){
        string s = q[0], e = q[1];
        if(s==e && !adj[s].empty()){
            out.push_back(1.0);
            continue;
        }else if (adj[s].empty() || adj[e].empty()){
            out.push_back(-1.0);
            continue;
        }else{
            map<string, double>vis;
            queue<T>bfs;
            bfs.push({s, 1.0});
            vis[s] = 1.0;
            while(!bfs.empty()){
                auto [node, val] = bfs.front();
                bfs.pop();
                if(node == e){
                    break;
                }
                for(auto &neib : adj[node]){
                    auto [new_node, wt] = neib;
                    double new_wt = val * wt;
                    if(vis[new_node]!= 0.0 && 
                    vis[new_node] < new_wt){
                        vis[new_node] = new_wt;
                        bfs.push({new_node, new_wt});
                    }else if (vis[new_node] == 0.0){
                        vis[new_node] = new_wt;
                        bfs.push({new_node, new_wt});
                    }else continue;
                }
            }
            if(vis[e]){
                out.push_back(vis[e]);
            }else out.push_back(-1.0);
            
        }
    }
    return out;
}
