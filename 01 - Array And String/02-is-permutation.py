# Assumption: Case-senitive i.e. S and s are different

def is_permutation(string1, string2):
  # Check if their length is same
  if(len(string1) == len(string2)):
    # Check if len of their unique chracters is same
    if(len(set(string1)) == len(set(string2))):
      # Iterate over all letters of unique string1
      for letter in set(string1):
        # Check if letter in unique string1 is in unique string2
        if(letter not in set(string2)):
          # If not then not a permutation
          return "Not a permutation"
      # Else definately a permutation
      return "A permutation"
    # If not, not a permutation
    return "Not a permutation"
  # If not, not a permutation
  return "Not a permutation"


print(is_permutation("string", "trngis"))
