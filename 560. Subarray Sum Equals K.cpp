class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        map<int, int>mp;
        mp[0]=1;
        int cnt=0, total=0;
        for(auto it:nums)
        {
            total+=it;
            cnt+=mp[total-k];
            mp[total]++;
        }

        return cnt;
    }
};
