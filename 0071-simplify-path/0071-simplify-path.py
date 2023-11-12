class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack=[]
        path=path.split("/")
        path =[p for p in path if p ]
        for p in path:
            if (len(stack)==0 and p=="..") or p ==".":
                continue 
            elif p==".." and stack:
                stack.pop()
            else:
                stack.append(p)
        return "/" + "/".join(stack)
        