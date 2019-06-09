#include<string.h>
#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[]) {
    int t=0;

    while (1)
    {
        t++;
        string str;
        cin>>str;
        if(str[0]=='-')
        {
            break;
        }

        stack <int> s;
        int cnt1 = 0,cnt2 =0,ans=0;
        for (size_t i = 0; i < str.size(); i++) {
            if (str[i]=='{')
            s.push(1);
            else if (!s.empty()) {
            s.pop();
            }
            else
            {
                cnt1+=1;
            }

        }
        cnt2 = s.size();

    if (cnt1%2==0 && cnt2%2==0)
    {
        cnt1/=2;
        cnt2/=2;
        ans = cnt1+cnt2;
    }
    else
    {
        --cnt1/=2;
        --cnt2/=2;
        ans = cnt1+cnt2+2;
    }

std::cout << t <<". "<<ans<< '\n';
}


    return 0;
}
