#include <iostream>

namespace RedBlackTree {

#define BLACK 1
#define RED 0

	using namespace std;

	class bst {
	private:

		struct Node {
			int value;
			bool color;
			Node* leftChild, * rightChild, * parent;

			Node() : value(0), color(RED), leftChild(NULL), rightChild(NULL), parent(NULL) { }

			Node* grandparent() {
				if (parent == NULL) {
					return NULL;
				}
				return parent->parent;
			}

			Node* uncle() {
				if (grandparent() == NULL) {
					return NULL;
				}
				if (parent == grandparent()->rightChild)
					return grandparent()->leftChild;
				else
					return grandparent()->rightChild;
			}

			Node* sibling() {
				if (parent->leftChild == this)
					return parent->rightChild;
				else
					return parent->leftChild;
			}
		};

		// 右转
		void rotate_right(Node* x) {
			Node* gp = x->grandparent();
			Node* p = x->parent;
			Node* rChild = x->rightChild;

			p->leftChild = rChild;
			if (rChild != NIL)
				rChild->parent = p;

			x->rightChild = p;
			p->parent = x;

			if (root == p)
				root = x;
			x->parent = gp;

			if (gp != NULL) {
				if (gp->leftChild == p)
					gp->leftChild = x;
				else
					gp->rightChild = x;
			}
		}

		// 左转
		void rotate_left(Node* x) {
			if (x->parent == NULL) {
				root = x;
				return;
			}
			Node* gp = x->grandparent();
			Node* p = x->parent;
			Node* lChild = x->leftChild;

			p->rightChild = lChild;
			if (lChild != NIL)
				lChild->parent = p;

			x->leftChild = p;
			p->parent = x;

			if (root == p)
				root = x;
			x->parent = gp;

			if (gp != NULL) {
				if (gp->leftChild == p)
					gp->leftChild = x;
				else
					gp->rightChild = x;
			}
		}

		// 中序遍历，左->父->右
		void inorder(Node* p) {
			if (p == NIL)
				return;

			if (p->leftChild)
				inorder(p->leftChild);

			cout << p->value << (p->color == RED? "red" : "black") << "  ";

			if (p->rightChild)
				inorder(p->rightChild);
		}
		// 输出颜色
		string outputColor(bool color) {
			return color ? "BLACK" : "RED";
		}
		// 递归，找到当前树的最左节点
		Node* getSmallestChild(Node* p) {
			if (p->leftChild == NIL)
				return p;
			return getSmallestChild(p->leftChild);
		}
		// 二叉查找树，查询到后，做删除
		bool delete_child(Node* p, int data) {
			if (p->value > data) {
				if (p->leftChild == NIL) {
					return false;
				}
				return delete_child(p->leftChild, data);
			}
			else if (p->value < data) {
				if (p->rightChild == NIL) {
					return false;
				}
				return delete_child(p->rightChild, data);
			}
			else if (p->value == data) {
				// 找到对应的节点p
				// 通过二叉查找书的方式，将调整放到叶子节点临近位置
				if (p->rightChild == NIL) {
					delete_one_child(p);
					return true;
				}
				Node* smallest = getSmallestChild(p->rightChild);
				swap(p->value, smallest->value);
				delete_one_child(smallest);

				return true;
			}
			else {
				return false;
			}
		}
		// 删除一个节点
		void delete_one_child(Node* d) {
			if (d->parent == NULL && d->leftChild == NIL && d->rightChild == NIL) {
				// 当前是节点是root，且无child，直接删除
				d = NULL;
				root = d;
				return;
			}

			Node* child = d->leftChild == NIL ? d->rightChild : d->leftChild;	// 
			if (d->parent == NULL) {
				// 当前是节点是root，有child
				delete  d;
				child->parent = NULL;
				root = child;
				root->color = BLACK;
				return;
			}

			// 链接 parent和child
			if (d->parent->leftChild == d) {
				d->parent->leftChild = child;
			}
			else {
				d->parent->rightChild = child;
			}
			child->parent = d->parent;

			if (d->color == BLACK) {
				if (child->color == RED) {
					// 删除节点是黑色，child为红色
					child->color = BLACK;
				}
				else
					// 删除节点是黑色，child为黑色
					delete_case(child);
			}
			delete d;
		}
		// 处理删除后的变色和旋转
		void delete_case(Node* d) {
			if (d->parent == NULL) {
				d->color = BLACK;
				return;
			}

			if (d->sibling()->color == RED) {
				d->parent->color = RED;
				d->sibling()->color = BLACK;
				if (d == d->parent->leftChild)
					rotate_left(d->sibling());
				else
					rotate_right(d->sibling());
			}

			if (d->parent->color == BLACK && d->sibling()->color == BLACK
				&& d->sibling()->leftChild->color == BLACK && d->sibling()->rightChild->color == BLACK) {
				d->sibling()->color = RED;
				delete_case(d->parent);
			}
			else if (d->parent->color == RED && d->sibling()->color == BLACK
				&& d->sibling()->leftChild->color == BLACK && d->sibling()->rightChild->color == BLACK) {
				d->sibling()->color = RED;
				d->parent->color = BLACK;
			}
			else {
				if (d->sibling()->color == BLACK) {
					if (d == d->parent->leftChild && d->sibling()->leftChild->color == RED
						&& d->sibling()->rightChild->color == BLACK) {
						d->sibling()->color = RED;
						d->sibling()->leftChild->color = BLACK;
						rotate_right(d->sibling()->leftChild);
					}
					else if (d == d->parent->rightChild && d->sibling()->leftChild->color == BLACK
						&& d->sibling()->rightChild->color == RED) {
						d->sibling()->color = RED;
						d->sibling()->rightChild->color = BLACK;
						rotate_left(d->sibling()->rightChild);
					}
				}
				d->sibling()->color = d->parent->color;
				d->parent->color = BLACK;
				if (d == d->parent->leftChild) {
					d->sibling()->rightChild->color = BLACK;
					rotate_left(d->sibling());
				}
				else {
					d->sibling()->leftChild->color = BLACK;
					rotate_right(d->sibling());
				}
			}
		}
		// 插入 ： 二叉搜索树的查找 + 创建Node
		void insert(Node* p, int data) {
			if (p->value >= data) {
				if (p->leftChild != NIL)
					insert(p->leftChild, data);
				else {
					Node* tmp = new Node();
					tmp->value = data;
					tmp->leftChild = tmp->rightChild = NIL;
					tmp->parent = p;
					p->leftChild = tmp;
					insert_case(tmp);
				}
			}
			else {
				if (p->rightChild != NIL)
					insert(p->rightChild, data);
				else {
					Node* tmp = new Node();
					tmp->value = data;
					tmp->leftChild = tmp->rightChild = NIL;
					tmp->parent = p;
					p->rightChild = tmp;
					insert_case(tmp);
				}
			}
		}
		// 插入： 处理 变色和转换
		void insert_case(Node* x) {
			if (x->parent == NULL) {
				// x 为根节点，直接设置为黑色
				root = x;
				x->color = BLACK;
				return;
			}
			if (x->parent->color == RED) {
				if (x->uncle()->color == RED) {
					// x 为的Parent为红，且uncle为红；变色后做递归
					x->parent->color = x->uncle()->color = BLACK;
					x->grandparent()->color = RED;
					insert_case(x->grandparent());
				}
				else {
					//  x 的 parent 为红，同时 uncle是黑色
					if (x->parent->rightChild == x && x->grandparent()->leftChild == x->parent) {
						// LR，做先x节点左旋，再右旋，变色
						rotate_left(x);
						rotate_right(x);
						x->color = BLACK;
						x->leftChild->color = x->rightChild->color = RED;
					}
					else if (x->parent->leftChild == x && x->grandparent()->rightChild == x->parent) {
						// RL，先X节点右旋，再左旋，变色
						rotate_right(x);
						rotate_left(x);
						x->color = BLACK;
						x->leftChild->color = x->rightChild->color = RED;
					}
					else if (x->parent->leftChild == x && x->grandparent()->leftChild == x->parent) {
						// LL，Parent节点右旋，变色
						x->parent->color = BLACK;
						x->grandparent()->color = RED;
						rotate_right(x->parent);
					}
					else if (x->parent->rightChild == x && x->grandparent()->rightChild == x->parent) {
						// RR，Parent节点左旋，变色
						x->parent->color = BLACK;
						x->grandparent()->color = RED;
						rotate_left(x->parent);
					}
				}
			}
		}
		// 删除树
		void DeleteTree(Node* p) {
			if (!p || p == NIL) {
				return;
			}
			DeleteTree(p->leftChild);
			DeleteTree(p->rightChild);
			delete p;
		}

	public:

		bst() {
			NIL = new Node();
			NIL->color = BLACK;
			root = NULL;
		}

		~bst() {
			if (root)
				DeleteTree(root);
			delete NIL;
		}

		void inorder() {
			if (root == NULL)
				return;
			inorder(root);
			cout << endl;
		}

		void insert(int x) {
			if (root == NULL) {
				root = new Node();
				root->color = BLACK;
				root->leftChild = root->rightChild = NIL;
				root->value = x;
			}
			else {
				insert(root, x);
			}
		}

		bool delete_value(int data) {
			return delete_child(root, data);
		}
	private:
		Node* root, * NIL;
	};

	int test()
	{
		cout << "---【红黑树】---" << endl;
		// 创建红黑树
		bst tree;

		// 顺序打印红黑树
		cout << "插入元素后的红黑树：" << endl;
		// 插入元素
		tree.insert(2);
		tree.inorder();
		tree.insert(1);
		tree.inorder();
		tree.insert(3);
		tree.inorder();
		tree.insert(4);
		tree.inorder();
		tree.insert(5);
		tree.inorder();
		tree.insert(6);
		tree.inorder();
		tree.insert(7);
		tree.inorder();
		tree.insert(8);
		tree.inorder();

		// 删除元素
		tree.delete_value(2);

		// 顺序打印红黑树
		cout << "删除元素 2 后的红黑树：" << endl;
		tree.inorder();

		// 析构
		tree.~bst();

		getchar();
		return 0;
	}
}