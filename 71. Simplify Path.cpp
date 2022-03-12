class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        list<string> paths;
        string cur_path = "";
        for(int i=0;i<path.length();i++)
        {
            if(path[i] == '.' && (i > 0 && path[i-1] =='/'))
            {
                cur_path = "";
                int dotNum = 0;
                string dots = "";
                while(i < path.length() && path[i] != '/')
                {
                    dotNum ++;
                    dots += path[i];
                    i ++;
                }
                if(dotNum == 2)
                {
                    if(dots[1] == '.' && paths.size() > 0)
                        paths.pop_back();
                }
                else if(dotNum > 2){
                    paths.push_back(dots);
                }
            }
            else if(path[i] == '/')
            {
                if(cur_path.length() > 0)
                {
                    paths.push_back(cur_path);
                }
                cur_path = "";
            }
            else{
                cur_path += path[i];   
            }
        }
        if(cur_path.length() > 0)
        {
            paths.push_back(cur_path);
        }
        for(auto dir:paths)
        {
            ans += "/" + dir;
        }
        if(ans.length() == 0)
            return "/";
        return ans;
    }
};