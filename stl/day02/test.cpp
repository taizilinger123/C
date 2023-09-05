#include <iostream>

int main() {
    // 定义一个示例的 2x3 二维数组
    int myArray[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
    // 获取数组的行数和列数
    int numRows = sizeof(myArray) / sizeof(myArray[0]);
	//std::cout <<" "<< numRows << std::endl;
	std::cout <<" "<< sizeof(myArray) << std::endl;
	//std::cout <<" "<< myArray << std::endl;
	//std::cout <<" "<< sizeof(myArray[0]) << std::endl;
	//std::cout <<" "<< myArray[0] << std::endl;
	
	int numCols = sizeof(myArray[0]) / sizeof(myArray[0][0]);
	//std::cout <<" "<< numCols << std::endl;
	//std::cout <<" "<< myArray[0] << std::endl;
	//std::cout <<" "<< sizeof(myArray[0]) << std::endl;
	//std::cout <<" "<< myArray[0][0] << std::endl;
	//std::cout <<" "<< sizeof(myArray[0][0]) << std::endl;
		
		    // 使用嵌套的 for 循环遍历二维数组
		    for (int row = 0; row < numRows; ++row) {
			        for (int col = 0; col < numCols; ++col) {
					      std::cout << myArray[row][col] << " ";
					}
				 std::cout << std::endl; // 在每行结束后换行
			}
			
            return 0;
}
