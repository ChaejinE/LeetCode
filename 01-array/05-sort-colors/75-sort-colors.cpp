#include <vector>

using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int writeIdx = 0;
        int zeroIdx = 0;
        int twoIdx = nums.size() - 1;

        while (writeIdx <= twoIdx)
        {
            if (nums[writeIdx] == 0)
            {
                swap(nums[writeIdx++], nums[zeroIdx++]);
            }
            else if (nums[writeIdx] == 2)
            {
                swap(nums[writeIdx], nums[twoIdx--]);
            }
            else
            {
                ++writeIdx;
            }
        }
    }
};
