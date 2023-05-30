class Solution 
{
public:

    void bubbleSortBySize(std::vector<std::string>& vec) 
    {
        int n = vec.size();
        bool swapped;
        
        for (int i = 0; i < n - 1; i++) 
        {
            swapped = false;
            
            for (int j = 0; j < n - i - 1; j++) 
            {
                if (vec[j].size() > vec[j + 1].size()) 
                {
                    std::swap(vec[j], vec[j + 1]);
                    swapped = true;
                }
            }
            
            if (!swapped) 
            {
                // If no swap occurred in this pass, the vector is already sorted
                break;
         
            }
        }
    }


    string shortestCompletingWord(string licensePlate, vector<string>& words) 
    {
        int counter = 0;
        unordered_map<char,int>hashmap;
        for(int i = 0; i < licensePlate.size(); i++)
        {
            if(isalpha(licensePlate[i])){
                if(hashmap.count(licensePlate[i]))
                {
                    hashmap[tolower(licensePlate[i])]++;
                    counter++;
                }
                else{
                    hashmap[tolower(licensePlate[i])] = 1;
                    counter++;
                }

            }
        }
        cout << counter << endl;
        
        for (auto it = hashmap.begin(); it != hashmap.end(); ++it)
        {
           cout << it->first << " " << it->second << endl;
        }


        vector<int>wordss = bubbleSortBySize(words);       

        int hcv = counter; //hcv equals holdcountervalue
        for(int i = 0; i < wordss.size(); i++)
        {
            int n = wordss[i].length();
            for(int j = 0; j < n; j++)
            {
                if(hashmap.count(wordss[i][j]))
                    counter--;
            }
            if(counter <= 0)   
                return wordss[i];
            else
                counter = hcv;
                
        }
        return "";
    }
    //copy all the letters, and then 
};
