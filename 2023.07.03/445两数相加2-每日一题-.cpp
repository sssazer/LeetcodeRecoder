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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2;
        while(l1){
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2){
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        int jinwei = 0;
        ListNode* result = new ListNode(0);
        if(v1.size() > v2.size()){
            int i, j;
            for(i = v1.size() - 1, j = v2.size() - 1; i >= 0 && j >= 0; i--, j--){
                v1[i] = v1[i] + v2[j] + jinwei;
                if(v1[i] >= 10){
                    v1[i] %= 10;
                    jinwei = 1;
                }
                else{
                    jinwei = 0;
                }
            }
            for(; i >= 0; i--){
                v1[i] += jinwei;
                if(v1[i] >= 10){
                    v1[i] %= 10;
                    jinwei = 1;
                }
                else{
                    jinwei = 0;
                }
            }
            ListNode* p = result;
            if(jinwei){
                p->next = new ListNode(1, nullptr);
                p = p->next;
            }
            for(int i = 0; i < v1.size(); i++){
                p->next = new ListNode(v1[i], nullptr);
                p = p->next;
            }
        }else{
            int i, j;
            for(i = v1.size() - 1, j = v2.size() - 1; i >= 0 && j >= 0; i--, j--){
                v2[j] = v1[i] + v2[j] + jinwei;
                if(v2[j] >= 10){
                    v2[j] %= 10;
                    jinwei = 1;
                }
                else{
                    jinwei = 0;
                }
            }
            for(; j >= 0; j--){
                v2[j] += jinwei;
                if(v2[j] >= 10){
                    v2[j] %= 10;
                    jinwei = 1;
                }
                else{
                    jinwei = 0;
                }
            }
            ListNode* p = result;
            if(jinwei){
                p->next = new ListNode(1, nullptr);
                p = p->next;
            }
            for(int i = 0; i < v2.size(); i++){
                p->next = new ListNode(v2[i], nullptr);
                p = p->next;
            }           
        }
        return result->next;
    }
};

int main(){

    return 0;
}