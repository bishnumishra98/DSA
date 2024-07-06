// This code is already solved by slow and fast pointer approach(tortoise and hare algorithm). But it can
// even be solved using maps.
// Algorithm: Store the address of every node you visit in a map(address, bool). Mark true if you visit an
// address for first time. Move on to next node and do the same until linked list gets finished. If you
// find any node, that was already visited, a cycle is found in the linked list.

// Visit this code for implementation: 'BaseBuildingPrograms\13. Linked_List\LL12_CyclesInLL.cpp'
