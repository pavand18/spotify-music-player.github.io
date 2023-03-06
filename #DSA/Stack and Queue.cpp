#### 2. Implementing queue (using array) : ####


/*
    Time Complexity : O(q)
    Space Complexity : O(q)

    Where q is the number of queries.
*/

class Queue {
public:
    int qfront, rear, size, queueSize;
    int q[100010];
    Queue() {

        // Intialise the queue with 0 elements.
        rear = 0;
        qfront = 0;
        size = 0;
        queueSize = 100010;

    }

    // Function to check if the queue is empty.
    bool isEmpty() {
        if (qfront == rear) {
            return true;
        }
        return false;
    }

    void enqueue(int data) {

        // Push the current element in the queue.
        q[rear] = data;
        rear = rear + 1;

        // Increase the value of size.
        size++;
    }

    int dequeue() {

        // Check if the queue is empty.
        if (isEmpty()) {
            return -1;
        }

        int ans = q[qfront];
        qfront++;
        size--;
        if (qfront == rear) {
            qfront = 0;
            rear = 0;
        }
        return ans;
    }

    int front() {

        // Check if the queue is empty.
        if (isEmpty()) {
            return -1;
        }

        // Return the element at front.
        return q[qfront];
    }
};


// ***************************************************************************************************

#### implementing stack (2 queue) : #### 

#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int> q1,q2;
    
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(q1.size()==0) return true;
        return false;
    }

    void push(int element) {
        // Implement the push() function.
        q2.push(element);
        int x = q1.size();
        while(x--)
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        swap(q1,q2);
    }

    int pop() {
        // Implement the pop() function.
        if(q1.size()==0) return -1;
        int xx = q1.front();
        q1.pop();
        return xx;
    }

    int top() {
        // Implement the top() function.
        if(q1.size()==0) return -1;
        return q1.front();
    }
};

// ***************************************************************************************************

#### implementing stack (single queue) : #### 


#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
   queue<int> q;
    
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(q.size() == 0) return true;
        return false;
    }

    void push(int element) {
        // Implement the push() function.
        q.push(element);
        
        for(int i=0;i<q.size()-1;++i)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        if(q.size()==0) return -1;
        int xx = q.front();
        q.pop();
        return xx;
    }

    int top() {
        // Implement the top() function.
        if(q.size()==0) return -1;
        return q.front();
    }
};


// ***************************************************************************************************

>>>>> solve it dynamically <<<<<

// ***************************************************************************************************

>>>>> implementing queue (using stack) <<<<<

#include <stack> 
class Queue {
    // Define the data members(if any) here.
    
    public:
    
    stack<int> st1,st2;
    
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        
        st1.push(val);
        
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(st1.size()==0) return -1;
        int xx = st1.top();
        st1.pop();
        return xx;
    }

    int peek() {
        // Implement the peek() function here.
        if(st1.size()==0) return -1;
        return st1.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        if(st1.size()==0) return true;
        return false;
    }
};


// ***************************************************************************************************

#include <bits/stdc++.h>
using namespace std;

struct Qnode{
    int data;
    Qnode* next;

    // parameterised constructor..
    Qnode(int d)
    {
        data = d;
        next = NULL;
    }
};

struct Queue{
    Qnode *front, *rear;

    Queue() 
    {
        front = rear = NULL;
    } 

    void enQueue(int x)
    {

    }

    void deQueue()
    {

    }

};

// ***************************************************************************************************

// >>>>> Q. valid parenthesis <<<<<

bool isValidParenthesis(string expression)
{
    // Write your code here.
    string s = expression;
    stack<int> st;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='['||s[i]=='('||s[i]=='{')
            st.push(s[i]);
        else
        {
            // if size == 0 ...then st.top() cant be used..
            // if used it will give runtime error..
            if(st.size()==0) return false;
            else if(s[i]==')' && st.top()=='(') st.pop(); 
            else if(s[i]==']' && st.top()=='[') st.pop();
            else if(s[i]=='}' && st.top()=='{') st.pop();
            else return false;
        }
    }
    
    if(st.size()==0) return true;
    return false;
}

// ***************************************************************************************************

// >>>>> Q2. Next Greater Element <<<<<

// Brute Force : 

#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> ans;
    for(int i=0;i<n;++i){
        int z=0;
        for(int j=i+1;j<n;++j){
            if(arr[i]<arr[j])
            {
                z=1;
                ans.push_back(arr[j]);
                break;
            }
        } 
        if(z==0) ans.push_back(-1);
    }
    return ans;
}

// using stack : 

#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int> st;
    vector<int> ans;
    
    for(int i=n-1;i>=0;--i)
    {
        while(st.size()!=0&&st.top()<=arr[i])
        {
            st.pop();
        }
        if(st.size()!=0) ans.push_back(st.top());
        else ans.push_back(-1);
        st.push(arr[i]);
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}

// ***************************************************************************************************

// >>>>> Q.4 LRU CACHE <<<<<

#include <bits/stdc++.h> 
class LFUCache
{
public:
    
//  double linked list....
    class node{
        public:
        int key,val;
        node *next,*prev;
        
        node(int k,int v){
            key=k;
            val=v;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int size;
    unordered_map<int,node*> m;
    
    LFUCache(int capacity)
    {
        // Write your code here.
        size = capacity;
        head->next = tail;
        tail->prev = head;
    } 
    
//     newnode is always added next to the head...
    void addnode(node* newnode){
        node* temp = head->next;
        head->next = newnode;
        temp->prev = newnode;
        newnode->next = temp;
        newnode->prev = head;
    } 
    
    void deletenode(node* newdelnode){
        newdelnode->prev->next = newdelnode->next;
        newdelnode->next->prev = newdelnode->prev;
    }

    int get(int key)
    {
        // Write your code here.
        if(m.find(key) != m.end())
        {
            node* resnode = m[key];
            int res = resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here.
        if(m.find(key) != m.end())
        {
            node*existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        if(m.size() == size)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key] = head->next;
    }
};

// ***************************************************************************************************

// >>>>> Q.4 sliding window <<<<<<

// brute force : 

#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    int n = nums.size();
    vector<int> ans;
    for(int i=0;i<n-k+1;++i){
        int xx = INT_MIN;
        for(int j=i;j<i+k;++j){
            xx = max(xx,nums[j]);
        }
        ans.push_back(xx);
    } 
    return ans;
}

// optimal solution :

#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    vector<int> ans;
    deque<int> dq;
    int n = nums.size();
    
    for(int i=0;i<n;++i)
    {
        if(!dq.empty() && dq.front()==i-k) dq.pop_front();
        
        while(!dq.empty() && nums[dq.back()]<= nums[i]) dq.pop_back();
        
//         index.. is push from the back...
        dq.push_back(i);
        
//         max. element of window is at front of dq.
        if(i>=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}

// ***************************************************************************************************

// >>>>> Q.5. MIN stack implement <<<<<

#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	public:
		
        stack<pair<int,int>> st;
        int x;
		// Constructor
		minStack() 
		{ 
			// Write your code here.
            x = INT_MAX;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            if(st.empty()) st.push({num,num});
            else
            {
                x = min(st.top().second,num);
                st.push({num,x});
            }  
        }
		
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
            if(!st.empty())
            {
                auto it = st.top();
                st.pop();
                return it.first;
            }
//             st.pop();
            return -1;
            
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            if(!st.empty())
            {
                auto it = st.top();
                return it.first;
            }
            return -1;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(!st.empty())
            {
                auto it = st.top();
                return it.second;
            }
            return -1;
		}
};

// ***************************************************************************************************





