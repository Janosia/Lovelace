/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        if(target == mountainArr.get(0)) return 0;
        
        int len = mountainArr.length(), low = 1 ;
        cout << "length of array is "<< len <<endl;
        int  high =  len-1, centre ;
        while(low <= high){
            
            int mid = (low+high)/2;
            centre = mountainArr.get(mid);
            int left = mountainArr.get(mid-1);
            int right = mountainArr.get(mid+1);
            
            if(centre > left && centre > right) {
                if(target > centre ) return -1;
                if(target == centre ) return mid;
                centre = mid;
                break;
            }
            
            else if (left < centre && centre < right) low = mid+1;

            else high = mid-1;
        }

        
        low =0, high = centre-1;
        while(low <= high){
            int mid = (low+high)/2;
            int el = mountainArr.get(mid);
            if(target == el ) return mid;
            else if (target > el ) low = mid+1;
            else high = mid-1;
        }
        
        low = centre+1 , high = len-1;
        while( low <= high ){
            int mid = (low+high)/2;
            int el = mountainArr.get(mid);
            if(target == el ) return mid ;
            else if (target > el ) low = mid+1;
            else high= mid-1;
        }
        
        if(target == mountainArr.get(len-1)) return len-1 ;
        return -1; 
    }
};