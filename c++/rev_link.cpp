/**
 * Reverse group of a list
 * Eg. 
 * 1,2,3,4,5;2
 * 1,2,3,4,5;3
 *
 * Op
 * -- 
 * 2,1,4,3,5
 * 3,2,1,4,5
 */

// 1234
// 4321

// 12345 678910
// 54321 109876

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class List {

  //  Node *head;
    int group_start;
    int group_end;
    int next_group_start;
    int group_size;

    std::vector<int> values;

    void set_index_pointers(int start) {

        int max_index = values.size() - 1;
       
        if(max_index - start > (group_size - 1)) { //This is because 0 - 4 is 5 elements
            this->group_start = start;
            this->group_end = this->group_start + this->group_size - 1;
            this->next_group_start = this->group_end + 1;
        } else {
            this->group_start = start;
            this->group_end = max_index;
            this->next_group_start = -1;
        }
    }

    void swap() {
       int temp = this->values[group_start];
       this->values[group_start] = this->values[group_end];
       this->values[group_end] = temp;
    }
 
    public:

    List(std::vector<int> values, int count) {
        this->values = values;
        this->group_size = count;
        this->set_index_pointers(0);
    }
  
    // Expect pointers to be set.
    void reverse_list() {
        
        if(this->next_group_start == -1) {
            // Dealing with last group, return.
            return;
        }

        // Reverse part
        while(this->group_start < this->group_end) {
           swap();
           group_start++;
           group_end--;
        }

        // This can be parallelized if appropriate input is given. 
        if(this->next_group_start != -1) {
            set_index_pointers(this->next_group_start);
            reverse_list();
        }
    }
 
    std::vector<int> get_list() {
        return this->values;
    }
};

void print_vector(std::vector<int> elems) {

   int index;
   for(index=0; index < elems.size() - 1; index++) {
       std::cout << elems[index] << ",";
   }
   std::cout << elems[index] << std::endl;
}

std::vector<std::string> split(const std::string &line, char delim) {

   std::istringstream line_stream(line);
   std::string item;
   std::vector<std::string> split_comp;
   while(std::getline(line_stream, item, delim)) {
        split_comp.push_back(item);
   }
   return split_comp;
}

// Task is to di

// * 1,2,3,4,5;2
// stream which gets a line. 
    // string stream which splits the line into two. 
       // part 1 string stream which splits by ,

int main(int argc, char*argv[]) {

   std::ifstream stream(argv[1]);
   std::string line;

   while(std::getline(stream, line)) {

      std::vector<std::string> split_comp = split(line, ';');
      int count = stoi(split_comp[1]);

      std::vector<std::string> inputs = split(split_comp[0], ',');
      std::vector<int> iplist;
      for(int index = 0; index < inputs.size(); ++index) {
         iplist.push_back(stoi(inputs[index]));
      }

      List* rev_list = new List(iplist, count);
      rev_list->reverse_list();
      std::vector<int> rev = rev_list->get_list();

      print_vector(rev);
   } 
}
