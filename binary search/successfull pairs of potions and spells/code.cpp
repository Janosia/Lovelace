class Solution {
public:
    long long func(vector<int>& potions, long long spell, int mid){
        long long prod  = potions[mid] * spell;
        return prod;
    }
    int bin_search(vector<int>& potions, long long success, int spell){
        int low = 0, high = potions.size()-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(func(potions, spell, mid)>= success){
                high = mid-1;
            } else low = mid+1;
        }
        return potions.size()-low;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int>out;
        for(auto &s : spells){
            int temp = bin_search(potions, success, s);
            out.push_back(temp);
        }
        return out;
    }
};