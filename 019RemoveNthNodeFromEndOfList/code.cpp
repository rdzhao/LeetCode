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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* l1 = NULL;
		ListNode* l2 = NULL;
		l1 = head;

		int count = 0;
		bool flag = false;
		do {
			if (flag)
				l2 = l2->next;
			count++;

			if (count == n + 1)
			{
				l2 = head;
				flag = true;
			}

			l1 = l1->next;
		} while (l1 != NULL);

		if (l2 != NULL)
		{
			ListNode* after = l2->next->next;
			delete l2->next;
			l2->next = after;

			return head;
		}
		else
		{
			ListNode* newHead = head->next;
			delete head;
			return newHead;
		}

	}
};