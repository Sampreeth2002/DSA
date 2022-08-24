class Solution {
    public String smallestSubsequence(String s) {
     int[] arr=new int[26];
        for(int i=0;i<s.length();i++)
        {
            arr[s.charAt(i)-'a']=i;
        }
        boolean[] visited=new boolean[26];
        Deque<Integer> st=new ArrayDeque<>();
        for(int i=0;i<s.length();i++)
        {
            int j=s.charAt(i)-'a';
            if(visited[j])
                continue;
            while(!st.isEmpty() && st.peek()>j && arr[st.peek()]>i)
            {
                visited[st.pop()]=false;
            }
            st.push(j);
            visited[j]=true;
        }
        StringBuilder str=new StringBuilder();
        while(!st.isEmpty())
        {
            str.append((char)(st.pop()+'a'));
        }
        return str.reverse().toString();
    }
}