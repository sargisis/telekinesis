#include "../StackHeader/Stack.h"


using namespace g3;

int main(int argc, char const *argv[])
{
     stack<int> s = {1,2,3,4,5,6,7,8,9,10};
     stack<int> s1 = {1,2,3,4,5,6,7,11,12,34};

     s.push(55);
     std::cout << s.top();
     return 0;
}
