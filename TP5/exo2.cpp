#include <QApplication>
#include <QString>
#include <time.h>
#include <stdio.h>
#include <string>

#include <tp5.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;


std::vector<string> TP5::names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});

unsigned long int hash(string key)
{
    // return an unique hash id from key

    int i = 0;
    int hashValue = 0;

    while(key[i] != '\0'){
        hashValue += (int)key[i]*pow(254, key.size()-1-i);
        i++;
    }

    return hashValue;
}

struct MapNode : public BinaryTree
{

    string key;
    unsigned long int key_hash;

    int value;

    MapNode* left;
    MapNode* right;

    MapNode(string key, int value) : BinaryTree (value)
    {
        this->key = key;
        this->value = value;
        this->key_hash = hash(key);

        this->left = this->right = nullptr;
    }

    /**
     * @brief insertNode insert a new node according to the key hash
     * @param node
     */
    void insertNode(MapNode* node)
    {
        if(node->key_hash > this->key_hash){
            if(this->right == nullptr){
                this->right = node;
            }
            else{
                this->right->insertNode(node);
            }
        }
        else{
            if(this->left == nullptr){
                this->left = node;
            }
            else{
                this->left->insertNode(node);
            }
        }


    }

    void insertNode(string key, int value)
    {
        this->insertNode(new MapNode(key, value));
    }

    virtual ~MapNode() {}
    QString toString() const override {return QString("%1:\n%2").arg(QString::fromStdString(key)).arg(value);}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

struct Map
{
    Map() {
        this->root = nullptr;
    }

    /**
     * @brief insert create a node and insert it to the map
     * @param key
     * @param value
     */
    void insert(string key, int value)
    {
        if(this->root == nullptr){
            this->root = new MapNode(key, value);
        }
        else{
            this->root->insertNode(key, value);
        }

    }

    /**
     * @brief get return the value of the node corresponding to key
     * @param key
     * @return
     */
    int get(string key)
    {
        MapNode* currentNode = this->root;
        unsigned long int hashKey = hash(key);

        while(currentNode != nullptr && currentNode->key_hash != hashKey){
            if(hashKey > currentNode->key_hash){
                currentNode = currentNode->right;
            }
            else if (hashKey < currentNode->key_hash){
                currentNode = currentNode->left;
            }
        }

        if(currentNode != nullptr){
            return currentNode->value;
        }
        else{
            return 0;
        }

    }

    MapNode* root;
};


int main(int argc, char *argv[])
{
    srand(time(NULL));
    Map map;

    map.insert("Yolo", 20);
    for (std::string& name : TP5::names)
    {
        if (rand() % 3 == 0)
        {
            map.insert(name, rand() % 21);
        }
    }

    printf("map[\"Margot\"]=%d\n", map.get("Margot"));
    printf("map[\"Jolan\"]=%d\n", map.get("Jolan"));
    printf("map[\"Lucas\"]=%d\n", map.get("Lucas"));
    printf("map[\"Clemence\"]=%d\n", map.get("Clemence"));
    printf("map[\"Yolo\"]=%d\n", map.get("Yolo"));
    printf("map[\"Tanguy\"]=%d\n", map.get("Tanguy"));


    QApplication a(argc, argv);
    MainWindow::instruction_duration = 200;
    w = new MapWindow(*map.root);
    w->show();
    return a.exec();
}
