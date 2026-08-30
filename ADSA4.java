//Search Key in a BST
class Node
{
	int key;
	Node left, right;
	public Node(int item)
	{
        	key = item;
        	left = right = null;
	}
}
class ADSA4
{
	Node root;
	public Node search(Node root, int key)
	{
        	Node current = root;
        	while (current != null)
		{
			if (key == current.key)
				return current;
			else if (key < current.key)
				current = current.left;
			else
				current = current.right;
        	}
		return null;
	}
	public static void main()
	{
		ADSA4 tree = new ADSA4();
		tree.root = new Node(50);
	        tree.root.left = new Node(30);
	        tree.root.right = new Node(70);
        	tree.root.left.left = new Node(20);
	        tree.root.left.right = new Node(40);
	        tree.root.right.left = new Node(60);
	        tree.root.right.right = new Node(80);

		int find = 60;
		Node r = tree.search(tree.root, find);
		if (r == null)
			System.out.println(find + " Not found in tree");
		else
			System.out.println(find + " Found in tree");
	}
}
