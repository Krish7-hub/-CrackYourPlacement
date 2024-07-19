double pref = 1;
double suff = 1;
double  ans = INT_MIN;
int n = nums.size();
for(int i = 0; i < n; i++){
  if(pref == 0) pref = 1;
  if(suff == 0) suff = 1;
  pref = pref * nums[i];
  suff = suff * nums[n - i - 1];
  ans = max(ans, max(pref, suff));
}
return ans;
