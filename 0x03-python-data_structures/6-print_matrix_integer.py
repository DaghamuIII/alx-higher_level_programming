#!/usr/bin/python3
def print_matrix_integer(matrix=[[]]):
    for row in matrix:
        for index, value in enumerate(row):
            # use str.format() and no trailing space on last item
            if index != len(row) - 1:
                print("{:d}".format(value), end=" ")
            else:
                print("{:d}".format(value), end="")
        print()
