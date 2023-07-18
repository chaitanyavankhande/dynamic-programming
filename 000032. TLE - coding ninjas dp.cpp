

// 000032. TLE - (medium) Longest Palindromic Substring- coding ninjas dp.cpp


#include <bits/stdc++.h> 


string toStr(char ch) {
  string str = "";
  str += ch;
  return str;
}

void solve(string &str, int start, int end, string currentStr, string &ansString) {
    
    if(currentStr.size() > ansString.size()) ansString = currentStr;
    
    int n = str.size();
    if(start < 0 || end == n) return;
    if(str[start] != str[end]) return;

    if(start == end) {
        solve(str, start-1, end, "", ansString);
        solve(str, start, end+1, "", ansString);
        solve(str, start-1, end+1, toStr(str[start]), ansString);
    }
    else {
        solve(str, start-1, end+1, toStr(str[start]) + currentStr + toStr(str[end]), ansString);
        
    }

}

string longestPalinSubstring(string &str)
{
    // Write your code here.
    int n = str.size();
    string ansString = "";
    for(int i=0; i<n; i++) {
        solve(str, i, i, "", ansString);
    }
    return ansString;
}
