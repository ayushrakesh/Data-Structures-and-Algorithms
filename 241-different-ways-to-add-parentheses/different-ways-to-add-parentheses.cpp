class Solution {
public:
    vector<int> three(string exp) {
        vector<int> res;
        char c = exp[1];
        switch (c) {
        case '+':
            res.push_back((exp[0] - '0') + (exp[2] - '0'));
            break;

        case '-':
            res.push_back((exp[0] - '0') - (exp[2] - '0'));
            break;

        case '*':
            res.push_back((exp[0] - '0') * (exp[2] - '0'));
            break;
        }
        return res;
    }
    vector<int> four(string exp) {
        char c = exp[1];
        vector<int> res;
        if (c == '+' || c == '-' || c == '*') {
            switch (c) {
            case '+':
                res.push_back((exp[0] - '0') + (stoi(exp.substr(2, 2))));
                break;

            case '-':
                res.push_back((exp[0] - '0') - (stoi(exp.substr(2, 2))));
                break;

            case '*':
                res.push_back((exp[0] - '0') * (stoi(exp.substr(2, 2))));
                break;
            }
        } else {
            switch (c) {
            case '+':
                res.push_back((stoi(exp.substr(0, 2))) + (exp[3] - '0'));
                break;

            case '-':
                res.push_back((stoi(exp.substr(0, 2))) - (exp[3] - '0'));
                break;

            case '*':
                res.push_back((stoi(exp.substr(0, 2))) * (exp[3] - '0'));
                break;
            }
        }
        return res;
    }
    vector<int> five(string exp) {
        char c = exp[2];
        vector<int> res;

        switch (c) {
        case '+':
            res.push_back((stoi(exp.substr(0, 2))) + (stoi(exp.substr(2, 2))));
            break;

        case '-':
            res.push_back((stoi(exp.substr(0, 2))) - (stoi(exp.substr(2, 2))));
            break;

        case '*':
            res.push_back((stoi(exp.substr(0, 2))) * (stoi(exp.substr(2, 2))));
            break;
        }
        return res;
    }
    vector<int> solve(string exp) {
        int n = exp.size();
        vector<int> res;
        
        if (n <= 2) {
            res.push_back(stoi(exp));
            return res;
        }
        // if (n <= 5) {
        //     switch (n) {
        //     case 3:
        //         return three(exp);
        //     case 4:
        //         return four(exp);
        //     case 5:
        //         return five(exp);
        //     }
        // }
        for (int i = 0; i < n; i++) {
            if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
                vector<int> u = solve(exp.substr(0, i));
                vector<int> v = solve(exp.substr(i + 1));

                for (int j = 0; j < u.size(); j++) {
                    for (int k = 0; k < v.size(); k++) {
                        if (exp[i] == '+')
                            res.push_back(u[j] + v[k]);
                        else if (exp[i] == '-')
                            res.push_back(u[j] - v[k]);
                        else
                            res.push_back(u[j] * v[k]);
                    }
                }
            }
        }
        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;

        return solve(expression);
        // return res;
    }
};