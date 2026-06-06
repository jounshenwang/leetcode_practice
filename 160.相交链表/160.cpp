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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //哈希表法
        //边界情况，空链表
        if(headA==nullptr||headB==nullptr){
            return nullptr;
        }
        //创建一个哈希表，存储链表A的节点地址
        unordered_set<ListNode*> seen;
        //因为题目要求函数返回结果后，链表必须 保持其原始结构，所以我们不能修改链表A和链表B的结构，因此只能通过遍历链表A，
        //将链表A的节点地址存储在哈希表中，然后遍历链表B，判断链表B的节点地址是否在哈希表中，如果在哈希表中，说明找到了交点，
        //返回该节点地址；如果遍历完链表B都没有找到交点，返回nullptr。
        ListNode* ptra=headA;
        ListNode* ptrb=headB;
        while(ptra!=nullptr){
            seen.insert(ptra);
            ptra=ptra->next;
        }
        while(ptrb!=nullptr){
            if(seen.count(ptrb)){
                return ptrb;
            }
            ptrb=ptrb->next;
        }
        return nullptr;
    }
};