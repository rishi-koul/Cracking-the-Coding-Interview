# Given: Its a square matrix(N * N)

# Take the traverse of the matrix
def tranverse(matrix):
  # Iterate over all rows
  for row in range(0, len(matrix)):
    # Iterate over col starting from index row
    for col in range(row, len(matrix[0])):
      # Swap the elemts at [row][col] with [col][row]
      temp = matrix[col][row]
      matrix[col][row] = matrix[row][col]
      matrix[row][col] = temp
  return matrix

# Invert individual columns
def invert_col(matrix):
  # Iterate over half the matrix rows
  for row in range(0, len(matrix) // 2 ):
    # Iterate over all columns
    for col in range(0, len(matrix[0])):
      # Swap elements at top and bottom, at 2nd and 2nd last etc
      temp = matrix[len(matrix) - row - 1][col]
      matrix[len(matrix) - row - 1][col] = matrix[row][col]
      matrix[row][col] = temp
  return matrix

# Function to rotate by 90 deg anticlockwise
def rotate_90_anticlock(matrix):
  tranverse(my_matrix)
  invert_col(my_matrix)

# Function to print 2D-array in matrix form
def print_matrix(matrix):
  for row in range(0, len(matrix)):
      print(matrix[row])

# Example
my_matrix  = [  [1, 2, 3, 10],
                [4, 5, 6, 11],
                [7, 8, 9, 12],
                [13, 14, 15, 16] ]

print_matrix(my_matrix)
rotate_90_anticlock(my_matrix)
print()
print_matrix(my_matrix)
