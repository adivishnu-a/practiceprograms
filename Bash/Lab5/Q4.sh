echo "Enter the number of terms: "
read n
a=0
b=1
echo "The Fibonacci series up to $n terms is:"
i=0
while [ $i -lt $n ]
do
    echo -n "$a "
    f=$((a+b))
    a=$b
    b=$f
    i=$((i+1))
done
echo ""

