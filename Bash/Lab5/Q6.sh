echo "Enter a number: "
read num
dup=$num
sum=0
while [ $num -gt 0 ]
do
    rem=$(($num%10))
    sum=$(($sum+$rem))
    num=$(($num/10))
done
echo "The sum of digits of $dup is $sum."

