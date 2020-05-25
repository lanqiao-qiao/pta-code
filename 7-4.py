m={'+':1,'-':1,'*':2,'/':2,'(':3,')':3}
ans=[];st=[]
s=input()
i=int(0)
while i< len(s):
    #print('#')
    if s[i].isdigit() or (i==0 or s[i-1]=='(') and (s[i]=='-' or s[i]=='+'):
        str=""
        if s[i]!='+':
            str+=s[i]
        while i+1<len(s) and (s[i+1]=='.' or s[i+1].isdigit()) :
            str+=s[1+i]
            i+=1
        ans.append(str)
    else:
        if s[i]=='(':
            st.append(s[i])
        elif s[i]==')':
            while st and st[-1]!='(':
                ans.append(st[-1])
                st.pop()
            st.pop()
        else:
            while st and st[-1]!='(' and m[st[-1]] >= m[s[i]]:
                ans.append(st[-1])
                st.pop()
            st.append(s[i])
    i+=1
while st:
    ans.append(st[-1])
    st.pop()
k=0
print(*ans)

