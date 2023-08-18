import random

file=open("transactions3.txt", 'w')
for i in range(10000):
    t_id=f"T{i+1}"
    num=random.randint(3,5)
    itemstring=""
    items=random.sample(['A','B','C','D','E'], k=num)
    for item in items:
        itemstring+=item+" "
    file.write(t_id+"-"+itemstring+"\n")
file.close()
print('Success')