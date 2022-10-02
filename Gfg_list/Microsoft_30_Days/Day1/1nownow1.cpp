// https://practice.geeksforgeeks.org/batch-problems/longest-subarray-with-sum-divisible-by-k1259/0/?track=microsoft-29days-day1&batchId=636




#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
bool alphanumeric_util(string in)
{
    for (auto ch:in)
        if(ch>='0' &&ch<='9')
            return false;

    return true  ;
}
bool prime_check(string order)
{
    int cut = order.find(" ");
    string id = order.substr(0 , cut);
    string metdata1 = order.substr(cut+1 , order.size());
    int cut2 = metdata1.find(" ");
    string firstpartofmetadata = metdata1.substr(0 , cut2);
    // cout<<"\n"<<id<<"  "<<metdata1<<"  "<<firstpartofmetadata<<endl;
    for (auto ch:firstpartofmetadata)
    {
        if(ch>='0' &&ch<='9')
            return false;
        // if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
        //     return true ;
    }
    return true  ;

}
int compare_function(string a1 , string b1)
{
    // tokenize_string
    
    bool isprime_check_order1 = prime_check(a1);
    bool isprime_check_order2 = prime_check(b1);


    int cut = a1.find(" ");
    string id1 = a1.substr(0 , cut);
    string metdata1 = a1.substr(cut+1 , a1.size());
    cut = b1.find(" ");
    string id2 = b1.substr(0 , cut);
    string metdata2 = a1.substr(cut+1 , b1.size());


    if(isprime_check_order1 && isprime_check_order2)
    {
        // cout<<"Reached"<<metdata1<<endl;
        if(metdata1!=metdata2)
            return metdata1.compare(metdata2) ;
        
        return id1.compare(id2);
    }

    //if only one prime 
    if(isprime_check_order1) 
        return -1 ;
    if(isprime_check_order2)
        return 1  ;

    return 0 ;    
}


vector<string>sortedOrders(vector<string> orderlist)
{
    // vector<pair<string,string>> input1 = split_the_string(orderlist);
    // sort(orderlist.begin(),orderlist.end(),compare_function);
    vector<string> prime_orders = {};
    vector<string> non_prime_orders = {};
    vector<string> ans1 = {} ;
    for(auto x: orderlist)
    {
        int cut = x.find(" ");
        string id = x.substr(0 , cut);
        string metdata1 = x.substr(cut+1 , x.size());
        int cut2 = metdata1.find(" ");
        string firstpartofmetadata = metdata1.substr(0 , cut2);
        if(alphanumeric_util(firstpartofmetadata))
            prime_orders.push_back(x);
        else 
            non_prime_orders.push_back(x);
    }

    sort(prime_orders.begin(),prime_orders.end(),compare_function);
    int i1 =0,j1=0 ;
    for(auto x: orderlist)
    {
        int cut = x.find(" ");
        string id = x.substr(0 , cut);
        string metdata1 = x.substr(cut+1 , x.size());
        int cut2 = metdata1.find(" ");
        string firstpartofmetadata = metdata1.substr(0 , cut2);
        if(alphanumeric_util(firstpartofmetadata))
            ans1.push_back(prime_orders[i1++]);
        else 
            ans1.push_back(prime_orders[j1++]);

            // non_prime_orders.push_back(x);
    }
    return ans1 ;
}

int main(int argc, char const *argv[])
{
    vector<pair<string,string>> input_parsing ; 
    // vector<string>orderlist = {{"abc 12 23"},{"xff 43 29"},{"af nfrh nfrh"},{"f kindle ebook"}};
    // vector<string>orderlist = {{"af nfrh nfrh"},{"f kindle ebook"}};

    // vector<string>orderlist = {{"zid 93 12"},{"fp kindle book"},{"10a echo show"},{"17g 12 256"},{"ab1 kindle book"},{"125 echo dot second generation"} };
    vector<string>orderlist = {{"fp kindle book"},{"10a echo show"},{"ab1 kindle book"},{"125 echo dot second generation"} };
    
    // for ( auto a1 : orderlist)
    // {
    //     int cut = a1.find(" ");
    //     string id1 = a1.substr(0 , cut);
    //     string metdata1 = a1.substr(cut+1 , a1.size());    
    //     cout<<endl<<id1<<"     "<<metdata1;
    // }
    
    
    // cout<<endl<<prime_check("abc night jesack output");
    // cout<<endl<<prime_check("abc 12 23");
    vector<string> output = sortedOrders(orderlist);
    for(auto x: output)
        cout<<"\n"<<x ;

    return 0;
}




