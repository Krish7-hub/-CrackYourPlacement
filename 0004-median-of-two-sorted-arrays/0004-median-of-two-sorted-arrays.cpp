class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Brute Force
        // vector<int>temp;
        // int n = nums1.size();
        // int m = nums2.size();
        // int i = 0;
        // int j = 0;
        // while(i < n && j < m){
        //     if(nums1[i] <= nums2[j]){
        //         temp.push_back(nums1[i]);
        //         i++;
        //     }
        //     else{
        //         temp.push_back(nums2[j]);
        //         j++;
        //     }
        // }
        // while(i < n){
        //     temp.push_back(nums1[i]);
        //     i++;
        // }
        // while(j < m){
        //     temp.push_back(nums2[j]);
        //     j++;
        // }

        // int len = temp.size();
        // if(len % 2 == 1){
        //     return (double)temp[len/2];
        // }
        // return (double)(temp[len/2] + temp[len/2-1])/2.0;

        // Better Approach

        int n = nums1.size();
        int m = nums2.size();
        int ind2 = (n+m)/2;
        int ind1 = ind2 - 1;
        int ele1 = 0, ele2 = 0;
        int i = 0, j = 0;
        int cnt = 0;
        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                if(cnt == ind1) ele1 = nums1[i];
                if(cnt == ind2) ele2 = nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt == ind1) ele1 = nums2[j];
                if(cnt == ind2) ele2 = nums2[j];
                cnt++;
                j++;
            }
        }

        while(i < n){
            if(cnt == ind1) ele1 = nums1[i];
            if(cnt == ind2) ele2 = nums1[i];
            cnt++;
            i++;
        }

        while(j < m){
            if(cnt == ind1) ele1 = nums2[j];
            if(cnt == ind2) ele2 = nums2[j];
            cnt++;
            j++;   
        }

        if((n+m) % 2 == 1){
            return ele2;
        }

        return (double)(ele1 + ele2)/2.0;


    }
};