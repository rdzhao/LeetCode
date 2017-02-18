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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* newNode = new ListNode(0);
		ListNode* preNode = new ListNode(0);
		ListNode* node = new ListNode(0);

		bool firstEnter = true;
		int next = 0;
		while (l1 != NULL || l2 != NULL)
		{
			newNode = new ListNode(0);
			if (l1 != NULL && l2 != NULL)
			{
				newNode->val = (l1->val + l2->val + next) % 10;
				next = (l1->val + l2->val + next) / 10;
				l1 = l1->next;
				l2 = l2->next;
			}
			else if (l1 == NULL && l2 != NULL)
			{
				newNode->val = (l2->val + next) % 10;
				next = (l2->val + next) / 10;
				l2 = l2->next;
			}
			else
			{
				newNode->val = (l1->val + next) % 10;
				next = (l1->val + next) / 10;
				l1 = l1->next;
			}

			if (firstEnter)
			{
				node = newNode;
				preNode = newNode;
				firstEnter = false;
			}
			else
			{
				preNode->next = newNode;
				preNode = newNode;

			}
		}
		if (next == 1)
		{
			newNode = new ListNode(1);
			preNode->next = newNode;
		}

		return node;
	}
};