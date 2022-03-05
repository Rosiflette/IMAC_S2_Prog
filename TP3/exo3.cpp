#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>
#include <time.h>
#include <stack>
#include <queue>

MainWindow* w = nullptr;
using std::size_t;

struct BinarySearchTree : public BinaryTree
{    
    Node* left;
    Node* right;
    int value;

    void initNode(int value)
    {
        // init initial node without children
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;

    }

	void insertNumber(int value) {
        // create a new node and insert it in right or left child
        if(this->get_value() == 0){
            this->initNode(value);
        }
        else {
            if(value < this->get_value()){
                if(this->get_left_child() == nullptr){
                    this->left = createNode(value);
                }
                else{
                    this->get_left_child()->insertNumber(value);
                }
            }
            else{
                if(this->get_right_child() == nullptr){
                    this->right = createNode(value);
                }
                else{
                    this->get_right_child()->insertNumber(value);
                }
            }
        }
    }

	uint height() const	{
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1

        uint l, r;
        if(this->get_left_child() == nullptr){
            l = 0;
        }
        else{
            l = this->get_left_child()->height();
        }

        if(this->get_right_child() == nullptr){
            r = 0;
        }
        else{
            r = this->get_right_child()->height();
        }


        uint h;
        if(l > r){
            h = 1 + l;
        }
        else{
            h = 1 + r;
        }
        return h;
    }

	uint nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        uint l, r;
        if(this->get_left_child() == nullptr){
            l = 0;
        }
        else{
            l = this->left->nodesCount();
        }

        if(this->get_right_child() == nullptr){
            r = 0;
        }
        else{
            r = this->right->nodesCount();
        }


        return l+r+1;
	}

	bool isLeaf() const {
        // return True if the node is a leaf (it has no children)
        if(this->left == nullptr && this->right == nullptr)
            return true;
        else
            return false;
	}

	void allLeaves(Node* leaves[], uint& leavesCount) {
        // fill leaves array with all leaves of this tree

        if(this->get_left_child() != nullptr){
            this->get_left_child()->allLeaves(leaves, leavesCount);
        }
        if(this->isLeaf()){
            leaves[leavesCount] = this;
            leavesCount++;
        }

        if(this->get_right_child() != nullptr){
            this->get_right_child()->allLeaves(leaves, leavesCount);
        }


	}

	void inorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with inorder travel
        if(this->get_left_child() != nullptr){
            this->get_left_child()->inorderTravel(nodes, nodesCount);
        }
        nodes[nodesCount] = this;
        nodesCount++;
        if(this->get_right_child() != nullptr){
            this->get_right_child()->inorderTravel(nodes, nodesCount);
        }
	}

    void preorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with preorder travel
        nodes[nodesCount] = this;
        nodesCount++;
        if(this->get_left_child() != nullptr){
            this->get_left_child()->preorderTravel(nodes, nodesCount);
        }
        if(this->get_right_child() != nullptr){
            this->get_right_child()->preorderTravel(nodes, nodesCount);
        }
	}

	void postorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with postorder travel
        if(this->get_left_child() != nullptr){
            this->get_left_child()->postorderTravel(nodes, nodesCount);
        }
        if(this->get_right_child() != nullptr){
            this->get_right_child()->postorderTravel(nodes, nodesCount);
        }
        nodes[nodesCount] = this;
        nodesCount++;
	}

	Node* find(int value) {
        // find the node containing value
        if(this->get_value() == value){
            return this;
        }
        else if(this->get_left_child() != nullptr){
            return this->get_left_child()->find(value);
        }
        else if(this->get_right_child() != nullptr){
            return this->get_right_child()->find(value);
        }
	}

    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }

    BinarySearchTree(int value) : BinaryTree(value) {initNode(value);}
    ~BinarySearchTree() {}
    int get_value() const {return value;}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new BinarySearchTree(value);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<BinarySearchTree>();
	w->show();

	return a.exec();
}
