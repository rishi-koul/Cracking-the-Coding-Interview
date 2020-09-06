def string_compression(string):
  compressed_string = ""
  prev_letter = ""

  # Iterate over the string
  for i in range(0, len(string)):
    # Add the first element of the string in compressed string
    if compressed_string == "":
      compressed_string += string[i]
      counter = 1

    # If it is last letter and is also not equal to prev letter
    elif string[i] != prev_letter and i == len(string) - 1:
      # Add the count of prev letter
      compressed_string += str(counter)
      # Add the last letter and its count which will always be 1
      compressed_string += string[i] + str(1)

    # If it is the last letter and equal to prev letter
    elif string[i] == prev_letter and i == len(string) - 1 :
      # Increase the counter
      counter += 1
      # Add the counter
      compressed_string += str(counter)

    # If letter is not equal to prev letter
    elif string[i] != prev_letter:
      # Increase the counter
      compressed_string += str(counter)
      compressed_string += string[i]
      counter = 1

    # If letter is equal to prev letter
    else:
      counter += 1

    # Assign prev letter to the present letter
    prev_letter = string[i]
  
  if (len(compressed_string) < len(string)): return compressed_string
  else: return string

print(string_compression("aabcccccaaa"))
  


