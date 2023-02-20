class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (!m)
            nums1 = nums2;

        int nums1Idx = m-1;
        int nums2Idx = n-1;
        int writeIdx = nums1.size() - 1;

        int nums1Val, nums2Val;
        while (nums1Idx >= 0 && nums2Idx >= 0)
        {   
            nums1Val = nums1[nums1Idx];
            nums2Val = nums2[nums2Idx];

            if (nums1Val >= nums2Val)
            {
                nums1[writeIdx--] = nums1Val;
                --nums1Idx;
            }
            else
            {
                nums1[writeIdx--] = nums2Val;
                --nums2Idx;
            }
        }

        for(; nums2Idx >= 0; --nums2Idx)
            nums1[writeIdx--] = nums2[nums2Idx];
    }
};
