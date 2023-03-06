## Reverse a LL :

ListNode* reverse(ListNode* head)
{
    ListNode* newhead = NULL;
    while(head != NULL)
    {
        ListNode* next = head->next;
        head->next = newhead;

        newhead = head;
        head = next;
    }
    return newhead;
}

// ******************************************************************

## delete nth node from end of the LL.
optimesed code : o(n)

ListNode* remove(ListNode* head)
{
    ListNode* start = new ListNode();  
    start->next = head;     

    ListNode* fast = start;
    ListNode* slow = slow;

    for(int i=1;i<=n;++i)
    {
        fast = fast->next;
    }

    for(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* node = slow->next;
    slow->next = slow->next->next;
    delete(node);
}

//-----------------------------------------------------------------

ListNode* remove(ListNode* head,int n)
{
    ListNode* temp = head;
    int len = 0;
    while(temp != NULL)
    {
        ++len;
        temp = temp->next;
    }

    if(len == n) 
    {
        ListNode* todelete = head;
        head = head->next;
        delete(todelete);
        return head;
    }

    int x = len-n;
    ListNode* curr = head;
    int cnt = 1;
    while(cnt != x)
    {
        ++cnt;
        curr = curr->next;
    }

    ListNode *todelete = curr->next;
    curr->next = curr->next->next;
    delete(todelete);
    return head;  
}


// ******************************************************************

## Middle of the LL : 

ListNode* middle(ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// ******************************************************************

## merge two sorted LL :

ListNode* merge(ListNode* list1,ListNode* list2)
{
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    if(list1->val > list2->val) swap(list1,list2);
    ListNode* res = list1;

    while(list1!=NULL && list2!=NULL)
    {
        ListNode* temp = NULL;
        while(list1 != NULL && list1->val <= list2->val)
        {
            temp = list1;
            list1 = list1->next;
        }
        temp->next = list2;
        swap(list1,list2);
    }
    return res;
}

tc : o(n1 + n2)
sc : o(1) no extra space...

brute force : make a new ll ..
so tc is same..
but sc is 0(n1+n2) for new ll...
// ******************************************************************

## Add two numbers given as a LL : 

ListNode* add(ListNode* l1,ListNode* l2)
{
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    int carry = 0;
    ListNode* dumy = new ListNode();
    ListNode* temp = dumy;

    while(l1||l2||carry)
    {
        int sum = 0;
        if(l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2) 
        {
            sum += l2->val;
            l2 = l2->next;
        }

        sum+=carry;
        ListNode* node = new ListNode(sum%10);
        carry = sum/10;
        temp->next = node;
        temp = temp->next; 
    }
    return dumy->next;
}

// ******************************************************************

## Delete a node in LL :

ListNode* func(ListNode* node)
{
    swap(node->val,node->next->val);
    ListNode* todelete = node->next;
    node->next = node->next->next;
    delete(todelete);
    return;
}

// ******************************************************************

## intersection node of LL :

ListNode* func(ListNode* l1,ListNode* l2)
{
    if(l1==NULL||l2==NULL) return NULL;

    ListNode* t1 = l1;
    ListNode* t2 = l2;

    while(l1 != l2)
    {
        t1 = t1==NULL ? t2 : t1->next;
        t2 = t2==NULL ? t1 : t2->next;
    }
    return t1;
}

// ******************************************************************

ListNode* cycle(ListNode* head)
{
    if(head==NULL) return NULL;

    ListNode* fast = head;
    ListNOde* slow = head;

    while(fast != slow&&fast&&fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return fast->next;
}

// ******************************************************************
## Reverse a LL :

ListNode* reverse(ListNode* head)
{
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* nxt;

    while(curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nxt;
    }
    return prev;
}

// ******************************************************************

## is LL palindrome : 

bool palin(ListNode* head)
{
    if(head==NULL || head->next==NULL) return true;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* t2 = slow->next;
    
    // reverse LL : 
    ListNode* prev = slow;
    ListNode* curr = slow->next;
    ListNode* nxt;

    while(curr!=NULL)
    {
        nxt = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nxt;
    }

    ListNode* t1 = head; 

    while(t2!=NULL)
    {
        if(t1->val != t2->val) return false;
        t1 = t1->next;
        t2 = t2->next;
    }
    return true;
}

// ******************************************************************

## Starting point of the cycle : 
// s == step

s1 = first find the intersection of slow and fast pointer..
s2 = move temp(head) and slow pointer until they collide..

ListNode* point(ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast!=slow&&fast&&fast->next)
    {
        if(fast==NULL||fast->next==NULL) return NULL;
        fast = fast->next->next;
        slow = slow->next;
    } 

    ListNode* t1 = head;

    while(t1!=slow)
    {
        t1=t1->next;
        slow=slow->next;
    }

    return slow;
}

// ******************************************************************

## flattening of a LL :

// s1 = apply recursion ...
// s2 = try merge of 2 LL into 1 LL ...

ListNode* merge(ListNode* a,ListNode* b)
{
    ListNode* temp = new ListNode(0);
    ListNode* res = temp;

    while(a!=NULL && b!=NULL)
    {
        if(a->val < b->val)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if(a) temp->bottom = a;
    else temp->bottom = b;

    return res->bottom;
}

ListNode* flatten(ListNode* root)
{
    if(root==NULL||root->next==NULL) return root;

    root->next = flatten(root->next);

    root = merge(root,root->next);

    return root;
}

// ******************************************************************

## Rotate a LL :
// s1 = first find len of LL..
// s2 = then last->next = head...ie form cycle...
// s3 = iterate till n-k node from head...
// s4 = form new node and the new node which points to null...

ListNode* rotate(ListNode* head,int k)
{
    if(head==NULL||head->next==NULL||k==0) return head;

    int len = 1;
    ListNode* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
        ++len;
    }

    temp->next = head;
    k = k%len;

    ListNode* t1 = head;
    for(int i=1;i<len-k;++i)
    {
        t1 = t1->next;
    }
    head = t1->next;
    t1->next = NULL;

    return head;
}

// ******************************************************************

More to do in LL....

add a node at start ,end ,middle of LL : 
reverse LL in recursive way...
sort LL using bubble sort,,merge sort...





