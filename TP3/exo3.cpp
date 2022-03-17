#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>
#include <time.h>
#include <stack>
#include <queue>

MainWindow* w = nullptr;
using std::size_t;

struct SearchTreeNode : public Node
{
    SearchTreeNode* left;
    SearchTreeNode* right;
    int value;

    SearchTreeNode* createNodeS(int value) {
        return new SearchTreeNode(value);
    }

    void initNode(int value)
    {
        // init initial node without children
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
    void rotateRight(){
        SearchTreeNode* newRoot = this->left;
        this->left = newRoot->right;
        newRoot->right = this;
    }

    void rotateLeft(){
        SearchTreeNode* newRoot = this->right;
        this->right = newRoot->left;
        newRoot->left = this;
    }


    void avlInsert(int value){ // essayé mais ne marche pas

            if(this->get_value() == 0){
                this->initNode(value);
            }
            if(value <= this->value){
                if(this->left != nullptr){
                    this->left->avlInsert(value);
                }
                else{
                    this->left = createNodeS(value);
                }
            }
            else{
                if(this->right != nullptr){
                    this->right->avlInsert(value);
                }
                else{
                    this->right = createNodeS(value);
                }
            }


            int balance;
            if(this->left == nullptr){
                balance = 0;
            }
            else{
                balance = this->left->height();
            }
            if(this->right != nullptr){
                balance -= this->right->height();
            }

            if(balance >1){
                int balanceEnf;
                if(this->left->left == nullptr){
                    balanceEnf = 0;
                }
                else{
                    balanceEnf = this->left->left->height();
                }
                if(this->left->right != nullptr){
                    balanceEnf -= this->left->right->height();
                }

                if(balanceEnf >= 1){
                    return this->rotateRight();
                }
                else{
                    this->left->rotateLeft();
                    return this->rotateRight();
                }

            }
            if(balance < -1){
                int balanceEnf;
                if(this->right->left == nullptr){
                    balanceEnf = 0;
                }
                else{
                    balanceEnf = this->right->left->height();
                }
                if(this->right->right != nullptr){
                    balanceEnf -= this->right->right->height();
                }
                if(balanceEnf >= 1){
                    return this->rotateLeft();
                }
                else{
                    this->right->rotateRight();
                    return this->rotateLeft();
                }

            }
        }


    void insertNumber(int value) {
        // create a new node and insert it in right or left child
        if(this->get_value() == 0){
            this->initNode(value);
        }
        else {
            if(value < this->get_value()){
                if(this->get_left_child() == nullptr){
                    this->left = createNodeS(value);
                }
                else{
                    this->get_left_child()->insertNumber(value);
                }
            }
            else{
                if(this->get_right_child() == nullptr){
                    this->right = createNodeS(value);
                }
                else{
                    this->get_right_child()->insertNumber(value);
                }
            }
        }
        //avlInsert(value);
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
        else if(this->get_value() > value && this->get_left_child()!= nullptr){
            this->get_left_child()->find(value);
        }
        else if(this->get_value() < value && this->get_right_child()!= nullptr){
            this->get_right_child()->find(value);
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

    SearchTreeNode(int value) : Node(value) {initNode(value);}
    ~SearchTreeNode() {}
    int get_value() const {return value;}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new SearchTreeNode(value);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<SearchTreeNode>();
	w->show();

	return a.exec();
}
