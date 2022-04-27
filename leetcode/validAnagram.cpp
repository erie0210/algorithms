// ascii code 이용
class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[30];
        memset(arr, 0, sizeof(arr));
        if(s.length()!=t.length())  return false;
        for(auto iter:s)    arr[iter-97]++;
        for(auto iter:t)   arr[iter-97]--;
        for(int i=0; i<30; i++) if(arr[i])  return false;
        return true;
    }
};




// sort 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())  return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s!=t)    return false;
        return true;
    }
};




//map 이용
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())  return false;
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto iter: mp){
            if(iter.second) return false;
        }
        return true;
    }
};