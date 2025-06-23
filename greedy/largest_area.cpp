#include <iostream>
#include <vector>
#include <map>

long long maxArea(vector<vector<int>>& points) {
    map<int, vector<int>>y,x;
    int min_x =INT_MAX, min_y=min_x, max_x=INT_MIN, max_y=INT_MIN;
    
    // group all y coord for same x coord
    // group all x coord for same y coord
    for(auto &p:points){
        x[p[0]].push_back(p[1]);
        y[p[1]].push_back(p[0]);
        // find minimum and maximum of x & y 
        min_x = min(min_x,p[0]), max_x = max(max_x, p[0]);
        min_y = min(min_y,p[1]), max_y = max(max_y, p[1]);
    }
    long long max_area=0;
    //for all x coords find maximum horizontal(ht)[b/w current x coord and min_x and max_x] & vertical(base)[b/w y coords of same x coord] distance height 
    for(auto &p:points){
        if(x.count(p[0]) && x[p[0]].size()>=2){
            vector<int>y_val = x[p[0]];
            int y_min = *min_element(y_val.begin(), y_val.end()), y_max=*max_element(y_val.begin(), y_val.end());
            long long base = y_max-y_min;
            long long ht = max(abs(p[0]-min_x), abs(p[0]-max_x));
            max_area = max(max_area, base*ht);
        }
    }
    //for all y coords find maximum horizontal(base)[b/w current y coord and min_y and max_y] & vertical(ht)[b/w x coords of same y coord] distance
    for(auto &p:points){
        if(y.count(p[1]) && y[p[1]].size()>=2){
            vector<int>x_val = y[p[1]];
            int x_min = *min_element(x_val.begin(), x_val.end()), x_max=*max_element(x_val.begin(), x_val.end());
            long long base = x_max-x_min;
            long long ht = max(abs(p[1]-min_y), abs(p[1]-max_y));
            max_area = max(max_area, base*ht);
        }
    }
    // return -1 if no triangle is found
    return max_area = max_area==0?-1:max_area;

}