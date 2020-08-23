/*----------------------------------------------------------------------|
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三	|
个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存|
在唯一答案。															|
																		|
 																		|
																		|
示例：																	|
																		|
输入：nums = [-1,2,1,-4], target = 1									|
输出：2																	|
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。						|
 																		|
																		|
提示：																	|
																		|
3 <= nums.length <= 10^3												|
-10^3 <= nums[i] <= 10^3												|
-10^4 <= target <= 10^4													|
																		|
来源：力扣（LeetCode）													|
链接：https://leetcode-cn.com/problems/3sum-closest						|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。	|
-----------------------------------------------------------------------*/

/*	排序双指针法
*	执行用时：16 ms, 在所有 C++ 提交中击败了76.98%的用户
*	内存消耗：10 MB, 在所有 C++ 提交中击败了86.22%的用户
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
	if (nums.size() < 3 || nums.size() > 1000 || target < -10000 || target>10000)
	{
		return false;
	}

	int length = nums.size();
	sort(nums.begin(), nums.end());

	int result = -1E5;
	for (int a = 0; a < length; a++)
	{
		if (a > 0 && nums[a] == nums[a - 1])
		{
			continue;
		}

		int a_val = target - nums[a];
		for (int b = a + 1; b < length; b++)
		{
			if (b > a + 1 && nums[b] == nums[b - 1])
			{
				continue;
			}

			int c = length - 1;
			while (b < c-1 && nums[b] + nums[c] > a_val)
			{
				c--;
			}
			if (b == c)
			{
				break;
			}
			if (nums[b] + nums[c] == a_val)
			{
				return target;
			}
			if (c == length - 1)
			{
				int sum1 = nums[a] + nums[b] + nums[c];
				int abs1 = (sum1 > target) ? sum1 - target : target - sum1;
				int abs = (result > target) ? result - target : target - result;
				result = (abs > abs1) ? sum1 : result;
			}
			if (c < length - 1)
			{
				int sum1 = nums[a] + nums[b] + nums[c];
				int abs1 = (sum1 > target) ? sum1 - target : target - sum1;
				int abs = (result > target) ? result - target : target - result;
				result = (abs > abs1) ? sum1 : result;

				int sum2 = nums[a] + nums[b] + nums[c + 1];
				int abs2 = (sum2 > target) ? sum2 - target : target - sum2;
				abs = (result > target) ? result - target : target - result;
				result = (abs > abs2) ? sum2 : result;
			}

		}
	}
	return result;
}

int main()
{
	vector<int> nums = { 1,2,4,8,16,32,64,128 };

	int target = 82;

	int result;
	//

	//int length = nums.size();
	//sort(nums.begin(), nums.end());

	//int result = -1E5;
	//for (int a = 0; a < length; a++)
	//{
	//	if (a > 0 && nums[a] == nums[a - 1])
	//	{
	//		continue;
	//	}

	//	int a_val = target - nums[a];
	//	for (int b = a + 1; b < length; b++)
	//	{
	//		if (b > a + 1 && nums[b] == nums[b - 1])
	//		{
	//			continue;
	//		}

	//		int c = length - 1;
	//		while (b < c-1 && nums[b] + nums[c] > a_val)
	//		{
	//			c--;
	//		}
	//		if (b == c)
	//		{
	//			break;
	//		}
	//		if (nums[b] + nums[c] == a_val)
	//		{
	//			return target;
	//		}
	//		if (c == length - 1)
	//		{
	//			int sum1 = nums[a] + nums[b] + nums[c];
	//			int abs1 = (sum1 > target) ? sum1 - target : target - sum1;
	//			int abs = (result > target) ? result - target : target - result;
	//			result = (abs > abs1) ? sum1 : result;
	//		}
	//		if (c < length - 1)
	//		{
	//			int sum1 = nums[a] + nums[b] + nums[c];
	//			int abs1 = (sum1 > target) ? sum1 - target : target - sum1;
	//			int abs = (result > target) ? result - target : target - result;
	//			result = (abs > abs1) ? sum1 : result;

	//			int sum2 = nums[a] + nums[b] + nums[c + 1];
	//			int abs2 = (sum2 > target) ? sum2 - target : target - sum2;
	//			abs = (result > target) ? result - target : target - result;
	//			result = (abs > abs2) ? sum2 : result;
	//		}

	//	}
	//}
	//

	result = threeSumClosest(nums, target);

	cout << result;
}