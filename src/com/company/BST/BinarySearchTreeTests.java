package com.company.BST;

/**
 * Created by sangar on 10.5.18.
 */
public class BinarySearchTreeTests {
    public static void main (String[] args){
        BinarySearchTreeTraversal binarySearchTree = new BinarySearchTreeTraversal();

        binarySearchTree.insert(7);
        binarySearchTree.insert(8);
        binarySearchTree.insert(6);
        binarySearchTree.insert(9);
        binarySearchTree.insert(3);
        binarySearchTree.insert(4);

        binarySearchTree.postOrderTraversal();
    }
}
