class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        list<string> waiting;
        int cur_len = 0;
        vector<string> ans;
        for(int w = 0; w<words.size();w ++)
        {
            string word = words[w];
            bool overFlow = true;
            if(cur_len + word.length() <= maxWidth)
            {
                waiting.push_back(word);
                cur_len += word.length() + 1;
                overFlow = false;
            }
            if(overFlow || w == words.size() - 1){
                string str = waiting.front();
                waiting.pop_front();
                auto iter = waiting.begin();
                int spaceLen=0;
                int wordsLen = str.length();
                int wordsNum = 1;
                while(iter!=waiting.end())
                {
                    wordsNum ++;
                    wordsLen += iter->length();
                    iter ++;
                }
                spaceLen = maxWidth - wordsLen;
                if(wordsNum == 1)
                {
                    string span(maxWidth - str.length(),' ');
                    str += span;
                    ans.push_back(str);
                }
                else{
                    int spaceNum = wordsNum - 1;
                    vector<int> spaceLens(spaceNum, spaceLen/spaceNum);
                    for(int i=0;i<spaceLen%spaceNum;i++)
                    {
                        spaceLens[i] ++;
                    }
                    waiting.insert(waiting.begin(),str);
                    str = "";
                    iter = waiting.begin();
                    string add;
                    for(int i=0;i<spaceNum;i++)
                    {
                        string space(spaceLens[i],' ');
                        add += (*iter) + space;
                        iter ++;
                    }
                    str = add + waiting.back();
                    ans.push_back(str);
                }
                cur_len = 0;
                if(overFlow)
                    w --;
                waiting.clear();
            }
        }
        string lastOne = ans.back();
        ans.pop_back();
        string newOne(maxWidth,' ');
        bool hasSpace = false;
        int ni = 0;
        for(int i=0;i<maxWidth;i++)
        {
            if(lastOne[i] == ' ')
            {
                if(hasSpace==false){
                    hasSpace = true;
                    newOne[ni++] = lastOne[i];
                }
            }
            else
            {
                newOne[ni++] = lastOne[i];
                hasSpace = false;
            }
        }
        ans.push_back(newOne);
        return ans;
    }
};