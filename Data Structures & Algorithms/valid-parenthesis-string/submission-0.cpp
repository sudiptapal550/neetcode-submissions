class Solution {
public:
    bool checkValidString(string s) {
       int n = s.length();

       int open = 0;
       int star = 0;
       for (int i= 0 ; i < n; i++) {
        if (s[i] == '(') {
            open += 1;
        } else if (s[i] == '*') {
            star += 1;
        } else {
            if (open > 0) {
                open -= 1;
            } else if (star > 0) {
                star -= 1;
            } else return false;
        }
       }


       open = 0;
       star = 0;

       for (int i = n-1 ; i >= 0; i--) {
        if (s[i] == ')') {
            open += 1;
        } else if (s[i] == '*') {
            star += 1;
        } else {
            if (open > 0) {
                open -= 1;
            } else if (star > 0) {
                star -= 1;
            } else return false;
        }
       }
       return true;

    }
};
