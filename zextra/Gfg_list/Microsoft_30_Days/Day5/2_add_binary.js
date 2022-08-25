

// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day5/problem/add-binary-strings3805

class Solution {
    addBinary(A,B){ 
      //code here
      

     var result = "";
     var s = 0;        
     var i = A.length - 1, j = B.length - 1;
     while (i >= 0 || j >= 0 || s == 1)
     {
          
         s += ((i >= 0)? A.charAt(i).charCodeAt(0) -'0'.charCodeAt(0): 0);
         s += ((j >= 0)? B.charAt(j).charCodeAt(0) -'0'.charCodeAt(0): 0);
         result = String.fromCharCode(parseInt(s % 2) +'0'.charCodeAt(0)) + result;
         s = parseInt(s/2);
         i--; j--;
     }
    i=0 ; 
    while(i< result.size() && result[i]=='0')
        i++;
    if(i==result.size())
     return "0";

    result = result.substring(i) ; 
    return result;
    }
}