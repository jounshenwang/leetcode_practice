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
    ListNode* reverseList(ListNode* head) {
        //迭代法解反转链表，本质上就是链表类型的双指针
        //假设原链表为1->2->3->空
        //反转以后就要变成3->2->1->空
        //单向链表每个节点有两个成员，一个是值，一个是指向下一个节点的指针next
        //实际上要做的是将每一个节点的next指针改为指向前一个节点
        ListNode* prev=nullptr;//这个指针是反转以后节点将要指向的节点，由于链表最后的指向一定是空，所以反转以后的原一号节点要指向空，后续随循环更新
        ListNode* cur=head;//一开始这个指针指向1，也就是指向要反转的节点
        //和双指针一样也用个while，只是条件变一下，在cur不为空指针的时候循环（如果cur为空了说明以及完成整个链表的反转）
        while(cur){ 
        //创建一个临时中间变量暂存后继节点，->用于访问结构体/类成员，这里就是把cur节点的指向下一个节点的指针暂存在next
            ListNode* next = cur->next; //cur->next为2，即next也为2
        //先前已经把cur节点的next暂存了，现在就可以改变这个值了，令这个值为prev，也就是nullptr，这样就完成了第一个片段的反转，整个链表变成两部分，即1->空，2->3->空
            cur->next=prev;
        //然后prev和cur都前进一位，为下一个循环做准备
            prev = cur;//更新将prev指向1，意思也就是接下来要让2节点指向1
            cur = next;//更新将cur指向2，意思是接下来要进行反转操作的是2
        }
        return prev;
    }
};