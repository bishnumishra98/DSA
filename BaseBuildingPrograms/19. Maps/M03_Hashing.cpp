// Hashing:
// Hashing is the process of converting a given key into another value using a hash function. This mathematical algorithm generates a new value (called a hash or hash value) based on the input key. Here are the properties of a good hash function:

// Efficiently Computable: The hash function should be fast to compute.
// Uniform Distribution: It should evenly distribute keys across the hash table.
// Hash Tables:
// A hash table is a data structure that maps keys to values. It uses a hash function to compute an index (also known as a hash code) into an array of buckets or slots. Each bucket can store a value associated with a unique key. Key points about hash tables:

// Every key in a hash table is unique.
// Hash tables support three fundamental operations:
// Insert (key, value): Adds an item to the hash table.
// Get (key): Retrieves the value associated with the given key.
// Delete (key): Removes a value based on the given key.
// Ideally, these operations execute in O(1) time (constant time).