echo "Enter the value of N: "
read N
count=0
even=0
echo "The first $N even numbers are:"
while [ $count -lt $N ]
do
    echo $even
    even=$((even+2))
    count=$((count+1))
done

