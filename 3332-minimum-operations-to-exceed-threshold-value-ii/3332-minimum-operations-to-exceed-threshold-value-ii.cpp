class Solution {
public:
    #define ll long long
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> minheap(nums.begin(), nums.end());
        int count = 0;
        while(!minheap.empty()){
            ll min1 = minheap.top();
            minheap.pop();
            if(min1 >= k){
                break;
            }
            ll min2 = minheap.top();
            minheap.pop();
            ll val = min(min1, min2) * 2 + max(min1, min2);
            minheap.push(val);
            count++;
        }
        return count;
    }
};