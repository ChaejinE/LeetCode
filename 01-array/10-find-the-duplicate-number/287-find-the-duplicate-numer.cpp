#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int result;
        for (auto e : nums)
        {
            if (nums[abs(e)] < 0)
            {
                result = e; // - 면 이미 marking 된 중복..
                break;
            }
            else
            {
                nums[abs(e)] *= -1; // 해당 int 값을 index 정보로 보고, 존재했음을 marking
            }
        }

        return result < 0 ? result * -1 : result;
    }
};
