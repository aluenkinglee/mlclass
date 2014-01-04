#! /bin/bash
IN="bas@som.com;;, jsa@th.com"
echo "split the string ... method one"
#arr=$(echo $IN | tr ";," "\n")
arr=$(echo $IN | tr ";," " ")
for x in $arr
do
    echo $x
done
echo "print with arr[0] arr[1]"
echo $arr[0]
echo "print with {arr[0]} {arr[1]}"
echo "${arr[@]}"
echo "${arr[0]}" 
echo "${arr[1]}"
echo "this is the right solution with \"\${arr[0]}\""

echo "split the string ... method two"
IFS=";,\n" && Array=($IN)
for x in $Array
do
    echo $x
done

echo "${Array[@]}" 
#echo "${Array[0]}" 
#echo "${Array[1]}" 
