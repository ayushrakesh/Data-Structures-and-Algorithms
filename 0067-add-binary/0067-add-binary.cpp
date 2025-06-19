class Solution {
public:
    char addition(char a, char b, int* carry){
        if(a == '1' && b == '1' && *carry == 0){ 
            *carry=1;
            return '0';
        }
        else if(a == '1' && b == '1' && *carry == 1){
            return '1';
        }
        else if((a == '1' || b == '1') && *carry == 1){
            return '0';
        }
        else if(a == '1' || b == '1' || *carry == 1){
            *carry=0;
            return '1';
        }
        else{
            return '0';
        }
    }
    string addBinary(string a, string b) {
        string output;
        int carry=0;
        int i = a.size()-1;
        int j = b.size()-1;

        while(i >= 0 && j >= 0){
            output.insert(output.begin(), addition(a[i], b[j], &carry));
            i--;
            j--;
        }
        while(i >= 0){
            output.insert(output.begin(), addition(a[i], '0', &carry));
            i--;
        }
        while(j >= 0){
            output.insert(output.begin(), addition('0', b[j], &carry));
            j--;
        }
        if(carry == 1){
            output.insert(output.begin(), '1');
        }

        return output;
    }
};