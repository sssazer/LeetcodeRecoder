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
        // �ȰѺ�������ת��Ȼ�����β���ǰ���������
        int len = 0;
        ListNode* p = head;
        while (p) {
            len++;
            p = p->next;
        }
        int target = 0; // �ҵ�������������λ��
        if (len % 2) {
            target = len / 2 + 2;
        }
        else {
            target = len / 2 + 1;
        }
        p = head;
        ListNode* rear = new ListNode(); // ����������ε����λ��
        for (int i = 2; i < target; i++) {
            p = p->next;
        }
        // ��ǰ��κͺ��η��뿪
        rear->next = p->next;
        p->next = nullptr;

        // ��ת��������(��ͷ�巨)
        p = rear->next; // ��β���
        ListNode* cur = nullptr; // ��ǰҪ��ɾ��������ͷ��Ľ��
        while (p->next) {
            cur = p->next;
            p->next = cur->next;
            cur->next = rear->next;
            rear->next = cur;
        }
        
        // ǰ�������������
        p = nullptr; // ��һ��Ҫ����Ľ��
        cur = rear->next; // ����Ҫ����Ľ��
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