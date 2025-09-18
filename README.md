# Hello!
##### This place is where I'm documenting the process of learning more about data structures. I'm currently working in C++.

<details>
  <summary>Navegue por seção:</summary>
    <li><a href="#big-os">Big Os</a></li>
    <li><a href="#linked-lists">Linked Lists</a></li>
    <li><a href="#doubly-linked-lists">Doubly Linked Lists</a></li>
</details>


## Big Os

To measure the time and space complexity, we can count on how many processess the program goes until finding the worst case.
Note: big O is specifically the worst case scenario. The best case scenario is omega, and average, theta.

![alt text](/src/img/grafico.png)

### O(n)
```
void printItems(int n) {
    for (int i = 0, i < n; i++) {
        cout << i << endl;
    }
}

int main() {
    printItems(10);
}
```

###### Drop Constants
```
void printItems(int n) {
    for (int i = 0, i < n; i++) {
        cout << i << endl;
    }
    for (int j = 0, j < n; j++) {
        cout << j << endl;
    }
}

int main() {
    printItems(10);
}
```
- in this case, the output will be (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9), because it goes 2*n times. Even though, it's still O(n). 


### O(n²)

```
void printItems(int n) {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << j << endl;
        }
    }
}

int main() {
    printItems(10);
}
```
- this function will go through 00 to 99, so it has a O(n²) complexity.

###### Drop Non-Dominants 

```
void printItems(int n) {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << j << endl;
        }
    }

    for (int k = 0; k < n; k++) {
        cout << k << endl;
    }
}

int main() {
    printItems(10);
}
```

- on this case, the complexity can be written in O(n² + n), because the result goes from 00 to 99 and then from 0 to 9.
- The big scandal around dropping is because even though the complexity is not quite the same, when talking about the big Os, those non-dominant and/or secondary functions won't alter the overall behaviour of the notation.

### O(1)
- very low complexity.
```
int addItems(int n) {
    return n + n;
}
```

### O(log n)
- on this case, the algorithm get to the half of the list, checks if the number is before or after than the current spot; then it discards the other half, and goes to the half of the count there the item is.

### O(n log n)
- used a lot in sorting algorithms.
- also a lot consuming, but better than O(n²).

### Big Os in Vectors
- take the array 
    |id | item |
    |---|---|
    | 0 | 2 |  
    | 1 | 32 |  
    | 2 | 9 |  
    | 3 | 12 |
- everytime there is an insert or delete in the beggining of the array, the complexity will be O(n) because all the items has to be reindexed.
- if the insert or delete occurs in the last item, the complexity is O(1).
- every other input fits the drop constants logic.

### Demonstration

- when n = 100:
    - O(1) = 1
    - O(log n) ≃ 7
    - O(n) = 100
    - O(n²) = 10.000
<br>
- when n = 1.000:
    - O(1) = 1
    - O(log n) ≃ 10
    - O(n) = 1.000
    - O(n²) = 1.000.000
<br>
- this shows how important understanding and optimizing the complexity is, specially when working with more items.

- An easy way to visualize wich one is wich, you can take that O(n²) is a loop within a loop; O(n) is a proportional straight line; O(log n) is a divide and conquer style, a curved line approaching the O(1); and finally the O(1) is always the straight line over the input size line.

Make sure to check out the [Big O CheatSheet](https://www.bigocheatsheet.com/) website. 


## Linked Lists

- Linked Lists are often treated as closest to arrays, or vectors
    - but:
        - Vectors have indexes setting the position of each item.
        - Linked Lists have no indexes.

### About them:
- The items are spread in different parts of the memory instead of in a contiguous space. 
- The items in the vector now become nodes when in linked lists. 
- There's a variable that points to the head node of the list.
- There's a variable that points to the tail node of the list.
- Each node points to the next, head to tail.
- The tail node points to a nullptr, as in a pointer that doesn't point to anything.

### What we do with it:
- Add a node to the end of the list;
    - In current tail, add the new node to the nullptr's tail.
    - Tail points the new node;
    - Has an **O(1)** complexity;
- Delete the last node:
    Current list:
        3   ->    9   ->    8   ->   7   ->   13   
        H     
                                        T
    Set tail to be equal to the only other pointer that points the current node predecessor, wich is it's own predecessor.
        As in:
            3   ->    9   ->    8   ->   7   ->   13
            H                                     T
        Because whe have to iterate from the head to the tail, the complexity is **O(n)**
            > Delete last node
            - goes from head to tail until it gets to the pointer needed 
            3   ->    9   ->    8   ->   7   ->   13
            H-----------------------^             T
            3   ->    9   ->    8   ->   7   ->   13
            H-----------------------^             T
            > Set the pointer Tail equals to the pointer to 7

- Add an item to the beggining of the list:
    - Point new head pointer to be equal to the head pointer.
    - Moves the head pointer to the new head.
    - Has an **O(1)** complexity
- Remove an item that's head of the linked list:
    - Point pointer header to the next item. (head->next)
    - Has an **O(1)** complexity.
- Add an item to a node that's somewhere in the middle:
    Current list:
        3   ->    9   ->    8   ->   7   ->   13   
        H                                     T
    - Goes from head to the pointer of the node that will be closer to head.
        3   ->    9   ->    8   ->   7   ->   13   
        H-------------^                       T
    - Set the pointer of the new node to be equal to the pointer that points to the next item.
        3   ->    9   ->    8   ->   7   ->   13   
            H                     4 -^        T
    - Set the pointer of the previous node to be equal to the new node.
        3   ->    9   ->    8      7   ->   13   
            H                -> 4 -^        T
    - Has an **O(n)** complexity
- Remove an item from the list that's somewhere in the middle:
    - Goes from head to the item that points to the to-be-removed item. That's the previous item.
        3   ->    9   ->    8   ->   7   ->   13   
        H---------^---^                       T
    - Points the previous item's pointer to the to-be-removed item, that points the next.
        3   ->    9         8   ->   7   ->   13   
        H         -------------------^        T
    - Has an **O(n)** complexity

- Overall of actions with the LLs and their complexities:
    - Append: O(1)
    - Remove last: O(n)
    - Prepend: O(1)
    - Remove First: O(1)
    - Insert: O(n)
    - Remove: O(n)
    - Lookup by index: O(n)
    - Lookup by value: O(n)
        While in vectors, their complexities are:
    - Remove last: O(1)
    - Prepend: O(n)
    - Remove First: O(n)
    - Lookup by index: O(1)
        The  LLs are more efficient with adding and removing items from the head, but less efficient when removing last and looking up for them;

- Also, linked lists can be demonstrated by:

```head: {
        "value": 3,
        "next" (pointer): {
                "value": 9,
                "next" (pointer): {
                    "value": 8,
                    "next" (pointer): {
                        "value": 7,
                        "next" (pointer):{
                            "value": 13,                  // with tail also pointing to them
                            "next" (pointer): nullptr     // with tail also pointing to them
                        }
                    }
                }
            }
        }
```

### Constructor
When creating a class, the Constructor says what it is.

```
    LinkedList(int value) {
        Node *newNode = new Node(value);
        head = newNode; // points the head to the node newNode
        tail = newNode;
        length = 1;
    }
```

In this code, constructor of the LinkedList class, we see that every LinkedList will receive a integer value, then we will set that head points to this value, as well as the tail, because it will be the first element in this new LL. At the end, we set that the length of the list equals 1, to further add new elements and keeping the size of the list known.

### Destructor
The destructor does indeed destruct the LL. Through a loop it destruct all items, head to tail.

```
    ~LinkedList() {
        Node *temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
```
In this case the destructor takes the Node that the head points, set the head to be equal to the next in the node, delete the node, repeat. It allow us to disalocate all the list from the memory;

### Append
Adding a node to the end of the list requires us to: 
- create the new node, that receives the value, 
- check if the list has length equals to zero so we can set head and tail to the new node
- if not, we set the current tail node to point to the new node, filling the nullptr, then set the tail pointer to point to the new node.
- increasing the length through i++ 

### Pop
In order to delete the last node, we have to:
- check is the length is 0, if it is then there's nothing to delete.
- create a variable called temp that will hold info. It receives head.
- check if the length is 1, and if it is, set both head and tail to nullptr (so we can deallocate from memory)
- if the length is not 1, we set a new variable pre.
- both temp and  pre iterates trhough the list, set to stop when temp->next is null. 
    - then we equal pre to temp,
    - set temp to be equal to temp->next
-and it will go until temp is the pointer to the last node, and pre, the pointer to the one that preceeds.
- in this position, we can set that the LL tail is now equal to pre;
- then we decrease the length;

### Prepend
For adding a new item in the beggining of the list, we do:
- create a new node
- check if the list's length equals zero,
    - if so, define both head and tail to point the new node;
- if it's not zero, set the nullptr in new node to point to current head.
- then set the pointer head to the new node.
- increase the length of the list.

### Delete First
Deleting the first element is fairly uncomplicated:
- if the head points to a nullptr, there's nothing to delete.
- if there's one element, we'll set head and tail to a nullptr.
- if not, define that the head equals to the pointer next in currend head.
- then, delete the temporary node we created,
- and finally decrease length.

### Get
Getting an item is very straigth-forward:
- check if the input is not negative neither bigger than the list.
- create a temp variable, that equals the head.
- iterate through the list until the node.
- return temp.

### Set
The set function overlaps the previous value with a new one, given the index:
- set a temp node that get(index). Get index returns the temp.
- if temp is ok (as in goes through the get function correctly), replace the value of this temp with the value of the input.
- return true.
- if temp is not ok, return false.

### Insert
In this function we add a new node at a chosen index:
- First we check if the index is valid (not negative, under the length), and if it isn't valid we return.
- Then check if the index = 0, and if so, we call the prepend() function.
- Then check if the index = length, and if so, we call the append() function.
- Finally, we do create two new nodes, one receives the value (newNode), and the other receives the index-1 (temp).
- Set the newNode->next to equal the temp->next (so the newNode address itself).
```
    1       2       3
    H               T

    newNode->next = temp->next
    1       2  -------->  3
    H         /           T
        temp->next   4----^
                 newNode->next
```
- Set the temp->next to be the newNode, so the pointers point in the correct order.
```
    temp->next = newNode;
    1       2  --->  4       3
    H   temp->next           T
```
- increase the length.
- return true.

### Reverse

- In order to reverse the list, we need a temp, a before and a after node. 
- Start by setting temp equals head, then head equals tail, then tail equals temp.
- Then, after receives temp->next (temp holds the original head) and before points to nullptr.
- After that, we iterate through all elements in list, doing the following:
    - after receives the temp->next, so it can hold the next element in reverse process;
    - temp->next receives before, where the current node will point;
    - before equals temp, where the current node points to;
    - temp equals after, that will then receive temp->next;

# Doubly Linked List

- The main difference here is that there is an extra pointer, called prev:
```
class Node {
  public:
    int value;
    Node *next;
    Node *prev;

    Node (int value) {
      this->value = value;
      next = nullptr;
      prev = nullptr;
    }
}