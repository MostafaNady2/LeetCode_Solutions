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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(), nums.end());
        ListNode* h = head;
        ListNode* newHead = nullptr;
        ListNode* last = newHead;
        while (h != nullptr) {
            int idx =
                lower_bound(nums.begin(), nums.end(), h->val) - nums.begin();
            if (idx >= 0 && idx < nums.size() && nums[idx] == h->val) {
                h = h->next;
                continue;
            }
            if (newHead == nullptr) {
                newHead = new ListNode(h->val);
                last = newHead;
            } else {
                ListNode* node = new ListNode(h->val);
                last->next = node;
                last = node;
            }
            h = h->next;
        }
        return newHead;
    }
};