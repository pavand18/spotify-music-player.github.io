// ## sorting algos : 
// bubble sort 
// merge sort
// quick sort 

// insertion sort 

// *************************************************************************************

// #1. Bubble sort..
tc = o(n^2) = n(n-1)/2  
sc = o(1)
// worst case tc is when vector is sorted in descending order..
// i.e. 

#include <bits/stdc++.h>
using namespace std;

void bubble(vector<int> &v,int n)
{
    // bool swap = true;
    
    for(int i=0;i<n-1;++i){
        // swap = false;
        for(int j=0;j<n-i-1;++j){
            if(v[j] > v[j+1]) 
            {
                swap(v[j],v[j+1]);
                swap = true;
            }
        }
    }
    
    // if(swap == false) break;
} 
//******************
int main(){
	#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
//******************
    int n;      
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
    bubble(v,n);
    
    for(auto it:v) cout<<it<<" ";
    cout<<endl;
} 

// *************************************************************************************

// Recursive way ...

#include <bits/stdc++.h>
using namespace std;

void bubble(vector<int> &v,int n)
{
    if(n==0||n==1) return;
    
    for(int i=0;i<n-1;++i)
    {
        if(v[i]>v[i+1]) swap(v[i],v[i+1]);
    }
    bubble(v,n-1);
}

//******************
int main(){
	#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
//******************
int n;      cin>>n;
vector<int> v(n);
for(int i=0;i<n;++i)
{
    cin>>v[i];
}
bubble(v,n);

for(auto it:v) cout<<it<<" ";
cout<<endl;
}

// *************************************************************************************


