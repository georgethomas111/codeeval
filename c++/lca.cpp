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

#include "tree.h"

// Try out of copy constructor to copy Tree object to LCATree.
// root is ancestor for all elements if elements are present. 

// lca is the straight parent if it is present.
  

// find operation. Its the path upto which the find follows the 
// same path.

// elem1, elem2
// root -> left -> right

class LCATree : public Tree {

    public :
    
    Node* find_ans(Node* parent, Node* curr_ans, int elem1, int elem2) {

        if(elem1 == curr_ans->get_value() || elem2 == curr_ans->get_value()) {
            return parent;
        }

        else if (elem1 < curr_ans->get_value() && elem2 < curr_ans->get_value()) {
            return find_ans(curr_ans, curr_ans->get_left(), elem1, elem2);
        } else if(elem1 > curr_ans->get_value() && elem2 > curr_ans->get_value()) {
            return find_ans(curr_ans, curr_ans->get_right(), elem1, elem2);
        } else {
            return curr_ans;
        }
    }

    int get_lca(int elem1, int elem2) {

        if (elem1 == elem2) {
            return 0;
        }       
        Node *val = this->find_ans(this->root, this->root, elem1, elem2);
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
  
   std::cout << std::endl; 
   std::cout << "Extra tests 8 29" << std::endl << my_tree->get_lca(8, 29) << std::endl;
   std::cout << "Extra tests 3 52" << std::endl << my_tree->get_lca(3, 52) << std::endl;
   std::cout << "Extra tests 10 52" << std::endl << my_tree->get_lca(10, 52) << std::endl;
}
