def is_rotation(s1, s2):
  if len(s1) != len(s2):
    return False
  return is_substring(s1 + s1, s2)
  
def is_substring(s1, s2):
  if len(s2) > len(s1):
    return False
  for i in range(len(s1) - len(s2) + 1):
    is_substring_here = True
    for j in range(len(s2)):
      if s1[i + j] != s2[j]:
        is_substring_here = False
        break
    if is_substring_here:
      return True
  return False


print(is_rotation("waterbottle", "erbottlewat"))

