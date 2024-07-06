// HASHING: Hashing is the process of converting a given key into another value using a hash function. This mathematical algorithm
//          generates a new value (called a hash or hash value) based on the input key. Here are the properties of a good hash function:
//          ➤ Efficiently Computable: The hash function should be fast to compute.
//          ➤ Uniform Distribution: It should evenly distribute keys across the hash table.

// HASH TABLE: A hash table is a data structure that maps keys to values. It uses a hash function to compute an
//             index (also known as a hash code) into an array of buckets or slots. Each bucket can store a value associated
//             with a unique key. Key points about hash tables:
//             ➤ Every key in a hash table is unique.
//             ➤ Hash tables support three fundamental operations:
//                i.   Insert (key, value): Adds an item to the hash table.
//                ii.  Get (key): Retrieves the value associated with the given key.
//                iii. Delete (key): Removes a value based on the given key.
//             ➤ Ideally, these operations execute in O(1) time (constant time).

// HOW HASHING WORKS ?
// 1. Insertion: When you insert a key-value pair, the hash function computes an index for the key. The value is then stored at that index.
// 2. Collision: Sometimes, different keys may produce the same index (collision). Handling collisions is crucial for hash tables.

// COLLISION RESOLUTION TECHNIQUES IN HASHING: There are various ways to minimize collisions while hashing in hash tables:
// 1. Open Hashing (Chaining): In open hashing, each bucket (slot) in the hash table contains a linked list or another data structure
//                             (like a tree). When a collision occurs, we insert the new key-value pair into the linked list at that index.
//                             Chaining allows multiple keys to coexist in the same bucket without overwriting each other.
// 2. Closed Hashing (Open addressing): Closed addressing aims to resolve collisions by finding an alternative slot within the same bucket.
//                                      There can be different kinds of closed hashing:
//    i.   Linear Probing: When a collision occurs, we search for the next available slot (usually the next index) in the hash table.
//                         ➤ Next index = (h + i) % n;   where h =  hash number, i = probe number, n = size of hash table
//    ii.  Quadractic Probing: It uses a quadratic function to determine the next probing position. When a collision occurs, we compute
//                             the next index using the formula:
//                             ➤ Next index = (h + i^2) % n;   where h =  hash number, i = probe number, n = size of hash table
//    iii. Double Hashing: Double hashing combines two hash functions. Double hashing aims to distribute keys more uniformly.
//                         ➤ Next index = h1(key) + h2(key);   where h1 and h2 are different hash functions

// LOAD FACTOR: The load factor measures how full the hash table is allowed to get before increasing its capacity. It’s calculated as:
//              ➤ Load Factor = Number of items in the table​ / Number of slots in the hash table
//              Lower load factors (closer to 0) generally mean fewer collisions, but they also imply larger memory usage.
//              In practice, hash tables often aim for a load factor between 0.5 and 0.8. If the load factor exceeds a certain
//              threshold (e.g., 0.9), it’s time to resize the hash table (increase the number of slots) to maintain efficiency.

// APPLICATIONS OF HASHING:
// 1. Implementing hash tables, hash maps, and Python dictionaries.
// 2. Unordered sets.
// 3. Cryptography (cryptographic hash functions).
