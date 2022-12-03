# // User function Template for C++
class Solution:
    def decodedString(self, s):
        # code here
        stack_1 = []
        for i in s : 
            if(i!=']'):
                stack_1.append(i)
            else:
                temp = ""
                while len(stack_1)>0 and stack_1[-1]!='[':
                    temp = stack_1[-1]+temp 
                    stack_1.pop() 
                stack_1.pop() # [ remove 
                count = 0 
                power = 1
                while len(stack_1)>0 :
                    num = stack_1[-1]#>='0' and stack_1[-1]<='9'):
                    try:
                        num = int(stack_1[-1])
                    except:
                        break 
                    num*=power 
                    power*=10
                    count+=num 
                    stack_1.pop()
                while(count>0):
                    count-=1 
                    for c in temp:
                        stack_1.append(c)
        ans1 = ""
        while (len(stack_1)>0):
            ans1=stack_1[-1]+ans1
            stack_1.pop()

        return ans1 

# class Solution{
# public:
#     string decodedString(string s){
#         // code here
#         stack<char> s1 ;
#         for (int i1 = 0; s[i1]; i1++)
#         {
#             if(s[i1]!=']')
#                 s1.push(s[i1]);
#             else 
#             {
#                 string temp = "";
#                 while(!s1.empty()&&s1.top()!='[')
#                 {
#                     temp = s1.top()+temp;
#                     s1.pop();
#                 }
#                 s1.pop();//remove [
#                 int count = 0;
#                 int power = 1 ;
#                 while(!s1.empty()&& (s1.top()>='0' &&s1.top()<='9'))
#                 {
#                     int num = s1.top()-'0';
#                     num = num*power ;
#                     power*=10 ;
#                     count+=num ;
#                     s1.pop();
#                 }
#                 // s1.pop();//remove count
#                 while(count--)
#                     for(auto c : temp)
#                         s1.push(c);
#             }
#         }
#         string ans1 = "";
#         while(!s1.empty())
#             ans1 = s1.top()+ans1,s1.pop();
#         return ans1 ;
    
#     }
# };