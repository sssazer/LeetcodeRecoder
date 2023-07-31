#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        // 先把后半段链表反转，然后依次插入前半段链表中
        int len = 0;
        ListNode* p = head;
        while (p) {
            len++;
            p = p->next;
        }
        int target = 0; // 找到后半段链表的起点位置
        if (len % 2) {
            target = len / 2 + 2;
        }
        else {
            target = len / 2 + 1;
        }
        p = head;
        ListNode* rear = new ListNode(); // 用来保存后半段的起点位置
        for (int i = 2; i < target; i++) {
            p = p->next;
        }
        // 把前半段和后半段分离开
        rear->next = p->next;
        p->next = nullptr;

        // 反转后半段链表(用头插法)
        p = rear->next; // 链尾结点
        ListNode* cur = nullptr; // 当前要被删除并重新头插的结点
        while (p->next) {
            cur = p->next;
            p->next = cur->next;
            cur->next = rear->next;
            rear->next = cur;
        }
        
        // 前后半段链表交替插入
        p = nullptr; // 下一个要插入的结点
        cur = rear->next; // 现在要插入的结点
        ListNode* head_p = head;
        while (cur) {
            p = cur->next;
            cur->next = head_p->next;
            head_p->next = cur;
            cur = p;
            head_p = head_p->next->next;
        }
    }
};

int main() {

	return 0;
}