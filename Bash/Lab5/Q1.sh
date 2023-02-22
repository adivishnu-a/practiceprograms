echo "Enter value of a: "
read a
echo "Enter value of b: "
read b
echo "Enter value of c: "
read c
if [ $a -gt $b ]; then
    if [ $a -gt $c ]; then
        echo "$a is the greatest number."
    else
        echo "$c is the greatest number."
    fi
else
    if [ $b -gt $c ]; then
        echo "$b is the greatest number."
    else
        echo "$c is the greatest number."
    fi
fi
