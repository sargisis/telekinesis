#include "../ForwardHeader/ForwardList.h"

int main() {
    Forward_List<int> f = {1,2,3,4};
    Forward_List<int> f1 = {1,2,3,4,5,6};

    f.push_back(55);
    f.print();
   
    f.insert(2,555);
    f.print();
   
    f._swap(f1);
    f.print();
    f1.print();

    f.erase(1);
    f.print();
    
}