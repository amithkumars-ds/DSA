def containsDuplicate(nums: list) -> bool:
    seen = set()
    for i in nums:
        if i in seen:
            return True
        seen.add(i)
    return False


print(containsDuplicate([1,1,2]))
print(containsDuplicate([1,3,2]))
