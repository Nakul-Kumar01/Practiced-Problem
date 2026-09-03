class Solution:
    def merge(self, arr: List[List[int]]) -> List[List[int]]:
        arr.sort()
        l = arr[0][0]
        r = arr[0][1]

        ans = []


        for i in range(1,len(arr)) : 
            if r < arr[i][0] :
                ans.append([l,r])
                l = arr[i][0]
                r = arr[i][1]
            else :
                l = min(l,arr[i][0])
                r = max(r,arr[i][1])
        
        ans.append([l,r])
        return ans
            
                
