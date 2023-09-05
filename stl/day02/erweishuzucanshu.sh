#!/bin/bash

# 接收命令行参数并将它们组装成一个二维数组
# 假设参数的格式为 "row1:val1,val2,val3 row2:val4,val5,val6 ..."
# 每一行以空格分隔，每一行的第一个元素是行名，后面是逗号分隔的元素值。
# 例如：./myscript.sh "row1:1,2,3 row2:4,5,6 row3:7,8,9"
input="$1"  # 第一个命令行参数

# 将参数解析成一维数组
IFS=' ' read -a rows <<< "$input"

# 遍历一维数组并打印每一行的内容
for row in "${rows[@]}"; do
    IFS=':' read -a parts <<< "$row"
	rowName="${parts[0]}"  # 行名
	elements="${parts[1]}"  # 元素值
	echo "Row: $rowName"
	IFS=',' read -a elementArray <<< "$elements"
	for element in "${elementArray[@]}"; do
		echo "  Element: $element"
	done
done
