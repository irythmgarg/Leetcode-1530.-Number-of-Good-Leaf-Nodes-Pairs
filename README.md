# Leetcode-1530.-Number-of-Good-Leaf-Nodes-Pairs

# 🌲 Count Good Leaf Node Pairs

## 📘 Problem Statement

Given the `root` of a binary tree and an integer `distance`, return the number of good leaf node pairs in the tree.

A pair of leaf nodes is considered *good* if:

* The length of the shortest path between them is less than or equal to `distance`.

---

## 🧠 Approach Explanation

1. 🔁 **Convert the Tree to an Undirected Graph**:

   * Use DFS to map each node to its neighbors (parent-child bidirectional mapping).
   * Collect all leaf nodes during the traversal.

2. 🔍 **BFS from Each Leaf**:

   * Perform BFS starting from each leaf node.
   * Track visited nodes and level (depth) to ensure we don’t go beyond the allowed distance.
   * Count the number of other leaf nodes encountered within this range.

3. ➗ **Avoid Double Counting**:

   * Each valid pair is counted twice (once from each node), so we divide the final count by 2.

---

## 🧪 Example

```
      1
     / \
    2   3
   /     \
  4       5

  Leaf Nodes: 4 and 5
  Distance: 3
  Path: 4 -> 2 -> 1 -> 3 -> 5 (length = 4) ❌
  So only include valid pairs within the given range.
```

---

## ⏱️ Time Complexity

* **O(N²)** in the worst case: BFS is done for each leaf node.

## 💾 Space Complexity

* **O(N)** for:

  * Storing graph connections (adjacency list)
  * Leaf node set
  * Visited sets during BFS

---

## 🧑‍💻 Author Info

**👨‍🎓 Ridham Garg**
🚀 B.Tech Computer Engineering, Thapar University, Patiala
📧 *[ridhamgarg@example.com](mailto:ridhamgarg@example.com)* (add your email here if you wish)

---

## 🎉 Made with ❤️ using C++ and DSA!
