class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        # m = map
        res=[]
        m={}
        for x in words[0]:
            if m.get(x)==None:
                m[x]=1
            else:
                m[x]+=1
        m = self.find(m,words,1)
        print(m)
        for x in m:
            if(m.get(x)>0):
                for i in range(0,m.get(x)):
                    res.append(x)
                    
        return res
    
    def find(self,m,words,i):
        if(i==len(words)):
            return m
        m1={}
        for x in words[i]:
            if m1.get(x)==None:
                m1[x]=1
            else:
                m1[x]+=1
        for x in m:
            if(m1.get(x)==None):
                m[x]=0
            else:
                if(m.get(x)<=m1.get(x)):
                    m[x]=m[x]
                else:
                    m[x]=m1[x]
                # print("")
        self.find(m,words,i+1)
        return m
