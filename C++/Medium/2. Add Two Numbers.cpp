/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 創造新的Linklist，並記錄第一個節點
        ListNode* nl = new ListNode(0);
        ListNode* first = nl;
        // 紀錄總和與進位
        int ct = 0;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                ct = l2->val + carry;
                l2 = l2->next;
            }
            else if (l2 == nullptr) {
                ct = l1->val + carry;
                l1 = l1->next;
            }
            else {
                ct = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            nl->next = new ListNode(ct % 10);
            nl = nl->next;
            if (ct >= 10) {
                carry = 1;
            }
            else {
                carry = 0;
            }
        }
        // 檢查是否要進位到最後一個節點
        if(carry == 1) {
            nl->next = new ListNode(1);
        }
        // 回傳Linklist開頭
        return first->next;
    }
};