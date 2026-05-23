class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long out =0, count =0, temp = k, n = happiness.size(), i = n-1;
        while( temp && i >=0 ){
            if(happiness[i] > count){
                out += happiness[i]-count;
                i--;
                count++;
                temp--;
            } else break;
            
            
        }
        return out ;
    }
};