class Solution {
public:
    vector<int> findNextSmaller(vector<int>&nums){
        int n = nums.size();
        vector<int>nextSmall(n);
        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            nextSmall[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nextSmall;
    }

    vector<int> findPrevSmaller(vector<int>&nums){
        int n = nums.size();
        vector<int>prevSmall(n);
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            prevSmall[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prevSmall;
    }
    
    
    long long findSmallestSum(vector<int>& nums){
        int n = nums.size();
        vector<int>nextSmaller(n);
        nextSmaller = findNextSmaller(nums);
        vector<int>prevSmaller(n);
        prevSmaller = findPrevSmaller(nums);
        long long total = 0;
        for(int i = 0; i < n; i++){
            int left = i - prevSmaller[i];
            int right = nextSmaller[i] - i;
            total = (total + (right * left * 1LL * nums[i]));
        }
        return total;
    }

    vector<int> findNextLarger(vector<int>&nums){
        int n = nums.size();
        vector<int>nextLarge(n);
        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            nextLarge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nextLarge;
    }

    vector<int> findPrevLarger(vector<int>&nums){
        int n = nums.size();
        vector<int>prevLarge(n);
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            prevLarge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prevLarge;
    }

    long long findLargestSum(vector<int>& nums){
        int n = nums.size();
        vector<int>nextLarger(n);
        nextLarger = findNextLarger(nums);
        vector<int>prevLarger(n);
        prevLarger = findPrevLarger(nums);
        long long  total = 0;
        for(int i = 0; i < n; i++){
            int left = i - prevLarger[i];
            int right = nextLarger[i] - i;
            total = (total + (right * left * 1LL * nums[i]));
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {

        long long smallest = findSmallestSum(nums);
        long long largest = findLargestSum(nums);
        return largest - smallest;
        
    }
};