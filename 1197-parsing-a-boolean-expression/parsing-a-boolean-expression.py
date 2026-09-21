class Solution:
    def parseBoolExpr(self, s: str) -> bool:
        
        n = len(s)

        st = []


        for i in range(n) :
            if s[i] != ')' :
                # print(s[i])
                st.append(s[i])
            else:
                t = 0
                f = 0
                while st and st[-1] != '(' :
                    if st[-1] == 't' : t+=1
                    elif st[-1]=='f' : f +=1

                    st.pop()
                
                st.pop()
                oper = st[-1]
                st.pop()

                if oper == '&' :
                    if t != 0 and f ==0 : st.append('t')
                    else : st.append('f')
                elif oper == '|' :
                    if t!= 0 : st.append('t')
                    else : st.append('f')
                else :
                    if t == 0 : st.append('t')
                    else : st.append('f')
                
                # st.pop()

        # print(st[-1])
        return True if st[-1] == 't' else False

