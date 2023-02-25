#include <vector>
#include <limits>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int startIdx = 0;
        int sum = 0;
        int minLength = numeric_limits<int>::max();

        for (int endIdx = 0; endIdx < nums.size(); ++endIdx)
        {
            sum += nums[endIdx];

            while (sum >= target)
            {
                minLength = min(minLength, endIdx - startIdx + 1);
                sum -= nums[startIdx++];
            }
        }

        return (minLength != numeric_limits<int>::max()) ? minLength : 0;
    }
};
