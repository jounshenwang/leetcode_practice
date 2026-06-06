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

//一次遍历
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //边界情况，空链表或者只有一个节点
        if(head==nullptr||head->next==nullptr) {
            return head;
        }
        //创建一个指向头节点的节点，用于遍历并且更改以后不影响头节点本身的返回
        ListNode* to=head;
        while(to->next!=nullptr){
                 if(to->val==to->next->val){//相邻节点值相等，跳到下下的节点
                         to->next=to->next->next;
                     }
                 else{//如果不相等，正常更新
                     to=to->next;
                 }
        }
        return head;//head后面的节点虽然都修改过了，但是head这个头节点本身并未改变什么
    }
};