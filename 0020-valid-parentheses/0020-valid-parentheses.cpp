class Solution {
public:
    bool isValid(string s) {
        vector <char> stack;
        for (int i=0; i<s.size(); i++){
            char current_word = s[i];
            if(current_word == '(' || current_word == '[' || current_word == '{'){
                stack.push_back(current_word);
            }
            else if(stack.size() == 0){
                return false;
            }
            else if(parentheses_check(current_word, stack.back())){
                stack.pop_back();
            }
            else return false;
            
        }
        return (stack.size() == 0)? true:false; 
    }

    bool parentheses_check(char current_word, char stack_word){
        if(current_word == ')' && stack_word == '(') return 1;
        if(current_word == ']' && stack_word == '[') return 1;
        if(current_word == '}' && stack_word == '{') return 1;
        return 0;
    }

};