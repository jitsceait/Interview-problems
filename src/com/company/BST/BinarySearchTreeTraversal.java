package com.company.BST;

import java.util.Stack;

/**
 * Created by sangar on 22.5.18.
 */
public class BinarySearchTreeTraversal {

    private Node root;

    public void BinarySearchTree(){
        root = null;
    }

    public class Node {
        private int value;
        private Node left;
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
        public void postOrderTraversal(){
          //  postOrder(root);
            postOrderIterative2(root);
            //postOrderIterative(root);
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

    private void postOrderIterative2(Node root){
            Node prev = null;
            Stack<Node> s = new Stack<>();

            s.push(root);

            while(!s.empty()){
                Node current  = s.peek();
                if(prev == null || ( prev.left == current || prev.right == current )){
                    if(current.left != null) s.push(current.left);
                    else if(current.right != null) s.push(current.right);
                }
                else if(prev == current.left){
                    if(current.right != null) s.push(current.right);
                }else{
                    System.out.println(current.value);
                    s.pop();
                }

                prev = current;
            }
    }

}
