// 47.PermutationsII.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
	void permute_recusion(vector<int>& nums, int deep, int length, vector<int>& result_item, vector< vector<int>>& result) {
		// 递归到末尾，则停止
		if (deep > length) {
			// 判断结果列表中是否已有当前排列，去重
			vector < vector<int>>::iterator iVector = find(result.begin(), result.end(), result_item);
			if (iVector != result.end()) {
			}
			else {
				result.push_back(result_item);
			}
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

			permute_recusion(nums_, deep + 1, length, result_item, result);
		}
	}

	// 循环 实现
	void permute_loop(vector<int>& nums) {

	}
};

int main()
{
	vector<int> nums = { 1,2,1 };

	Solution solution;
	solution.permute(nums);
	cin;
}
