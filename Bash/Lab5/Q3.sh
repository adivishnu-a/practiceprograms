echo "Enter a number: "
read num
if [ $num -lt 2 ]; then
    echo "$num is not a prime number."
    exit
else
    i=2
    while [ $i -le $((num/2)) ]
    do
        if [ $((num%i)) -eq 0 ]; then
            echo "$num is not a prime number."
            exit
        fi
        i=$((i+1))
    done
fi
echo "$num is a prime number."

