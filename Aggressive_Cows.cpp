#include<iostream>
#include <bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
bool check(int num, int stalls[], int n, int c)
{
    int cows=1;
    int pos=stalls[0];
    for(int i=1;i<n;i++)
    {
        if(stalls[i]-pos>=num)
        {
            pos=stalls[i];
            cows+=1;
            if(cows==c)
                return true;
        }
    }
    return false;
}
int binarysearch(int stalls[], int n, int c)
{
    int l=0;
    int h=stalls[n-1];
    int max=-1;
    while(l<h)
    {
        int m=(l+h)/2;
        if(check(m,stalls,n,c))
        {
            if(m>max)
                max=m;
                l=m+1;
        }
        else
            h=m;
    }
    return max;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        int stalls[n];
        for(int i=0;i<n;i++)
            cin>>stalls[i];
       sort(stalls,stalls+n);
        int ans=binarysearch(stalls,n,c);
        cout<<ans;
    }
    return 0;
}
