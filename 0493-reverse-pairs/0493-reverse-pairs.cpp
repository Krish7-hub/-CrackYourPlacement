class Solution {
public:
    int find(vector<int>& nums, int low, int mid, int high){
        int cnt = 0;
        int right = mid + 1;
        for(int i = low; i <= mid; i++){
            // long long val = 2 * nums[right];
            while(right <= high && nums[i] > (2 * (long long)nums[right])) {
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int>temp;
        int left = low;
        int right = mid+1;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = low; i <= high; i++){
            nums[i] = temp[i-low];
        }
    }
    int mergeSort(vector<int>& nums, int low, int high){
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = (low + high)/2;
        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid+1, high);
        cnt += find(nums, low, mid, high);
        merge(nums, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {

        int n = nums.size();
        int low = 0;
        int high = n - 1;
        return mergeSort(nums, low, high);
    }
};