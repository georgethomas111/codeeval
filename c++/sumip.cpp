#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Sum {
   
   private:
      int x;
      int y;
      int sum;
      vector<int> ip;
   
   
   public:

      Sum(vector<int> ip) {
         this->ip = ip;
      }

      int get() {

          int sum = 0;
          for(int i = 0; i < this->ip.size(); i++) {
             sum += this->ip[i];
          }
          return sum;
      }
};

int main(int argc, char* argv[]) {


    ifstream stream(argv[1]);
    string line;
    vector<int> vect_inp;  
 
    while(getline(stream, line)) {
        vect_inp.push_back(stoi(line));
    }

    Sum* sum = new Sum(vect_inp);
    cout << sum->get() << endl;
    stream.close();
}
