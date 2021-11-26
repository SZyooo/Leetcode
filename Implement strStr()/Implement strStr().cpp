#include<iostream>
#include<string>

using namespace std;

//KMP
class Solution {
public:
	void calMaxSamePreSubStr(const string& s,int* arr)
	{
		arr[0]=0;
		for(int i=1;i<s.length();i++)
		{
			int start = i-1;
			while(start!=0)
			{
				if(s[arr[start]] == s[i])
				{
					arr[i] = arr[start]+1;
					break;
				}
				else{
					start = arr[start-1];
				}
			}
			if(start == 0)
			{
				if(s[i] == s[0]) arr[i] = 1;
				else arr[i] = 0;
			}
		}
	}
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) return 0;
        if(haystack.length() == 0) return -1;
        int* maxPre = new int[needle.length()];
        calMaxSamePreSubStr(needle,maxPre);
        int haystack_index = 0,needle_index=0;
        int res = -1;
        while(needle_index < needle.length() && haystack_index < haystack.length())
        {
        	if(haystack[haystack_index] == needle[needle_index])
        	{
        		needle_index++;
        		if(needle_index == needle.length()) {
        			res = haystack_index - needle.length() + 1;
        			break;
        		}
        		haystack_index ++;
        	}
        	else
        	{
        		if(needle_index == 0)
        		{
        			haystack_index ++;
        		}
        		else{
        			needle_index = maxPre[needle_index-1];
        		}
        	}
        }
        delete [] maxPre;
        return res;
    }
};

int main()
{
	string haystack = "aaaaa";
	string needle = "aa";
	cout << Solution().strStr(haystack,needle);
}