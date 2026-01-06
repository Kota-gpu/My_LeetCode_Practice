
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

typedef struct ListNode NODE;

NODE *createNode(int val){
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode-> val = val;
    newNode-> next = NULL;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    NODE *tail = NULL;
    NODE *head = NULL;
    int carry = 0;
    int sum = 0;

    while(l1 != NULL || l2 != NULL || (carry > 0)){
        
        int v1 = (l1 != NULL)? l1->val : 0;
        int v2 = (l2 != NULL)? l2->val : 0;

        sum = (v1 + v2 + carry) % 10;
        carry = (v1 + v2 + carry) / 10;
        NODE *newNode = createNode(sum);

        if(head != NULL) {
            tail->next = newNode;
            tail = tail-> next;        
        }
        else {
            tail = newNode;
            head = newNode;
        }

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    
    return head;
}