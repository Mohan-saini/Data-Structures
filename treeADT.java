import java.util.*;
class Node
{
	int data;
	Node left,right;
}
public class treeADT
{
	public static Node insert(Node root,int value)
	{
		Node par=new Node();
		par.data=value;
		par.left=null;par.right=null;
		if(root==null)
		{
			root=par;
		}
		else{
			Node n;
			n=root;
			while(n!=null){
				if(value>n.data){
					if(n.right==null){
						n.right=par;
						n=null;
					}
					else
					    n=n.right;
				}
				else if(value<n.data)
				{
					if(n.left==null){
						n.left=par;
						n=null;
					}
					else
						n=n.left;
				}
			}
	    }
	    return(root);
	}
	public static void preTraverse(Node root){
		if(root!=null){
			System.out.print(root.data+"  ");
			preTraverse(root.left);
			preTraverse(root.right);
		}
	}
	public static void postTraverse(Node root){
		if(root!=null){
			postTraverse(root.right);
			postTraverse(root.left);
			System.out.print(root.data+"  ");
		}
	}
	public static void inTraverse(Node root){
		if(root!=null){
			inTraverse(root.left);
			System.out.print(root.data+"  ");
			inTraverse(root.right);
		}
	}
	public static Node findMax(Node root){
		Node maxValueNode;
		if(root.right==null)
			maxValueNode=root;
		else{
			maxValueNode=findMax(root.right);
		}
		return(maxValueNode);
	}
	public static Node Delete(Node root,int data)
	{
		Node temp;
		if(root!=null){
			if(data>root.data)
				root.right=Delete(root.right,data);
			else if(data<root.data)
				root.left=Delete(root.left,data);
			else{//data has found
				if(root.left!=null && root.right!=null){
					temp=findMax(root.left);
					root.data=temp.data;
					root.left=Delete(root.left,root.data);
				}
				else{
					if(root.right==null)
						root=root.left;
					else if(root.left==null)
						root=root.right;
				}
			}
		}
		return(root);
	}
	static int getHeight(Node root){
          //Write your code here
            if(root==null)
                return(-1);
            int leftDepth=getHeight(root.left);
            int rightDepth=getHeight(root.right);
            return (leftDepth>rightDepth?leftDepth:rightDepth) +1;
        }

	public static void main(String []args)
	{
		Scanner sc=new Scanner(System.in);
		Node start=null;
		System.out.println("enter the number of values");
		int n=sc.nextInt();
		for(int i=0;i<n;i++){
			start=insert(start,sc.nextInt());
		}
		System.out.println("Pre-Traversal:");
		preTraverse(start);													//pre-traversal of tree
		System.out.println("\nPost-Traversal:");
		postTraverse(start);												//post-traversal of tree
		System.out.println("\nIn-order Traversal:");
		inTraverse(start);													//in order traversal of tree
		System.out.println("\nMaximum value of tree is "+findMax(start).data);//maximum value in tree
		System.out.println("enter the value you want to delete");
		start=Delete(start,sc.nextInt());									//Deletion in tree
		System.out.println("After deletion in order traversal of tree-");
		inTraverse(start);
		System.out.println("\nHeight of the tree is= "+getHeight(start));
	}
}