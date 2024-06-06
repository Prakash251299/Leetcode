class Solution {
    public List<String> commonChars(String[] words) {
        List<String> res = new ArrayList<String>();
        HashMap<Character,Integer>m = new HashMap<>();
        for(int i=0;i<words[0].length();i++){
            if(m.get(words[0].charAt(i))==null){
                m.put(words[0].charAt(i),1);
            }
            else{
                int t= m.get(words[0].charAt(i))+1;
                m.put(words[0].charAt(i),t);
            }
        }
        m = Solution.find(m,words,1);
        System.out.println(m);
        for(Character x:m.keySet()){
            if(m.containsKey(x)==true){
                for(int i=0;i<m.get(x);i++){
                    res.add(x.toString());
                }
            }
        }
                    
        return res;
    }
    
    public static HashMap<Character,Integer> find(HashMap<Character,Integer>m,String[]words,int i){
        if(i==words.length){
            return m;
        }
        HashMap<Character,Integer>m1 = new HashMap<Character,Integer>();
        for(int j=0;j<words[i].length();j++){
            if(m1.get(words[i].charAt(j))==null){
                m1.put(words[i].charAt(j),1);
            }
            else{
                m1.put(words[i].charAt(j),m1.get(words[i].charAt(j))+1);
            }
        }
        
        for(Character x:m.keySet()){
            if(m1.get(x)==null){
                m.put(x,0);
            }
            else{
                if(m.get(x)<=m1.get(x)){
                    m.put(x,m.get(x));
                }
                else{
                    m.put(x,m1.get(x));
                }
            }
        }
        m = Solution.find(m,words,i+1);
        return m;
    }
}
