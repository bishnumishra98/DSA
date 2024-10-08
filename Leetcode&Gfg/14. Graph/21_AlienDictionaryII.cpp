// It is a follow-up of the previous problem '20_AlienDictionaryI.cpp'.
// We are asked to return an empty string if ordering of alphabets is not possible.

// Algorithm: There will be only two cases when ordering of alphabets is not possible:
// Case 1: If input provided is not in lexicographical order.
//         Example: {"abc", "ab"}.
//         Here, we can see "abc" stands before "ab" which is lexicographically incorrect.
//         In lexicographical order, shorter words come before longer words if one is a prefix of the other.
// Case 2: If there is an input which has cyclic dependency.
//         Example: {"abc", "bcd", "aef"}.
//         On building the graph of the above array of string, we find that 'a' and 'b' form a cyclic dependency.
//         a --> b
//         /\    |
//         |_____|
//         Thus, their ordering is not possible.

