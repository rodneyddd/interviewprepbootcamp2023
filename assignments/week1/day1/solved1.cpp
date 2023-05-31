class Solution 
{
public:

    vector<string>bubbleSortBySize(std::vector<std::string>& vec) 
    {
        int n = vec.size();
        bool swapped;
        
        for (int i = 0; i < n - 1 ; i++) 
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
        return vec;
    }


    string shortestCompletingWord(string licensePlate, vector<string>& words) 
    {
        int counter = 0;
        unordered_map<char,int>hashmap;
        for(int i = 0; i < licensePlate.size(); i++) //storing letter frequencies to decrement later on
        {
            if(isalpha(licensePlate[i])){
                if(hashmap.count(tolower(licensePlate[i])))
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
        cout << counter << endl; //checking how many letters got stored
        
        cout << "currently printing hashmap" << endl;
        for (auto it = hashmap.begin(); it != hashmap.end(); ++it) //checking the hash table
        {
            
            cout << it->first << " " << it->second << endl;
        }


        vector<string>wordss = bubbleSortBySize(words);  

        /*for(int i = 0; i < wordss.size(); i++)
        {
            cout << wordss[i] << endl; //
        }     */

        unordered_map<char,int>hashmap2;
        for (auto it = hashmap.begin(); it != hashmap.end(); ++it)
        {
           hashmap2[it->first] = it->second;
           //cout << "currently printing hashmap2" << endl;
           //cout << it->first << " " << hashmap2[it->first] << endl;
        }




        int hcv = counter; //hcv equals holdcountervalue
        for(int i = 0; i < wordss.size(); i++)
        {
            int n = wordss[i].length();
            for(int j = 0; j < n; j++)
            {
                if(hashmap2.count(wordss[i][j]) && hashmap2[wordss[i][j]] > 0)
                {
                    counter--; //counter--
                    hashmap2[wordss[i][j]]--;
                }

            }

            cout << "counter: " << counter << endl;

            cout << "currently printing hashmap2, after decrementation" << endl;
            for (auto it = hashmap2.begin(); it != hashmap2.end(); ++it)
            {
                //hashmap2[it->first] = it->second;
                //cout << "currently printing hashmap2, after decrementation" << endl;
                cout << it->first << " " << hashmap2[it->first] << endl;
            }

            

            if(counter <= 0)   
                return wordss[i];
            else
            {
                counter = hcv;
                for (auto it = hashmap.begin(); it != hashmap.end(); ++it)
                    {
                        hashmap2[it->first] = it->second;
                        //cout << "currently printing hashmap2" << endl;
                        //cout << it->first << " " << hashmap2[it->first] << endl;
                    }
            }



            /*for (auto it = hashmap2.begin(); it != hashmap2.end(); ++it)
            {
                if(it->second > 0){
                for (auto it = hashmap.begin(); it != hashmap.end(); ++it)
                    {
                        hashmap2[it->first] = it->second;
                        //cout << "currently printing hashmap2" << endl;
                        //cout << it->first << " " << hashmap2[it->first] << endl;
                    }
                }
                else if(it == hashmap2.end() && it->second <= 0)
                    return wordss[i];
            }*/
                
        }
        return "";
    }
    //copy all the letters, and then 
};
