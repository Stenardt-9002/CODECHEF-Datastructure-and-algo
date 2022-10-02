getMiddle(node)
{
    //your code here 
    let slow = node ;
    let fast = node ;
    while(fast!=null && fast.next!=null)
    {
        slow = slow.next ;
        fast = fast.next.next ;
    }
    return slow.data ;
}