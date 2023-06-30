#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* nextPtr) :val(x), next(nextPtr){}
};

class Solution1 { // 错误的解答
public:
	ListNode* removeZeroSumSublists(ListNode* head) {
		// 将链表转化为数组
		vector<int> list;
		while (head) {
			list.push_back(head->val);
			head = head->next;
		}
		for (int i = 0; i < list.size(); i++) {
			if (list[i] == 0) { // 如果某个节点值为0直接删除
				list.erase(list.begin() + i);
				i--;
				continue;
			}
			if (list[i] < 0) {
				// 往前找能让总和为0的节点
				int target = list[i];
				int pre = i - 1;
				while (pre >= 0 && target < 0) {
					target += list[pre--];
				}
				if (target == 0) {
					list.erase(list.begin() + pre + 1, list.begin() + i + 1);
					i = pre;
					continue;
				}
				// 往后找能让总和为0的节点
				int last = i + 1;
				target = list[i];
				while (last < list.size() && target < 0) {
					target += list[last++];
				}
				if (target == 0) {
					list.erase(list.begin() + i, list.begin() + last);
					i--;
				}
			}
		}
		if (list.size() == 0) {
			return nullptr;
		}
		ListNode* res = new ListNode(list[0]);
		ListNode* p = res;
		for (int i = 1; i < list.size(); i++) {
			p->next = new ListNode(list[i]);
			p = p->next;
		}
		return res;

	}
};

class Solution { // 前缀和 + 哈希表
public:
	ListNode* removeZeroSumSublists(ListNode* head) {
		// 从head开始计算每个节点的前缀和
		// 如果有相同的前缀和说明两个节点之间的元素和为0，直接连这两个节点把中间的全部删掉
		unordered_map<int, ListNode*> sums; // int是从head到ListNode*中的所有节点的值的和
		ListNode* preHead = new ListNode(0, head);
		ListNode* p = head;
		ListNode* prev = preHead;
		int sum = 0;
		sums[0] = preHead;
		while (p) {
			if (p->val == 0) { // 如果某个节点为0直接删除
				prev->next = p->next;
				p = p->next;
				continue;
			}
			sum += p->val;
			if (sums.find(sum) != sums.end()) { // 如果这个和已经出现过，删除中间和为0的节点并从头开始重新遍历
				sums.find(sum)->second->next = p->next;
				sums.clear();
				sums[0] = preHead;
				sum = 0;
				prev = preHead;
				p = preHead->next;;
				continue;
			}
			else {
				sums[sum] = p;
			}
			prev = p;
			p = p->next;
		}
		return preHead->next;
	}
};

int main() {

	return 0;
}