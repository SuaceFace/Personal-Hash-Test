My CPP professor proposed that I do a personal project to try to create a hashtable with separate chaining, which is exactly what this is.

I initially programmed it crudely, then moved it into a separate .h file, and then templatized everything to be nonspecific, typename T. 

There are 3 classes. 
1. Hasher: Holds a dynamic array of LinkedLists. If any LinkedList exceeds a length of 5, it'll create a new array of double size, copy everything over(with rehashed indexes), and delete the old array. 
            When adding a value, the class hashes the key to get an index, then stores the key and value in a ListNode in the LinkedList at the appropriate index
2. ListNode: A node with a string _key and a single T value, along with a pointer to the next node in the linked list.
3. LinkedList: Holds a pointer to the head Node. Has methods to add to front and back, and remove front and back. It also has a value to track the length of the LinkedList.

The main utilizes these classes two create two hashed arrays. First, it creates a hashed array where the keys are the names of the 50 States, and the values are strings of the matching state nickname. 
  Afterwards, it creates a hashed array where the keys are the names of the 50 States, and the values are integers of the estimated population of the state.
