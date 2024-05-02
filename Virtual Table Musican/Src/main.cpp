#include "../Headers/VT.h"

int main() {
  Musician* ob = new Musician();
  Drummerist* db = Dynamic_cast<Drummerist>(ob);
  if (ob) {
   std::cout << "HI" << std::endl; 
  }else {
    std::cout << "Bye" << std::endl; 
  }
  leader(db);
}