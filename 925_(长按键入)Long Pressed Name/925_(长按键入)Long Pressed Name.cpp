class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int name_len = name.size();
        int typed_len = typed.size();
        int i = 0, j = 0;
        while(i < name_len && j < typed_len){
            if(i + 1 < name_len && name[i] == name[i + 1]){
                if(typed[j] == name[i]) i++, j++;
                else return false;
            }
            else{
                if(typed[j] != name[i]) return false;
                while(j < typed_len && typed[j] == name[i]) j++;
                i++;
            }
        }
        if(i != name_len || j != typed_len) return false;
        else return true;
    }
};