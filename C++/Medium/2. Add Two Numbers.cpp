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
private:
    void carryToLastNode(ListNode* node) {
        // 避免傳入空指標，所以先傳入不為空的ListNode
        if (node->next == nullptr) {
            node->next = new ListNode(0);
        }
        // 處理後再指到下個node
        node = node->next;
        const int carry = 1;
        const int ct = node->val + carry;
        node->val = ct % 10;
        // 需要進位就繼續call function
        if (ct == 10) {
            carryToLastNode(node);
        }
        return;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 以l1為主
        ListNode* first = l1;
        // 紀錄總和與進位
        int ct = 0;
        int carry = 0;
        while(true) {
            ct = l1->val + l2->val + carry;
            if (ct >= 10) {
                ct -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            l1->val = ct;
            if (l1->next == nullptr) {
                // l1為空就把l2接上來並判斷是否繼續進位
                l1->next = l2->next;
                if (carry == 1) {
                    carryToLastNode(l1);
                }
                break;
            }
            else if (l2->next == nullptr) {
                // l2為空就判斷是否繼續進位
                if (carry == 1) {
                    carryToLastNode(l1);
                }
                break;
            }
            else {
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        // 回傳Linklist開頭
        return first;
    }
};
