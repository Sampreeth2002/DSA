class Solution {
public:
    
    int count_digits(int n)
    {
        string num = to_string(n);
        return num.size();
    }
    
    string thousand(int f)
    {
        string ans="";
            for(int i=0;i<f;i++)
            {
                ans+="M";
            }
        
        return ans;
    }
    
    string hunderad(int s)
    {
        string ans = "";
        if(s==9) ans+="CM";
            else if(s==4) ans+="CD";
            else if(s==1) ans+="C";
            else
            {
                if(s==5) ans += "D";
                else if(s<5)
                {
                    for(int i=0;i<s;i++)
                    {
                        ans += "C";
                    }
                }
                else if(s>5)
                {
                    ans += "D";
                    for(int i=0;i<s-5;i++)
                    {
                        ans += "C";
                    }
                }
            }
        
        return ans;
    }
    
    string tens(int t)
    {
        string ans = "";
        if(t==9) ans += "XC";
            else if(t==4) ans += "XL";
            else if(t==1) ans += "X";
            else
            {
                if(t==5)
                    ans += "L";
                else if(t<5)
                {
                    for(int i=0;i<t;i++)
                    {
                        ans += "X";
                    }
                }
                else if(t>5)
                {
                    ans += "L";
                    for(int i=0;i<t-5;i++)
                    {
                        ans += "X";
                    }
                }
            }
        return ans;
    }
    
    string units(int fo)
    {
        string ans = "";
        if(fo==1)
                ans+="I";
            else if(fo==5) ans +="V";
            else if(fo==4) ans += "IV";
            else if(fo==9) ans += "IX";
            else if(fo>5)
            {
                ans += "V";
                
                for(int i=0;i<fo-5;i++)
                {
                    ans += "I";
                }
            }
            else if(fo>0)
            {
                for(int i=0;i<fo;i++)
                {
                    ans += "I";
                }
            }
        return ans;
    }
    
    string intToRoman(int num) {
          int digits = count_digits(num);
            string ans ="";
        if(digits==4)
        {
            
            int f = num/1000;
            ans += thousand(f);
            num = num - (f*1000);
        }
        
        if(digits>=3)
        {
            int s = num/100;
            ans += hunderad(s);
            num = num - (s*100);
        }
        
        if(digits>=2)
        {
            int t = num/10;
            ans += tens(t);
            num = num - (t*10);
        }
        
        if(digits>=1)
        {
            int fo = num/1;
            ans += units(fo);
        }
        
        return ans;
        
    }
};