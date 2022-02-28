#!/bin/bash  
sites=("www.a.com" "www.b.com" "www.c.com" "www.d.com" "www.e.cn" "www.f.cn")
n_sites=${#sites[*]}     #获取一维sites的数组长度
for ((i=0;i<$n_sites;i++));
do
    inner_sites=(${sites[$i]}) #将一维sites字符串赋值到数组
    n_inner_sites=${#inner_sites[*]} #获取二维sites的数组长度
	  for ((j=0;j<$n_inner_sites;j++));
	  do
		    echo ${inner_sites[$j]}  #回显site
		    #do something
	  done
done
