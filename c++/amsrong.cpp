/**
 * Amstrong : Each numbers digits are needed. 
 *        These digits need to be pit in a vector also 
 *        length is to be found
 *
 */ 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>

class Amstrong {
   private :
       int num; 

       int find_len() {

          int temp = this->num;
          int count = 0;
          while(temp != 0) {
             ++count;
             temp /= 10;
          }
          return count;
       }

   public :

       Amstrong(int arg_num) {
           this->num = arg_num;
       } 

       std::string is_amstrong() {
          int len = this->find_len();
          int temp = this->num;
          int sum = 0;
          while(temp != 0) {
             
             int digit = temp % 10;
             temp = temp / 10;
             sum += pow(digit, len);
          }
          if(sum == this->num) {
              return "True";
          } else {
              return "False";
          }

       }

};

int main(int argc, char *argv[]) {

   std::ifstream ipstream(argv[1]);
   std::string line;
   std::vector<int> ipvect;

   while(std::getline(ipstream, line)) {
        ipvect.push_back(atoi(line.c_str()));
   }
   
   for(int i=0; i < ipvect.size(); i++) {
       Amstrong *ams = new Amstrong(ipvect[i]);
       std::cout << ams->is_amstrong() << std::endl;
     
   }
   
   return 0;
}
