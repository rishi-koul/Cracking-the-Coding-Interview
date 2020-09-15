def zero_row_col(matrix):
  list_all_0_index = list(list())
  # First lets get all the index where 0's are present
  for i in range(0, len(matrix)):
    for j in range(0, len(matrix[0])):
      if matrix[i][j] == 0:
        list_all_0_index.append([i, j])

  # Iterate over all paired indexes where 0's are present
  for i in range(0, len(list_all_0_index)):
    # Iterate over columns of matrix
    for col in range(0, len(matrix[0])):
      # Replace all column elements present in row: list_all_0_index[i][0] to 0
      matrix[list_all_0_index[i][0]][col] = 0

  # Iterate over all paired indexes where 0's are present
  for i in range(0, len(list_all_0_index)):
    # Iterate over rows of matrix
    for row in range(0, len(matrix)):
      # Replace all row elements present in col: [list_all_0_index[i][1]] to 0
      matrix[row][list_all_0_index[i][1]] = 0
        
# Function to print 2D-array in matrix form
def print_matrix(matrix):
  for row in range(0, len(matrix)):
      print(matrix[row])

# Example
my_matrix  = [  [1, 2, 3, 10],
                [4, 0, 6, 11],
                [7, 8, 9, 12],
                [13, 14, 15, 0],
                [16, 17, 20, 19] ]

print_matrix(my_matrix)
zero_row_col(my_matrix)
print()
print_matrix(my_matrix)
