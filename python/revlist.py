""" 
list of numbers and a positive integer k, reverse the elements of the
list, k items at a time. If the number of elements is not a multiple
of k, then the remaining items in the end should be left as is.

ip - array of numbers []
value of k - grouping amount.

leave last set as it is.

normVal logic 

1 -> 2 -> 3 -> 4 -> 5 k = 2

2 -> 1 -> 4 -> 3 -> 5
"""

def find_k_ahead(node, ahead_count):
    """
    Find k ahead and also say if it is 
    returns None if the list terminates before k nodes.
    """
    count = 0
    while count < ahead_count or node.next_node != None : 
        node  = node.next_node
        count = count + 1

    if count != ahead_count and node.next_node = None
        return None
    return node


def reverse(prev_node, curr_node, next_node):
    """
    Reverse start_node till end_node and make the link of the reversed list
    to the next_node.
    
    """
    if start_node.next_node == end_node :
         end_node.next_node = start_node
         return end_node
    
    node = reverse(start_node.next_node, end_node)
         
    return node

def rev_list(iplist, k_val):
    """
    traverse list k units at a time and update it so that those k are reversed.    

    1 -> 2 -> 3 -> 4 -> 5 k = 2
    2 -> 1 -> 4 -> 3 -> 5
    """
    start_node  = iplist.head 
    k_ahead = find_k_ahead(start_node, k_val)
    next_start = k_ahead.next_node
    head = reverse(start_node, k_ahead) #should return k ahead.
    while(k_ahead != None) :
         
         next_node = k_ahead.next_node
         head = reverse(start_node, k_ahead)
         start_node = next_node
         
    iplist.head = head
    return iplist

print rev_list([1, 2, 3, 4, 5], 2)
