echo "Creating Five Folders:"
for (( i=1; i<=5; i++ ))
do
  echo "Enter name $i:"
  read name
  mkdir "$name"
done
ls

