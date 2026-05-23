class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n = nums1.size(), m = nums2.size(), i=0, j =0;
       int count = 0, indx1 = (n+m)/2, indx2 = indx1-1;
       int e1, e2;
       while (i < n && j < m){
        if(nums1[i] < nums2[j]){
            if(count == indx1) e1 = nums1[i];
            if(count == indx2) e2 = nums1[i];
            i++;
            count++;
        } else {
            if(count == indx1) e1 = nums2[j];
            if(count == indx2) e2 = nums2[j];
            j++;
            count++;
        }
       }
       while(i < n){
        if(count == indx1) e1 = nums1[i];
        if(count == indx2) e2 = nums1[i];
        i++;
        count++;
       }
       while(j < m){
        if(count == indx1) e1 = nums2[j];
        if(count == indx2) e2 = nums2[j];
        j++;
        count++;
       }
       if((n+m) % 2 == 1) return (double) e1;
       return ((double) e1 + (double) e2)/2.0;
    }
};