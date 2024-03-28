#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<int> st; 
        for(char characters : s ){
            if (characters == '[' || characters == '{' || characters == '('){
                st.push(characters);
            }else {
                if (st.empty() ||
                   characters == '}' && st.top() !=  '{' ||
                   characters == ']' && st.top() !=  '[' || 
                   characters == ')' && st.top() !=  '(' ){
                    return false; 
                   }else {
                    st.pop();
                }
            }
        }
          return  st.empty();
    }
    
};