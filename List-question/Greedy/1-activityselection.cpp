
#include<bits/stdc++.h>
using namespace std;




    int maxMeetings(int start[], int end[], int n)
    {
        pair<int ,int>arr1[n];
        for(int i=0;i<n;i++)
        {
            arr1[i].first = end[i];arr1[i].second = start[i];
        }
        sort(arr1,arr1+n);
        // for(int i=0;i<n;i++)
        // {
        //     end[i] = arr1[i].first  ;start[i] = arr1[i].second;
        // }
        int asnwer1 = 0 ;
        int curr1 = 0;
        for(int j1 =0 ;j1<n;j1++)
        {
            if(curr1<arr1[j1].second)
            {
                curr1 = arr1[j1].first;asnwer1++;
            }
        }
        return asnwer1;
    }