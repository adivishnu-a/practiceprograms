echo "Enter a number: "
read num
i=1
while [ $i -le 10 ]
do
    result=$((i*num))
    echo "$i*$num=$result"
    i=$((i+1))
done

