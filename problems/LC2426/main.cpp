#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    void mergeSort(vector<int>& nums, int start, int end, int d, long long& count) {
        if (start == end) 
            return;

        int mid = (start + end) / 2;
        mergeSort(nums, start, mid, d, count);
        mergeSort(nums, mid + 1, end, d, count);

        int l = start, r = mid + 1;
        while (l <= mid && r <= end) {
            if (nums[l] <= nums[r] + d) {
                count += (end - r + 1);
                l++;
            } else {
                r++;
            }
        }

        vector<int> temp(end - start + 1);
        int i = start, j = mid + 1, k = 0;

        while (i <= mid && j <= end) 
        {
            if (nums[i] <= nums[j]) 
                temp[k++] = nums[i++];
            else 
                temp[k++] = nums[j++];
        }
        while (i <= mid) temp[k++] = nums[i++];
        while (j <= end) temp[k++] = nums[j++];


        for (int i = 0; i < temp.size(); i++) 
            nums[start + i] = temp[i];
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> sub(n);
        for (int i = 0; i < n; i++) 
            sub[i] = nums1[i] - nums2[i];

        long long ans = 0;
        mergeSort(sub, 0, n - 1, diff, ans);

        return ans;
    }
};
