#include <vector>
#include <limits>

using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        // search decreasing point
        int minValue = numeric_limits<int>::max();
        for (int idx = 1; idx < nums.size(); ++idx)
        {
            if (nums[idx - 1] > nums[idx])
            {
                minValue = min(minValue, nums[idx]);
            }
        }

        // search sorting start point
        int startPointOfSorting = 0;
        for (; startPointOfSorting < nums.size(); ++startPointOfSorting)
        {
            if (nums[startPointOfSorting] > minValue)
            {
                break;
            }
        }

        // search increasing point
        int maxValue = numeric_limits<int>::min();
        for (int idx = nums.size() - 2; idx >= 0; --idx)
        {
            if (nums[idx + 1] < nums[idx])
            {
                maxValue = max(maxValue, nums[idx]);
            }
        }

        // search sorting end point
        int endPointOfSorting = nums.size() - 1;
        for (; endPointOfSorting >= 0; --endPointOfSorting)
        {
            if (nums[endPointOfSorting] < maxValue)
            {
                break;
            }
        }

        int result = endPointOfSorting - startPointOfSorting + 1;

        return result < 0 ? 0 : result;
    }
};
