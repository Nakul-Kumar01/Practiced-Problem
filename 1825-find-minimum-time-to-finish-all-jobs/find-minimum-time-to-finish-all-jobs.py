class Solution:
    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:
        jobs.sort(reverse=True)

        left, right = max(jobs), sum(jobs)

        def can_assign(limit):
            workers = [0] * k

            def backtrack(i):
                if i == len(jobs):
                    return True

                for w in range(k):
                    if workers[w] + jobs[i] <= limit:
                        workers[w] += jobs[i]

                        if backtrack(i + 1):
                            return True

                        workers[w] -= jobs[i]

                    # Skip equivalent empty workers
                    if workers[w] == 0:
                        break

                return False

            return backtrack(0)

        while left < right:
            mid = (left + right) // 2

            if can_assign(mid):
                right = mid
            else:
                left = mid + 1

        return left