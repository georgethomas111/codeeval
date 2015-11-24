/**
 * Find lowest common ancestor of a tree
 * 
 *
 */

// TODO : Form tree - done
   // Least Common Acestor 

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

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

// Try out of copy constructor to copy Tree object to LCATree.
// root is ancestor for all elements if elements are present. 

// lca is the straight parent if it is present.
  

// find operation. Its the path upto which the find follows the 
// same path.

// elem1, elem2
// root -> left -> right

class LCATree : public Tree {

    public :
    
    Node* find_ans(Node* curr_ans, int elem1, int elem2) {
 
        if (elem1 <= curr_ans->get_value() && elem2 <= curr_ans->get_value()) {
            return find_ans(curr_ans->get_left(), elem1, elem2);
        } else if(elem1 > curr_ans->get_value() && elem2 > curr_ans->get_value()) {
            return find_ans(curr_ans->get_right(), elem1, elem2);
        } else {
           return curr_ans;
        }
    }

    int get_lca(int elem1, int elem2) {

        if (elem1 == elem2) {
            return 0;
        }       
        Node *val = this->find_ans(this->root, elem1, elem2);
        return val->get_value();
    }
};

void print_vector(std::vector<int> elems) {

   int index;
   for(index=0; index < elems.size(); index++) {
       std::cout << elems[index] << ",";
   }
   std::cout << std::endl;
}

int main(int argc, char* argv[]) {

   std::vector<int> inputs = {30,8,52,3,20,10,29};
   LCATree* my_tree = new LCATree();
   my_tree->add_elem(inputs);   

   std::ifstream my_stream(argv[1]);
   std::string line;
   while(std::getline(my_stream, line)) {
       int num1, num2;
       std::istringstream string_stream(line); 
       string_stream >> num1;
       string_stream >> num2;
       std::cout<< my_tree->get_lca(num1, num2) << std::endl;
   }
}
