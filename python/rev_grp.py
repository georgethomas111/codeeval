""" 
list of numbers and a positive integer k, reverse the elements of the
list, k items at a time. If the number of elements is not a multiple
of k, then the remaining items in the end should be left as is.

ip - array of numbers []
value of k - grouping amount.

leave last set as it is.


normal logic 

1 -> 2 -> 3 -> 4 -> 5 k = 2

2 -> 1 ->
"""

def rev_list(iplist, k):
    """
    traverse list k units at a time and update it so that those k are reversed.    
 
    """
    start_index = 0 
    end_index   = start_index + k   
    
    
    while(end_index < len(iplist)):
        front  = iplist[0:start_index]
        mid    = iplist[start_index:end_index][::-1] 
        end    = iplist[end_index:]
        print front, mid, end
       # front  = front.extend(end)
       # iplist = front
        abc = []
        print type(front), type(mid), type(end)
        print abc.extend(mid)
        start_index = end_index 
        end_index   = end_index + k
    
    return iplist

print rev_list([1, 2, 3, 4, 5], 2)
