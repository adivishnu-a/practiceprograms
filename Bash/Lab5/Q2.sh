echo "Enter n:"
read n
sum=0
i=1
while [ $i -le $n ]
do    
    echo "Enter number #$i:"
    read x
    sum=$(($sum+$x))
    i=$((i+1))
done
avg=$(($sum/$n))
echo "The average of $n numbers is $avg."
