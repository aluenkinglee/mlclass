#!/bin/bash
# $1 input file $2 output file
# 把数据matrix从octave可以识别的模式转化为armadillo识别的数据格式
echo "convert data which could be read by octave to structure that armadillo can be dealed with."
# 把matrix赋值给变量
#filecontent=`cat ex1data1.txt`
filecontent=`cat $1`

# 读取文件第一行，判断列数
#line1=`head -1 ex1data1.txt`
line1=`head -1 $1`

# echo $line1
# IFS 默认值为空白，此处根据格式‘，’转化为一个数组
IFS="," && arr=($line1)

# 统计矩阵 row col 数目
len=${#arr[@]}
#rows=`wc -l <ex1data1.txt`
rows=`wc -l <$1`

#格式转化过程,文件头，用于处理是矩阵行列大小
#out="data1.txt"
out=$2
echo "ARMA_MAT_TXT_FN008">>$out
echo $rows $len >> $out
echo $filecontent >> $out

#for  line in $filecontent
#do 
#    IFS=" " && arr=($line)
#    # equals to echo $line
#    echo ${arr[0]} ${arr[1]} >> new.txt
#done
