# Assumption: case-sensutive i.e. S and s considered unique

def unique_string(string):
  # Iterate ove rthe string
  for i in range(0, len(string)):
    # Create a string without that letter
    new_str = string[0:i] + string[i+1: len(string) + 1]
    # Checkout if that letter is in the remaining string
    if(string[i] in new_str):
      # Yes, so not unique
      return "Not Unique"
  return "Unique"

print(unique_string("string"))
# print(unique_string("stringg"))
