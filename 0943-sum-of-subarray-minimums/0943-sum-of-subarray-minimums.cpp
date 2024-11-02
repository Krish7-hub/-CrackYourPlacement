class Solution {
public:
    
    vector<int>findnse(vector<int>&arr){
        int n = arr.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int>findpse(vector<int>& arr){
        int n = arr.size();
        vector<int>pse(n);
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }



    int sumSubarrayMins(vector<int>& arr){
        int mod = (int)(1e9 + 7);
        int n = arr.size();
        long total = 0;
        vector<int>nse;
        nse = findnse(arr);
        vector<int>pse;
        pse = findpse(arr);
        for(int i = 0; i < n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + (right * left * 1LL * arr[i])%mod)%mod;
        }
        return total;
    }
};