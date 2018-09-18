package com.company.BST;

import java.util.ArrayList;
import java.util.Stack;

/**
 * Created by sangar on 10.5.18.
 */
public class BinarySearchTree {

    private Node root;

    public void BinarySearchTree(){
        root = null;
    }

    public class Node {
        private int value;
        private  Node left;
        private Node right;

        public Node(int value) {
            this.value = value;
            this.left = null;
            this.right = null;
        }
    }

    public void insert(int value){
        this.root =  insertNode(this.root, value);
    }

    public void insertIterative(int value){
        if(this.root == null){
            this.root  = new Node(value);
        }
        else{
            Node currentNode = root;
            Node parent = null;
            while(currentNode != null){
                parent = currentNode;
                if(currentNode.value > value) {
                    currentNode = currentNode.left;
                }
                else{
                    currentNode = currentNode.right;
                }
            }

            //Parent cannot be null here
            if(parent.value > value){
                parent.left = new Node(value);
            }
            else {
                parent.right = new Node(value);
            }
        }
    }

    private Node insertNode(Node root, int value){
        if(root == null){
            //if this node is root of tree
            root = new Node(value);
        }
        else{
            if(root.value > value){
                //If root is greater than value, node should be added to left subtree
                root.left = insertNode(root.left, value);
            }
            else{
                //If root is less than value, node should be added to right subtree
                root.right = insertNode(root.right, value);
            }
        }
        return root;
    }

    public void printPath(){
        ArrayList<Node> path  = new ArrayList<>();
        this.printPathRecursive(this.root, path);
    }

    private void printPathRecursive(Node root, ArrayList<Node> path){
        if(root == null) return;

        path.add(root);

        //If node is leaf node
        if(root.left == null && root.right == null){
            path.forEach(node -> System.out.print(" " + node.value));
            path.remove(path.size()-1);
            System.out.println();
            return;
        }

        //Not a leaf node, add this node to path and continue traverse

        printPathRecursive(root.left,path);
        printPathRecursive(root.right, path);

        path.remove(path.size()-1);

    }

    private void pathWithGivenPath(Node root, int sum, ArrayList<Node> path){
        if(root == null)
            return;

        if(sum < 0) return;

        int subSum = sum - root.value;
        path.add(root);

        boolean isLeaf = ( root.left == null && root.right == null );
        if(isLeaf && subSum == 0){
            path.forEach(node -> System.out.print(" " + node.value));
            System.out.println();
        }
        pathWithGivenPath(root.left, subSum, path);
        pathWithGivenPath(root.right, subSum, path);

        path.remove(path.size()-1);
    }

    public void printPathWithGivenPath(int sum){
        ArrayList<Node> path = new ArrayList<>();
        pathWithGivenPath(this.root, sum, path);
    }

    private void inorder(Node root){
        if(root == null) return;

        if(root.left != null) inorder(root.left);
        System.out.println(root.value);
        if(root.right != null) inorder(root.right);
    }

    private void preOrder(Node root){
        if(root == null) return;

        System.out.println(root.value);
        preOrder(root.left);
        preOrder(root.right);
    }

    private void postOrder(Node root){
        if(root == null) return;

        postOrder(root.left);
        postOrder(root.right);
        System.out.println(root.value);

    }

    private void postOrderIterative(Node root){
        Stack<Node> out = new Stack<>();
        Stack<Node> s = new Stack<>();

        s.push(root);

        while(!s.empty()){
            Node current = s.pop();

            out.push(current);
            if(current.left != null) s.push(current.left);
            if(current.right != null) s.push(current.right);
        }

        while(!out.empty()){
            System.out.println(out.pop().value);
        }
    }

    private boolean searchRecursive(Node root, int value){
        if(root == null) return false;

        if(root.value == value) return true;
        if(root.value > value ) return searchRecursive(root.left, value);
        if(root.value < value ) return searchRecursive(root.right, value);

        return false;
    }


    public boolean search(int value){
        return this.searchRecursive(this.root, value);
    }
    private int replaceSumRecursive(Node root){
        if (root == null)
            return 0;
        //Get left subtree sum
        int leftSum =  replaceSumRecursive(root.left);
        //Get right subtree sum
        int rightSum = replaceSumRecursive(root.right);
        /*This is to avoid replacing eaft node with 0 sum,
          which will eventually lead to entire tree being zero
          Keep in mind that bst no more bst it becomes binary tree.
         */
        if(leftSum + rightSum != 0){
            root.value += leftSum + rightSum;
        }
        return root.value;
    }

    public void replaceSum(){
        if(this.root == null) return;
        this.root.value = this.replaceSumRecursive(this.root);
    }

    public int sumAll(Node root) {
        if(root == null) return 0;
        return root.value + sumAll(root.left) + sumAll(root.right);
    }

    void replaceWithSumOfGreaterNodesUtil(Node root, int total)
    {
        if(root == null) return;

        int leftSum = sumAll(root.left);
        root.value = (total - leftSum - root.value);

        replaceWithSumOfGreaterNodesUtil(root.left, total);
        replaceWithSumOfGreaterNodesUtil(root.right, total);
    }

    public void replaceWithSumOfGreaterNodes(){
        int totalSum = sumAll(this.root);
        replaceWithSumOfGreaterNodesUtil(root, totalSum);
    }

    public void inorderTraversal(){
        inorder(this.root);
    }

    public boolean hasPathwithGivenSum(int sum){
        return this.hasPathWithSum(this.root, sum);
    }

    private boolean hasPathWithSum(Node root, int sum){
        boolean leftPath, rightPath;

        if(root == null) return sum == 0;

        int subSum =  sum - root.value;

        if(root.left == null || root.right == null)//If node is leaf node.
            return subSum == 0;

        leftPath = hasPathWithSum(root.left, subSum);
        rightPath = hasPathWithSum(root.right, subSum);

        return rightPath || leftPath;
    }

    public void delete(){
        deleteRecusrive(this.root);
        this.root = null;
    }
    private void deleteRecusrive(Node root){
        if(root == null) return;

        //delete left subtree
        deleteRecusrive(root.left);
        //delete right subtree
        deleteRecusrive(root.right);

        //delete the root, which will be collected by GC
        root.left = null;
        root.right = null;
    }

    public void mirror(){
        mirrorRecusrive(this.root);
    }
    private void mirrorRecusrive(Node root){
        if(root == null) return;

        //mirror left subtree
        mirrorRecusrive(root.left);
        //mirror right subtree
        mirrorRecusrive(root.right);

        //swap left and right child
        Node temp = root.left;
        root.left = root.right;
        root.right = temp;
    }
    public void replaceWithSumOfChildren(){
        replaceWithSumOfChildrenRecursive(this.root);
    }
    private int replaceWithSumOfChildrenRecursive(Node root){
        if(root == null) return 0;

        boolean isLeaf = ( root.left == null && root.right == null);

        if(isLeaf) return root.value;

        //process left subtree
        int leftSum = replaceWithSumOfChildrenRecursive(root.left);
        //process right subtree
        int rightSum = replaceWithSumOfChildrenRecursive(root.right);

        root.value += leftSum + rightSum;

        return root.value;
    }
}
