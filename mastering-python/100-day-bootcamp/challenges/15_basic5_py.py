# # Day (5)

fruits = ["Apple","Peach","Pear"]
for fruit in fruits:
    print(fruit)
    
print("\n") 
print("I have:")
for fruit in fruits:
    print(fruit + "-pie")

print(f"\nWhich one do you want: {fruits}\n")

student_scores = [150,142,185,120,171]
summing = 0
for score in student_scores:
    summing += score

print(summing)

#

sum_builtin = sum(student_scores)
print(sum_builtin)
    
# Challenge {1}

max_int = 0
for score in student_scores:
    if score > max_int:
        max_int = score

print(f"The maximum score is: {max_int} or {max(student_scores)}")

# # Challenge {2}: Gauss Challenge:
forward_num_seq = []
for number in range(1, 101, 1):
    forward_num_seq.append(number)
backward_num_seq = []
for number in range(100, 0, -1):
    backward_num_seq.append(number)

summed_seq = [] 
i = 0
for element in forward_num_seq:
    summed_seq.append((forward_num_seq[i] + backward_num_seq[i]))
    i += 1

print(sum(summed_seq)//2) # Need to divide by 2, as I am adding 100 with reversed same 100 pairs


    
    