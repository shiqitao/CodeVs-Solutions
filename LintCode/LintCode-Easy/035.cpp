/**
* Definition of ListNode
*
* class ListNode {
* public:
*     int val;
*     ListNode *next;
*
*     ListNode(int val) {
*         this->val = val;
*         this->next = NULL;
*     }
* }
*/


class Solution {
public:
	/*
	* @param head: n
	* @return: The new head of reversed linked list.
	*/
	ListNode * reverse(ListNode * head) {
		// write your code here
		ListNode *pre = NULL;
		ListNode *temp;
		while (head != NULL)
		{
			temp = head->next;
			head->next = pre;
			pre = head;
			head = temp;
		}
		return pre;
	}
};