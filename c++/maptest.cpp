#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>


int main(int argc, char* argv[]) {
   
   std::ifstream stream(argv[1]);
   std::string line;
  
   while(std::getline(stream, line)) {
       std::set<std::string> lookup;
       std::string letter;
       std::istringstream str_stream(line);
       std::vector<std::string> str_vect;

       while(std::getline(str_stream, letter, ',')) {
           if(lookup.find(letter) == lookup.end()) {
              lookup.insert(letter); 
              str_vect.push_back(letter);
           } 
       }

       for(int i = 0; i < str_vect.size(); i++) {
          if(i != 0) {
              std::cout << ",";
          }
          std::cout << str_vect[i];
       }
       std::cout << std::endl;
   }
   return 0;
}
