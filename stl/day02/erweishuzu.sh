#!/bin/bash 

# 声明一个模拟的二维数组
array=(
	   "1 2 3"
	   "4 5 6"
	   "7 8 9"
)

# 获取数组的行数和列数
rows=${#array[@]}
columns=${#array[0]}

# 遍历二维数组
for ((i = 0; i < rows; i++)); do
    for ((j = 0; j < columns; j++)); do
	        element=${array[i]}
			# 使用空格分隔的字符串，使用cut命令提取每个元素
		    element=$(echo "$element" | cut -d' ' -f$((j+1)))
			echo "Element at row $i, column $j: $element"
	done
done
