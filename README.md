## Hello, and welcome
###This place is where I'm documenting the process to learn different data structures in a pratical way, through C++.

#Big Os

To measure the time and space complexity, we can count on how many processess the program goes until finding the worst case.
Note: big O is specifically the worst case scenario. The best case scenario is omega, and average, theta.

![alt text](/src/img/grafico.png)

## O(n)

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


## O(n²)

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

## O(1)
- very low complexity.
```
int addItems(int n) {
    return n + n;
}
```


## O(log n)
- on this case, the algorithm get to the half of the list, checks if the number is before or after than the current spot; then it discards the other half, and goes to the half of the count there the item is.


## O(n log n)
- used a lot in sorting algorithms.
- also a lot consuming, but better than O(n²).


## Big Os in Vectors
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

## Demonstration

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


# Linked Lists

- Linked Lists are often treated as closest to arrays, or vectors
    - but:
        - Vectors have indexes setting the position of each item.
        - Linked Lists have no indexes.

-About them:
    - The items are spread in different parts of the memory instead of in a contiguous space. 
    - The items in the vector now become nodes when in linked lists. 
    - There's a variable that points to the head node of the list.
    - There's a variable that points to the tail node of the list.
    - Each node points to the next, head to tail.
    - The tail node points to a nullptr, as in a pointer that doesn't point to anything.

- What we do with it:
    - Add a node to the end of the list;
        - In current tail, add the new node to the nullptr's tail.
        - Tail points the new node;
        - Has an *O(1)* complexity;
    - Delete the last node:
        Current list:
            3   ->    9   ->    8   ->   7   ->   13   
            H     
                                            T
        Set tail to be equal to the only other pointer that points the current node predecessor, wich is it's own predecessor.
            As in:
                3   ->    9   ->    8   ->   7   ->   13
                H                                     T
                Because whe have to iterate from the head to the tail, the complexity is *O(n)*
                > Delete last node
                - goes from head to tail until it gets to the pointer needed 
                3   ->    9   ->    8   ->   7   ->   13
                H-----------------------^             T
                3   ->    9   ->    8   ->   7   ->   13
                H-----------------------^             T
                > Set the pointer Tail equals to the pointer to 7

    - Add an item to the beggining of the list:
        Point new head pointer to be equal to the head pointer.
        Moves the head pointer to the new head.
        Has an *O(1)* complexity
    - Remove an item that's head of the linked list:
        Point pointer header to the next item. (head->next)
        Has an *O(1)* complexity.
    - Add an item to a node that's somewhere in the middle:
        Current list:
            3   ->    9   ->    8   ->   7   ->   13   
            H                                     T
        Goes from head to the pointer of the node that will be closer to head.
            3   ->    9   ->    8   ->   7   ->   13   
            H-------------^                       T
        Set the pointer of the new node to be equal to the pointer that points to the next item.
            3   ->    9   ->    8   ->   7   ->   13   
                H                     4 -^        T
        Set the pointer of the previous node to be equal to the new node.
            3   ->    9   ->    8      7   ->   13   
                H                -> 4 -^        T
        Has an *O(n)* complexity
    - Remove an item from the list that's somewhere in the middle:
        Goes from head to the item that points to the to-be-removed item. That's the previous item.
            3   ->    9   ->    8   ->   7   ->   13   
            H---------^---^                       T
        Points the previous item's pointer to the to-be-removed item, that points the next.
            3   ->    9         8   ->   7   ->   13   
            H         -------------------^        T
        Has an *O(n)* complexity

- Overall of actions with the LLs and their complexities:
    Append: O(1)
    Remove last: O(n)
    Prepend: O(1)
    Remove First: O(1)
    Insert: O(n)
    Remove: O(n)
    Lookup by index: O(n)
    Lookup by value: O(n)
        While in vectors, their complexities are:
    Remove last: O(1)
    Prepend: O(n)
    Remove First: O(n)
    Lookup by index: O(1)
        The  LLs are more efficient with adding and removing items from the head, but less efficient when removing last and looking up for them;

- Also, linked lists can be demonstrated by:
    head: {
        "value": 3,
        "next" (pointer): {
                "value": 9,
                "next" (pointer): {
                    "value": 8,
                    "next" (pointer): {
                        "value": 7,
                        "next" (pointer):{
                            "value": 13,        // with tail also pointing to them
                            "next" (pointer): nullptr     // with tail also pointing to them
                        }
                    }
                }
            }
        }

## Constructor
When creating a class, the Constructor says what it is.

    LinkedList(int value) {
        Node *newNode = new Node(value);
        head = newNode; // points the head to the node newNode
        tail = newNode;
        length = 1;
    }

In this code, constructor of the LinkedList class, we see that every LinkedList will receive a integer value, then we will set that head points to this value, as well as the tail, because it will be the first element in this new LL. At the end, we set that the length of the list equals 1, to further add new elements and keeping the size of the list known.

## Destructor
The destructor does indeed destruct the LL. Through a loop it destruct all items, head to tail.

    ~LinkedList() {
        Node *temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

In this case the destructor takes the Node that the head points, set the head to be equal to the next in the node, delete the node, repeat. It allow us to disalocate all the list from the memory;


