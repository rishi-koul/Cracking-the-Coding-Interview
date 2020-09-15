def check_for_one_edit(string1, string2):
  # If both string have same length
  if(len(string1) == len(string2)):
    # Retuen True if both are same string, 0 edits away
    if(string1 == string2): return True

    else:
      # Iterate over any one of the string
      for i in range(0, len(string1)):
        # Replace the character present at i index of string1 with the character present at i index of string2
        # If both string become equal return True, 1 edit away (replace)
        if string1.replace(string1[i], string2[i]) == string2:
          return True
      # Else return False
      return False

  elif(len(string1) > len(string2)):
    long_string, small_string = string1, string2

  elif(len(string1) < len(string2)):
    long_string, small_string = string2, string1
  
  # Iterate over the longer string
  for letter in long_string:
    # Remove one letter from long string and check if becomes equal to small string
    # Yes, return True, 1 edit away (remove or insert)
    if(long_string.replace(letter, "") == small_string):
      return True
  # Else, return False
  return False


print(check_for_one_edit("pale", "ple"))
print(check_for_one_edit("pales", "pale"))
print(check_for_one_edit("pale", "bale"))
print(check_for_one_edit("pale", "bake"))
