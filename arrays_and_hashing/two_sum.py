def twoSum(nums: list[int], target: int) -> list:
    seen = {}
    for index, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [index, seen[complement]]
        seen[num] = index
    return []

if __name__ == '__main__':
    print(twoSum(nums=[1,2,3,4], target=7))
    print(twoSum(nums=[1,2,3,4], target=6))
    print(twoSum(nums=[1,2,3,4], target=-7))
