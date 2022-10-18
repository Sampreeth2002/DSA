class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        
        if(n==1) return str;
        if(n==2) return "11";
        if(n==3) return "21";
        if(n==4) return "1211";
        
         str = "1211";
        string newStr = "";
        
        while(n-4>0)
        {
            n--;
            int sizeOfStr = str.size();
            
            int counter = 1;
            for(int i=0;i<sizeOfStr-1;i++)
            {
                if(i==sizeOfStr-2 && str[i]!=str[i+1])
                {
                    newStr += counter + '0';
                    newStr += str[i];
                    counter = 1;
                    newStr += counter + '0';
                    newStr += str[i+1];
                }
                else if(i==sizeOfStr-2 && str[i]==str[i+1])
                {
                    counter++;
                    newStr += counter + '0';
                    newStr += str[i];
                }
                else if(str[i]==str[i+1])
                {
                    counter++;
                }
                else
                {
                    newStr += counter + '0';
                    newStr += str[i];
                    counter = 1;
                }
                
            }
            
            str = newStr;
            newStr = "";
            
        }
        
        return str;
    }
};