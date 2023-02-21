for i in {1..50}
do
  mkdir "DIR-$i"
done
echo "Fifty Folders Created"
ls

for i in {1..50}
do
  rm -r "DIR-$i"
done
echo "Fifty Folders Deleted"
ls

