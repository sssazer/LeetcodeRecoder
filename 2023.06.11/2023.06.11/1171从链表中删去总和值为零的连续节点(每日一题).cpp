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

class Solution1 { // ����Ľ��
public:
	ListNode* removeZeroSumSublists(ListNode* head) {
		// ������ת��Ϊ����
		vector<int> list;
		while (head) {
			list.push_back(head->val);
			head = head->next;
		}
		for (int i = 0; i < list.size(); i++) {
			if (list[i] == 0) { // ���ĳ���ڵ�ֵΪ0ֱ��ɾ��
				list.erase(list.begin() + i);
				i--;
				continue;
			}
			if (list[i] < 0) {
				// ��ǰ�������ܺ�Ϊ0�Ľڵ�
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
				// �����������ܺ�Ϊ0�Ľڵ�
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

class Solution { // ǰ׺�� + ��ϣ��
public:
	ListNode* removeZeroSumSublists(ListNode* head) {
		// ��head��ʼ����ÿ���ڵ��ǰ׺��
		// �������ͬ��ǰ׺��˵�������ڵ�֮���Ԫ�غ�Ϊ0��ֱ�����������ڵ���м��ȫ��ɾ��
		unordered_map<int, ListNode*> sums; // int�Ǵ�head��ListNode*�е����нڵ��ֵ�ĺ�
		ListNode* preHead = new ListNode(0, head);
		ListNode* p = head;
		ListNode* prev = preHead;
		int sum = 0;
		sums[0] = preHead;
		while (p) {
			if (p->val == 0) { // ���ĳ���ڵ�Ϊ0ֱ��ɾ��
				prev->next = p->next;
				p = p->next;
				continue;
			}
			sum += p->val;
			if (sums.find(sum) != sums.end()) { // ���������Ѿ����ֹ���ɾ���м��Ϊ0�Ľڵ㲢��ͷ��ʼ���±���
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