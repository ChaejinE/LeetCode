#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;
        while (row < m && col >= 0)
        {
            int pivot = matrix[row][col];

            if (pivot == target)
            {
                return true;
            }
            else if (pivot > target)
            {
                for (int c = 0; c < n; ++c)
                {
                    if (matrix[row][c] == target)
                    {
                        return true;
                    }
                }
            }
            else
            {
                for (int r = 0; r < m; ++r)
                {
                    if (matrix[r][col] == target)
                    {
                        return true;
                    }
                }
            }

            ++row;
            --col;
        }

        return false;
    }
};
