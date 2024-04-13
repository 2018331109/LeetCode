/*
3097. Shortest Subarray With OR at Least K II
You are given an array nums of non-negative integers and an integer k.

An array is called special if the bitwise OR of all of its elements is at least k.

Return the length of the shortest special non-empty
subarray
of nums, or return -1 if no special subarray exists.

*/
//sliding window
#define ll long long
class Solution
{
public:
    int minimumSubarrayLength(vector<int>& a, int k)
    {
        ll n=a.size();
        ll l=0, r=0, ans=INT_MAX, cnt=0;
        vector<ll>v(32);
        while(r<n)
        {
            cnt|=a[r];
            int it=a[r], j=0;
            while(it)
            {
                if(it%2)
                {
                    v[j]++;
                }
                j++;
                it/=2;
            }

            if(cnt>=k)
            {
                while(cnt>=k and r>=l)
                {
                    ans=min(ans, r-l+1);
                    ll it=a[l], j=0;
                    while(it)
                    {
                        if(it%2)
                        {
                            v[j]--;
                            if(v[j]==0)
                            {
                                cnt-=pow(2, j);
                            }
                        }
                        it/=2;
                        j++;
                    }
                    l++;
                }
            }
            r++;
        }
        cout<<ans<<endl;
        if(ans==INT_MAX)
        {
            ans=-1;
        }
        return ans;

    }
};

