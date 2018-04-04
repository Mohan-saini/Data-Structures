import java.util.*;
class Node
{
	int data;
	int bf,height;
	Node left,right;
	public Node(int value)
	{
		data=value;
		height=0;
	}
}
public class AVLtree
{
public static void update(Node root){
	int left_height=(root.left == null) ? -1 : root.left.height;
	int right_height=(root.right == null) ? -1 :root.right.height;
	root.height=1+Math.max(left_height,right_height);
	root.bf=(right_height-left_height);
}
public static Node left_left_rotation(Node root){
	return(right_rotation(root));
}
public static Node left_right_rotation(Node root){
	root.left=left_rotation(root.left);
	return(left_left_rotation(root));
}
public static Node right_right_rotation(Node root){
	return(left_rotation(root));
}
public static Node right_left_rotation(Node root){
	root.right=right_rotation(root.right);
	return(right_right_rotation(root));
}
public static Node left_rotation(Node root){
	Node new_parent=root.right;
	root.right=new_parent.left;
	new_parent.left=root;
	update(root);
	update(new_parent);
	return(new_parent);
}
public static Node right_rotation(Node root){
	Node new_parent=root.left;
	root.left=new_parent.right;
	new_parent.right=root;
	update(root);
	update(new_parent);
	return(new_parent);
}
public static Node balance(Node root){
	if(root.bf == -2){
		if(root.left.bf<=0)
			return left_left_rotation(root);
		else
			return left_right_rotation(root);
	}
	else if(root.bf == 2){
		if(root.right.bf>=0)
			return right_right_rotation(root);
		else
			return right_left_rotation(root);
	}
	return root;
}
public static Node insert(Node root,int data){
	if(root==null) return new Node(data);
	if(data>root.data){
		root.right=insert(root.right,data);
	}
	else
		root.left=insert(root.left,data);
	update(root);
	return(balance(root));
}
public static void inorder(Node root){
	if(root!=null){
		inorder(root.left);
	    System.out.println("Data= "+root.data+"  Height of this node= "+root.height+" it's balance factor= "+root.bf);
	    inorder(root.right);
	}
}
	public static void main(String []args)
	{
		Scanner sc=new Scanner(System.in);
		Node start=null;
		int arr[]=new int[5];
		for(int i=0;i<arr.length;i++){
			arr[i]=sc.nextInt();
		}
		for(int i=0;i<arr.length;i++){
			start=insert(start,arr[i]);
		}
		inorder(start);
	}
}