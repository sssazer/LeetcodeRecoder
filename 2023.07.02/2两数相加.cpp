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
	ListNode *p1 = l1,*p2 = l2;
	bool jinwei = 0;
	p1->val = p1->val + p2->val + jinwei;
	if(p1->val >= 10){
		jinwei = 1;
		p1->val %= 10;
	}
	while(p1->next && p2->next){
		p1 = p1->next;
		p2 = p2->next;
		p1->val = p1->val + p2->val + jinwei;
		if(p1->val >= 10){
			jinwei = 1;
			p1->val %= 10;
		}
		else{
			jinwei = 0;
		}
	}
	while(p2->next){ 
		p2 = p2->next;
		int data = p2->val + jinwei;
		if(data >= 10){
			data %= 10;
			jinwei = 1;
		}	
		else{
			jinwei = 0;
		}
		p1->next = new ListNode(data);
		p1 = p1->next;
	}
	while(p1->next){
		p1 = p1->next;
		p1->val =  p1->val + jinwei;
		if(p1->val >= 10){
			p1->val %= 10;
			jinwei = 1;
		}	
		else{
			jinwei = 0;
		}
	}	
	if(jinwei){
		p1->next = new ListNode(1);
	}
	return l1;
    }
};

int main(){

	return 0;
}
