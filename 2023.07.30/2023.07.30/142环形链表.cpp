#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> set;
        ListNode* p = head;
        while (p) {
            if (set.find(p) != set.end()) {
                return p;
            }
            set.insert(p);
            p = p->next;
        }
        return nullptr;
    }
};

int main() {

	return 0;
}