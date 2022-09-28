// https://practice.geeksforgeeks.org/problems/merging-details/1



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<vector<string>> mergeDetails(vector<vector<string>>& details) 
{
    // code here
    int n = details.size();
    unordered_map< string,vector<set<string>> > hash_map ;//string , email 
    for (int i1 = 0; i1 < n; i1++)
    {

        //all elements 
        for (auto keys : hash_map )
        {
            //search each word 
            bool merge_yes = false ;
            for(auto &eachset: hash_map[keys.first] )
            {
                for (int j1 = 1; j1 < details[i1].size() && !merge_yes; j1++)
                    if(eachset.find(details[i1][j1])!=eachset.end())
                        merge_yes = true ;
                    
                        //string found 
                if(merge_yes)
                {
                    // means merge it with this set 
                    for (int j1 = 1; j1 < details[i1].size(); j1++)
                        eachset.insert(details[i1][j1]);

                    break ;
                }
            }

            if(!merge_yes)
            {
                // set<string>new_set(details[i1].begin()+1 ,details[i1].end());
                // hash_map[keys.first].push_back(new_set);
                set<string>new_set ;
                for (int j1 = 1; j1 < details[i1].size(); j1++)
                        new_set.insert(details[i1][j1]);
                
                hash_map[keys.first].push_back(new_set);
            }
        }
        









        if(hash_map.find(details[i1][0])!=hash_map.end()  )
        {
            bool merge_yes = false ;
            for(auto &eachset: hash_map[details[i1][0]] )
            {
                for (int j1 = 1; j1 < details[i1].size() && !merge_yes; j1++)
                    if(eachset.find(details[i1][j1])!=eachset.end())
                        merge_yes = true ;
                    
                        //string found 
                if(merge_yes)
                {
                    // means merge it with this set 
                    for (int j1 = 1; j1 < details[i1].size(); j1++)
                        eachset.insert(details[i1][j1]);

                    break ;
                }
            }

            if(!merge_yes)
            {
                // set<string>new_set(details[i1].begin()+1 ,details[i1].end());
                // hash_map[details[i1][0]].push_back(new_set);
                set<string>new_set ;
                for (int j1 = 1; j1 < details[i1].size(); j1++)
                        new_set.insert(details[i1][j1]);
                
                hash_map[details[i1][0]].push_back(new_set);
            }
        }
        else 
        {
            // set<string>new_set(details[i1].begin()+1 ,details[i1].end());
            // hash_map[details[i1][0]] = {new_set};
            set<string>new_set ;
            for (int j1 = 1; j1 < details[i1].size(); j1++)
                new_set.insert(details[i1][j1]);
                
            hash_map[details[i1][0]].push_back(new_set);
        }
        




    }

    vector<vector<string>> ans1 ;

    for(auto names: hash_map)
        for(auto sets1 : names.second)
        {
            vector<string>ping = {names.first};
            for(auto email : sets1)
                ping.push_back(email);

            ans1.push_back(ping);
        }

    return ans1 ;
    

}



int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int n ,m;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n ;
        vector<vector<string>> input1 ;
        while(n--)
        {
            string name ; 
            cin>>name ;
            vector<string> intup ;
            intup.push_back(name);
            int noofemails ; 
            cin>> noofemails ;
            while(noofemails--)
            {
                cin>>name ;
                intup.push_back(name);
            }
            input1.push_back(intup);
        }
        
        vector<vector<string>> output1 = mergeDetails(input1);
        for (auto vec : output1)
        {
            for(auto str : vec)
                cout<<str<<" ";

            cout<<endl ;
        }
        


    }
    return 0 ;
}






