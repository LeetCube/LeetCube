from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        st = []

        def backtrack(openCnt, closeCnt):
            if openCnt == closeCnt == n:
                res.append("".join(st))
                return
            
            if openCnt < n:
                st.append("(")
                backtrack(openCnt + 1, closeCnt)
                st.pop()
            
            if closeCnt < openCnt:
                st.append(")")
                backtrack(openCnt, closeCnt + 1)
                st.pop()
        
        backtrack(0, 0)
        return res