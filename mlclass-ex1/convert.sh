#!/bin/bash
# $1 input file $2 output file
# ������matrix��octave����ʶ���ģʽת��Ϊarmadilloʶ������ݸ�ʽ
echo "convert data which could be read by octave to structure that armadillo can be dealed with."
# ��matrix��ֵ������
#filecontent=`cat ex1data1.txt`
filecontent=`cat $1`

# ��ȡ�ļ���һ�У��ж�����
#line1=`head -1 ex1data1.txt`
line1=`head -1 $1`

# echo $line1
# IFS Ĭ��ֵΪ�հף��˴����ݸ�ʽ������ת��Ϊһ������
IFS="," && arr=($line1)

# ͳ�ƾ��� row col ��Ŀ
len=${#arr[@]}
#rows=`wc -l <ex1data1.txt`
rows=`wc -l <$1`

#��ʽת������,�ļ�ͷ�����ڴ����Ǿ������д�С
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
