class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int charCount = 0, start = 0, end = 0;
        string line = "";
        for(auto& w: words){
            int ws = w.size(), wordCount = end - start;
            if(charCount + ws + wordCount < maxWidth){
                charCount += ws;
            }
            else if(charCount + ws + wordCount == maxWidth){
                line.clear();
                while(start < end){
                    line += words[start++] + " ";
                }
                line += w;
                ++start;
                
                ans.push_back(line);
                charCount = 0;
            }
            else{
                if(wordCount == 1){
                    line = words[start++] + string(maxWidth - charCount, ' ');
                }
                else{
                    int intervalSize = (maxWidth - charCount) / (wordCount - 1);
                    int extras = (maxWidth - charCount) % (wordCount - 1);
                    string spaces(intervalSize, ' ');
                    line = words[start++];
                    while(start < end){
                        if(--extras >= 0)
                            line += " ";
                        line += spaces + words[start++];
                    }
                }
                ans.push_back(line);
                charCount = ws;
            }
            ++end;
        }
        if(charCount != 0){
            line.clear();
            while(start < end){
                line += words[start++] + " ";
            }
            int extras = maxWidth - line.size();
            if(extras > 0)
                line += string(extras, ' ');
            else if(extras < 0)
                line.pop_back();
            ans.push_back(line);
        }
        return ans;
    }
};