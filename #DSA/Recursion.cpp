L4.Problems on Functional Recursion ...

// >>>>>> 1.Reverse an array <<<<<<<

#include <bits/stdc++.h>
using namespace std;
 
void func(int i,int j,vector<int>& a)
{
	if(i>=j) return;
	swap(a[i],a[j]);
	func(i+1,j-1,a);
}

//>>>>>>>>>>>>>>>>###################<<<<<<<<<<<<<<<<<<<
int main(){
	#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
//>>>>>>>>>>>>>>>>###################<<<<<<<<<<<<<<<<<<<
int n=7;
vector<int> a(n);
for(int i=0;i<n;++i) cin>>a[i];

func(0,n-1,a);

for(auto it:a) cout<<it<<' '; cout<<endl;
}

//******************************************************
// >>>>>> 2.check if string is palindrome <<<<<<<

#include <bits/stdc++.h>
using namespace std;
 
bool func(int i,int j,string s)
{
	if(i>=j) return true;
	if(s[i]!=s[j]) return false;
	
	if(!func(i+1,j-1,s)) return false;
	return true;  
}
 
//>>>>>>>>>>>>>>>>###################<<<<<<<<<<<<<<<<<<<
int main(){
	#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
//>>>>>>>>>>>>>>>>###################<<<<<<<<<<<<<<<<<<<
int n;		cin>>n;
string s;
cin>>s;

cout<<func(0,n-1,s);
}

// *****************************************************************************************************************

L5.Multiple Recursion calls ...

// >>>>>> fibonacci <<<<<<<

#include <bits/stdc++.h>
using namespace std;
 
int fibo(int n)
{
	// if(n==0) return 0;
	// if(n==1) return 1;
	if(n==0||n==1) return n;

	return fibo(n-1) + fibo(n-2);
}
 
//>>>>>>>>>>>>>>>>###################<<<<<<<<<<<<<<<<<<<
int main(){
	#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
//>>>>>>>>>>>>>>>>###################<<<<<<<<<<<<<<<<<<<
int n;
cin>>n;
cout<<fibo(5)<<endl;
}

// *****************************************************************************************************************

L6.Recursion on Subsequences ...

*subsequence is a continuous or non-continuous 
sequence(not sub array) of an array.
which follows order...

// >>>>>> print all subsequence of array <<<<<<<

#include <bits/stdc++.h>
using namespace std;
 
void func(int i,int n,vector<int> a,vector<int>& v,
	vector<vector<int>>& ans)
{
	if(i>=n) 
	{
		ans.push_back(v);
		return;
	}

	v.push_back(a[i]);
	func(i+1,n,a,v,ans);
	v.pop_back();

	func(i+1,n,a,v,ans);
}
 
//>>>>>>>>>>>>>>>>###################<<<<<<<<<<<<<<<<<<<
int main(){
	#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
//>>>>>>>>>>>>>>>>###################<<<<<<<<<<<<<<<<<<<
int n;		cin>>n;
vector<int> a(n);
for(int i=0;i<n;++i) cin>>a[i];

vector<vector<int>> ans;
vector<int> v;
func(0,n,a,v,ans);

for(auto x:ans)
{
	for(auto it:x) cout<<it<<" ";
		cout<<endl;
}}

// *****************************************************************************************************************

L7.All kind of patterns in Recursion 

>>>>>> print all subsequence whose sum==k <<<<<<<

#include <bits/stdc++.h>
using namespace std;
 
const int k = 5;

void func(int i,int n,int s,vector<int> a,vector<int>& v,
	vector<vector<int>>& ans)
{
	if(i>=n) 
	{
		if(s==k) ans.push_back(v);
		return;
	}

	v.push_back(a[i]);
	// s+=a[i];
	func(i+1,n,s+a[i],a,v,ans);
	// s-=a[i];
	v.pop_back();

	func(i+1,n,s,a,v,ans);
}
 
//>>>>>>>>>>>>>>>>###################<<<<<<<<<<<<<<<<<<<
int main(){
	#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
//>>>>>>>>>>>>>>>>###################<<<<<<<<<<<<<<<<<<<
int n;		cin>>n;
vector<int> a(n);
for(int i=0;i<n;++i) cin>>a[i];

int sum = 0;
vector<vector<int>> ans;
vector<int> v;
func(0,n,sum,a,v,ans);

for(auto x:ans)
{
	for(auto it:x) cout<<it<<" ";
		cout<<endl;
}}

// *****************************************************************************************************************

// >>>>>> print 1st subsequence whose sum==k <<<<<<<

#include <bits/stdc++.h>
using namespace std;
 
const int k = 5;

bool func(int i,int n,int s,vector<int> a,vector<int>& v,
	vector<vector<int>>& ans)
{
	if(i>=n) 
	{
		if(s==k) 
		{
			ans.push_back(v);
			return true;
		}
		return false;
	}

	v.push_back(a[i]);
	// s+=a[i];
	if(func(i+1,n,s+a[i],a,v,ans)) return true;
	// s-=a[i];
	v.pop_back();

	 if(func(i+1,n,s,a,v,ans)) return true;
	return false;
}
 
//>>>>>>>>>>>>>>>>###################<<<<<<<<<<<<<<<<<<<
int main(){
	#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
//>>>>>>>>>>>>>>>>###################<<<<<<<<<<<<<<<<<<<
int n;		cin>>n;
vector<int> a(n);
for(int i=0;i<n;++i) cin>>a[i];

int sum = 0;
vector<vector<int>> ans;
vector<int> v;
func(0,n,sum,a,v,ans);

for(auto x:ans)
{
	for(auto it:x) cout<<it<<" ";
		cout<<endl;
}}


// *****************************************************************************************************************

// >>>>>> number of subsequences whose sum==k <<<<<<<

#include <bits/stdc++.h>
using namespace std;
 
const int k = 5;

int func(int i,int n,int s,vector<int> a,vector<int>& v,
	vector<vector<int>>& ans)
{
	if(i>=n) 
	{
		if(s==k) 
		{
			return 1;
		}
		return 0;
	}

	// v.push_back(a[i]);

	int l = func(i+1,n,s+a[i],a,v,ans)  ;

	// v.pop_back();

	int r = func(i+1,n,s,a,v,ans);
	return l+r;
}
 
//>>>>>>>>>>>>>>>>###################<<<<<<<<<<<<<<<<<<<
int main(){
	#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
//>>>>>>>>>>>>>>>>###################<<<<<<<<<<<<<<<<<<<
int n;		cin>>n;
vector<int> a(n);
for(int i=0;i<n;++i) cin>>a[i];

int sum = 0;
vector<vector<int>> ans;
vector<int> v;
cout<<func(0,n,sum,a,v,ans);
}

// *****************************************************************************************************************

// L8. Combination sum 1

>>> Combinationn sum 1 <<<

class Solution {
public:
    void func(int i,int s,vector<vector<int>>& ans,vector<int> v,vector<int> a,int k)
    {
        if(i>=a.size()) 
        {
            if(s==0) 
            {
                ans.push_back(v);
                return;
            }
            return;
        }

        v.push_back(a[i]);
        if(s-a[i]>=0) func(i,s-a[i],ans,v,a,k);
        v.pop_back();

        func(i+1,s,ans,v,a,k);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        int i=0;
        int sum = target;
        func(i,sum,ans,v,candidates,target);
        return ans;
    }
};

tc = 2^target * k

// *****************************************************************************************************************
// L9. Combination sum 2 

class Solution {
public:
    void func(int ind,int s,vector<int> a,vector<int> v,vector<vector<int>>& ans)
    {
        if(s==0) 
        {
            ans.push_back(v);
            return;
        }

        for(int i=ind;i<a.size();++i)
        {
            if(i>ind&&a[i]==a[i-1]) continue;
            if(a[i]>s) break;
            v.push_back(a[i]);
            func(i+1,s-a[i],a,v,ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
       vector<int> v;
       sort(candidates.begin(),candidates.end());
       func(0,target,candidates,v,ans);
       return ans; 
    }
};

// *****************************************************************************************************************

L10.subset sum 1 ...

>>>> gfg : subset sum 1 <<<<

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void func(int i,int s,vector<int> a,vector<int> v,vector<int>& ans)
    {
        if(i>=a.size()) 
        {
            ans.push_back(s);
            return;
        }
        
        v.push_back(a[i]);
        func(i+1,s+a[i],a,v,ans);
        v.pop_back();
        
        func(i+1,s,a,v,ans);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        vector<int> v;
        func(0,0,arr,v,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends

// *****************************************************************************************************************

Leetcode : subsets 1 

class Solution {
public:
    void func(int i,vector<int> a,vector<int> v,vector<vector<int>>& ans)
    {
        if(i>=a.size()) 
        {
            ans.push_back(v);
            return;
        }

        v.push_back(a[i]);
        func(i+1,a,v,ans);
        v.pop_back();

        func(i+1,a,v,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        func(0,nums,v,ans);
        return ans;
    }
};

// *****************************************************************************************************************

L11. subset 2..

// *****************************************************************************************************************

L12. permutations (approach 1)..

class Solution {
public:
    void func(vector<int> a,vector<int>& vis,vector<int> v,vector<vector<int>>& ans)
    {
        if(v.size()>=a.size())
        {
            ans.push_back(v);
            return;
        }

        for(int i=0;i<a.size();++i)
        {
            if(vis[i]==1) continue;
            v.push_back(a[i]);
            vis[i]=1;
            func(a,vis,v,ans);
            vis[i]=0;
            v.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> vis(nums.size(),0);
        func(nums,vis,v,ans);
        return ans;
    }
};

// *****************************************************************************************************************

L13. Permutations (approach 2)..

// *****************************************************************************************************************

L14. N queen (extra tc)...

tc = o(n * 3n)

class Solution {
public:
    bool issafe(int row,int col,vector<string> v,int n)
    {
        int r = row;
        int c = col;
        while(col>=0)
        {
            if(v[row][col]=='Q') return false;
            --col;
        }           
        row=r;  col=c;
        while(col>=0&&row>=0)
        {
            if(v[row][col]=='Q') return false;
            --row;
            --col;
        }
        row=r;  col=c;                  
        while(col>=0&&row<n)
        {
            if(v[row][col]=='Q') return false;
            ++row;
            --col;
        }
        return true;
    }
    void func(int col,int n,vector<string>& v,vector<vector<string>>& ans) 
    {
        if(col>=n) 
        {
            ans.push_back(v);
            return;
        }
        for(int row=0;row<n;++row)
        {
            if(issafe(row,col,v,n)) 
            {
                v[row][col] = 'Q';
                func(col+1,n,v,ans);                  
                v[row][col] = '.';
            } 
        }
    }       

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n);
        string s(n,'.');
        for(int i=0;i<n;++i) v[i]=s;

        func(0,n,v,ans);
        return ans;
    }
};

// *****************************************************************************************************************

L14. Optimised code...tc( n*3 )

class Solution {
public:
    
    void func(int col,int n,vector<string>& v,vector<vector<string>>& ans,vector<int>& leftrow, vector<int>& updiag,vector<int>& downdiag) 
    {
        if(col==n) 
        {
            ans.push_back(v);
            return;
        }
        for(int row=0;row<n;++row)
        {
            if(leftrow[row]==0 && downdiag[row+col]==0 && updiag[n-1 +col-row]==0)
            {
                leftrow[row]=1;
                downdiag[row+col]=1;
                updiag[n-1 +col-row]=1;
                v[row][col] = 'Q';
                func(col+1,n,v,ans,leftrow,updiag,downdiag);                  
                v[row][col] = '.';
                leftrow[row]=0;
                downdiag[row+col]=0;
                updiag[n-1 +col-row]=0;
            }   
        }    
    }        

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n);
        string s(n,'.');
        for(int i=0;i<n;++i) v[i]=s;

        vector<int> leftrow(n,0) ; vector<int> downdiag(2*n-1,0); 
        vector<int> updiag(2*n-1,0);

        func(0,n,v,ans,leftrow,updiag,downdiag);
        return ans;
    }
};

// *****************************************************************************************************************

L  .Sudoku solver 

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        func(board);
    } 

    bool func(vector<vector<char>>& board)
    {
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.')
                {
                    for(char c ='1';c<='9';++c)
                    {
                        if(isvalid(c,board,i,j)) 
                        {
                            board[i][j] = c;

                            if(func(board)) return true;
                            else board[i][j]='.';
                        }    
                    }
                    // as no char is possible at that position...hence that combination or board
                    // is not possible...
                    return false;
                }
            }
        }
        // at this line all cells of board are traverse...
        //and we have got our completed board..
        //so to end this function we return true...  
        return true;
    }

    bool isvalid(char c,vector<vector<char>>& board,int row,int col)
    {
        for(int i=0;i<9;++i)
        {
            if(board[i][col]==c) return false;
            
            if(board[row][i]==c) return false;

            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3]==c) return false;
        }
        return true;
    } 
};

// *****************************************************************************************************************








