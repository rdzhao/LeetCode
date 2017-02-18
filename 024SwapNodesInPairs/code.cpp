/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* fir = NULL;
		ListNode* sec = NULL;
		ListNode* thi = NULL;
		ListNode* fou = NULL;

		if (!head == NULL && !head->next == NULL)
		{
			sec = head;
			thi = head->next;
			fou = head->next->next;

			head = thi;
			thi->next = sec;
			sec->next = fou;
		}

		while (fou != NULL && fou->next != NULL)
		{
			fir = sec;
			sec = fou;
			thi = fou->next;
			fou = fou->next->next;

			fir->next = thi;
			thi->next = sec;
			sec->next = fou;

		}

		return head;
	}
};