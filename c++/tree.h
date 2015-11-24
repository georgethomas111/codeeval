#include <vector>

class Node {
      
   int value;
   Node *left;
   Node *right;
   
   public:

   Node(int elem=0) {
       this->value = elem;
       this->left = NULL;
       this->right = NULL;
   }

   void set_left(Node *left) {
       this->left = left;
   }
 
   void set_right(Node *right) {
       this->right = right;
   }  

   Node* get_right() {
       return this->right;
   }

   Node* get_left() {
       return this->left;
   }
  
   int get_value() {
       return value; 
   }

   int set_value(int value) {
       this->value = value;
   }
};

class Tree {

   protected:
   
   Node *root;

   void add_node(Node *parent, Node *new_elem) {
            if(new_elem != NULL) {
                 if(new_elem->get_value() < parent-> get_value()) {
                     if(parent->get_left() == NULL) {
                         parent->set_left(new_elem);
                     } else {
                         this->add_node(parent->get_left(), new_elem);
		     }
                 } else {
                     if(parent->get_right() == NULL) {
                         parent->set_right(new_elem);
                     } else {
                         this->add_node(parent->get_right(), new_elem);
		     }
                 }
            }
   }

   void inorder(std::vector<int> &traverse_list, Node *node) {
       if(node == NULL) {
           return;
       } else {
          inorder(traverse_list, node->get_left());
          traverse_list.push_back(node->get_value());
          inorder(traverse_list, node->get_right());
       }
   }   

   public:

   Tree() {
       this->root = NULL;
   }

   void add_node(Node *new_elem) {
      
      if(this->root == NULL) {
         this->root = new_elem;
      } else {
         this->add_node(this->root, new_elem);     
      }
   }

   std::vector<int> inorder() {
      std::vector<int> traverse_list;
      inorder(traverse_list, this->root); 
      return traverse_list;
   }
 
   void add_elem(std::vector<int> inputs) {
      for(int i = 0; i < inputs.size(); i++) {
          Node* node = new Node();
          node->set_value(inputs[i]);
          add_node(node);
      }
   }
};
