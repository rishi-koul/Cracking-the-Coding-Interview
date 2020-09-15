def is_permutation_of_palindrome(sentence):
  # Initialize a dictionary
  my_dict = {}
  # Remove all whitespaces
  sentence = sentence.replace(" ", "")
  # iterate over the sentence
  for letter in sentence:
    # add all letters in sentence along with their count in my_dict
    if letter not in my_dict.keys():
      my_dict[letter] = 0
    my_dict[letter] += 1

  odd_count = 0
  # check for no.of letters having odd count in my_dict
  for i in my_dict.values():
    if(i%2 == 1): odd_count += 1
  
  # if more than two letters have odd count it cant be permutation of a palindrome
  return (odd_count <=1 )

print(is_permutation_of_palindrome("tact coa"))



