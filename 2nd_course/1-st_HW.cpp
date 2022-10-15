#include <iostream>
#include <string>
#include <regex>
using namespace std;
 
int main () {
 

   string str ("https://www.com");
   std::string str_pattern = R"(((https:\/\/(?:[a-z0-9](?:[a-z0-9-]{0,61}[a-z0-9])?\.))+([a-z0-9][a-z0-9-]{0,61}[a-z0-9])))";
   regex str_expr (str_pattern);
 
   if (regex_match (str,str_expr))
      cout << "string:object => matched\n";
 
   if ( regex_match ( str.begin(), str.end(), str_expr ) )
      cout << "string:range(begin-end)=> matched\n";

    
   smatch sm;
   regex_match (str,sm,str_expr);
    
   regex_match ( str.cbegin(), str.cend(), sm, str_expr);
   cout << "String:range, size:" << sm.size() << " matches\n";
 
   
 
   cout << "the matches are: ";
   for (unsigned i=0; i<sm.size(); ++i) {
      cout << "[" << sm[i] << "] ";
   }
 
   cout << endl;
 
   return 0;
}