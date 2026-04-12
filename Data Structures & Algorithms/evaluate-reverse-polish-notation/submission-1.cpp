class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        set<string> operators = {"+", "-", "/", "*"};
        stack<int> nums;

        for (const auto& token : tokens){
            if (operators.count(token)){
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                
                int total = 0;
                if (token == "+"){
                    total = num2 + num1;
                }
                else if (token == "-"){
                    total = num2 - num1;
                }
                else if (token == "/"){
                    total = num2 / num1;
                }
                else{
                    total = num2 * num1;
                }

                nums.push(total);
                continue;
            }

            nums.push(stoi(token));
        }

        return nums.top();
    }
};
