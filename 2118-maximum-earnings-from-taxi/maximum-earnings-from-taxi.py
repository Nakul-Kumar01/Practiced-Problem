from functools import cache
class Solution:
    def maxTaxiEarnings(self, n: int, arr: list[list[int]]) -> int:
        n = len(arr)

        arr.sort(key = lambda x :x[0])

        starts = [ride[0] for ride in arr]

        @cache
        def find(i):
            if i>= len(arr) : return 0

            inn = bisect.bisect_left(starts,arr[i][1])
            return max(arr[i][1]-arr[i][0] + arr[i][2] + find(inn), find(i+1))


        return find(0)