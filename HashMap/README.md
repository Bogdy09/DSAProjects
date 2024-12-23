# Bag ADT with Open Addressing (Double Hashing)

This project implements a Bag (Multi-set) Abstract Data Type (ADT) using a dynamic hashtable with open addressing and double hashing for collision resolution.

## Key Features:

**Dynamic Hashtable:** Automatically resizes and rehashes when the load factor exceeds a specified threshold (α).
**Supports Duplicates:** Elements can appear multiple times in the bag, with their occurrences tracked.
**Efficient Operations:**
Add elements.
Remove elements (single occurrences or all).
Search for elements.
Count occurrences of a specific element.
Custom Iterator: Iterate over the elements in the bag with BagIterator.

**Internal Details:**
Hashing:
**Primary Hash Function (hash1):** Computes the initial position of an element.
**Secondary Hash Function (hash2):** Used for probing in collision resolution.

**Special Values:**
**NULL_TELEM:** Marks empty slots.
**DELETED_TELEM:** Marks previously occupied slots, enabling efficient probing.
**Load Factor Management:** Ensures optimal performance by resizing the table when necessary.
