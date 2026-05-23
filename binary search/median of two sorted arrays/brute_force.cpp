class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        int i = 0, j =0;
        vector<int>temp;
        while(i < n && j < m){
            if(nums1[i] < nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            } else {
                temp.push_back(nums2[j]);
                j++;
            }
        }

        while( i < n ) {temp.push_back(nums1[i++]);}
        while( j < m ) {temp.push_back(nums2[j++]);}

        int indx = temp.size();
        double out;
        if( indx % 2 == 0){
            cout << "here"<<endl;
            int i1 = indx/2 , i2 = (indx-1)/2;
            out = temp[i1]+temp[i2];
            out /= 2.0;
        } else out = temp[indx/2];
        return out; 
    }
};