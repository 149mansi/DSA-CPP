/*#include<iostream>
#include<vector>
using namespace std;

 void reverseWords(string s)
{
    vector<string> tmp;
    string str = "";
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            tmp.push_back(str);
            str = "";
        }
        else
            str += s[i];
    }
    tmp.push_back(str);
 return str;
}
int main(){
    return 0;
}
*/
#include<iostream>
#include<vector>
using namespace std;
void reverseWords(string s)
{
    vector<string> tmp;
    string str = "";
    for (int i = 0; i < s.length(); i++) { // Strings doesn't have null characters as terminator by default
        if (s[i] == ' ') {
            tmp.push_back(str);
            str = "";
        }
        else
            str += s[i];
    }
    tmp.push_back(str);
    // No return statement as function is void
}
int main(){
return 0;
}
