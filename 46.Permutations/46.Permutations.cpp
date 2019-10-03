// 46.Permutations.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

提交记录：
Runtime：16ms, 85.52%
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	vector<int> temp;

public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> result_item;
		vector< vector<int>> result;
		permute_recusion(nums, 1, nums.size(), result_item, result);
		for (int i = 0; i < result.size(); i++) {
			for (int j = 0; j < result.at(i).size(); j++) {
				cout << result.at(i).at(j) << " ";
			}
			cout << endl;
		}
		return result;
	}

	// 递归函数
	void permute_recusion(vector<int>& nums, int deep, int length, vector<int>& result_item, vector< vector<int>> &result) {
		// 递归到末尾，则停止
		if (deep > length) {
			result.push_back(result_item);
			temp.assign(result_item.begin(), result_item.end());
			result_item.clear();
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (deep == 1) {
				result_item.clear();
			}
			else if (result_item.size() == 0) {
				/*for (int j = 0; j < deep-1; j++) {
					result_item.push_back(temp.at(j));
				}*/
				result_item.assign(temp.begin(), temp.begin() + deep - 1);
			}
			vector<int> nums_;
			nums_.assign(nums.begin(), nums.end());
			result_item.push_back(nums.at(i));
			vector<int>::iterator iVector = find(nums_.begin(), nums_.end(), nums_.at(i));
			if (iVector != nums_.end())
			{
				nums_.erase(iVector);
			}

			// 清理空间
			// vector<int>().swap(nums);

			permute_recusion(nums_, deep+1, length, result_item, result);
		}
	}

	// 循环 实现
	void permute_loop(vector<int>& nums) {

	}
};

int jc(int n) {
	if (n == 0) {
		return 1;
	}
	return n * jc(n - 1);
}

int main()
{
	vector<int> nums = { 1,2, 3,4,5,6,7,8};

	int counts = jc(nums.size());
	cout << "共有排列数：" << counts << endl;

	Solution solution;
	solution.permute(nums);
	cin;
}
