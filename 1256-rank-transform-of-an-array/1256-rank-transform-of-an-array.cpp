class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n = arr.size(); // get the size of the input array.
        if(n == 0)
            return {};
        
        //create a set ot store unique elements in sorted order
        set<int>uniqueElements(arr.begin(), arr.end());

        //create a hash mp (unordered_map) to store the rank of each unique element.
        unordered_map<int, int> ranks;
        int rank = 1;
        for(const int &ele : uniqueElements)
            ranks[ele] = rank++;
        vector<int> ans;
        for(int &ele : arr){
            ans.push_back(ranks[ele]);
        }
        return ans;
    }
};