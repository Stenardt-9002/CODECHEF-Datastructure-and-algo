// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day9/problem/intersection-point-in-y-shapped-linked-lists

intersectPoint(head1, head2)
{
    //your code here
    if(head1==null || head2==null)
        return null ;
        
    let a1 = head1 ;
    let a2 = head2 ;
    while(a1!=a2)
    {
        a1 = a1==null?head2:a1.next;
        a2 = a2==null?head1:a2.next;
    }
    if(a1==null)
        return null;
    return a1.data ;
}