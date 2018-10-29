class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        int len_emails = emails.size();
        for( int i = 0; i < len_emails; i++ ){
            int len_email = emails[i].size();
            int j = len_email - 1;
            //域名
            string domain;
            while(j >= 0 && emails[i][j] != '@') j--;
            domain += emails[i].substr(j, len_email - j);
            //本地名称
            string local_name;
            for( int k = 0; k < j; k++ ){
                if(emails[i][k] == '.') continue;
                else if(emails[i][k] == '+') break;
                else local_name += emails[i][k];
            }
            set.insert(local_name + domain);
            //cout << local_name + domain << endl;
        }
        return set.size();
    }
};