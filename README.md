# poj-1018-Communication-System
poj算法题1018——Communication System
[Communication System](http://poj.org/problem?id=1018)

**Description**

We have received an order from Pizoor Communications Inc. for a special communication system. The system consists of several devices. For each device, we are free to choose from several manufacturers. Same devices from two manufacturers differ in their maximum bandwidths and prices. 
By overall bandwidth (B) we mean the minimum of the bandwidths of the chosen devices in the communication system and the total price (P) is the sum of the prices of all chosen devices. Our goal is to choose a manufacturer for each device to maximize B/P. 

**Input**

The first line of the input file contains a single integer t (1 ≤ t ≤ 10), the number of test cases, followed by the input data for each test case. Each test case starts with a line containing a single integer n (1 ≤ n ≤ 100), the number of devices in the communication system, followed by n lines in the following format: the i-th line (1 ≤ i ≤ n) starts with mi (1 ≤ mi ≤ 100), the number of manufacturers for the i-th device, followed by mi pairs of positive integers in the same line, each indicating the bandwidth and the price of the device respectively, corresponding to a manufacturer.

**Output**

Your program should produce a single line for each test case containing a single number which is the maximum possible B/P for the test case. Round the numbers in the output to 3 digits after decimal point. 

**Sample Input**

1 3<br>
3 100 25 150 35 80 25<br>
2 120 80 155 40<br>
2 100 100 120 110<br>

**Sample Output**

0.649

在这里我把输入输出说一下吧，写程序的时候没看清楚被这个坑死了= =：<br>
输入：<br>
第一行第一个数字时进行测试的**用例个数t**（1<=t<=10），第二个数字是该测试用例**所需设备的个数n**（1<=n<=100），该用例接下来几行第一个数字都是每个设备所有的**供应商数量i**（1<=i<=n）,之后的数据是各个供应商的**带宽和价格**。<br>
输出：<br>
 将所有用例的最大b/p打印出来，**一行**输出一个。<br>
<br>
接下来我大概说一下我的**解题思路**：<br>
一开始以为这道题是贪心算法，但是深入思考时觉得没办法用贪心算法（也可能是我比较笨，想不到），到网上查了一些资料，大部分用动态规划，但是因为对这一块还不是很熟练，就用了另外一种比较简单粗暴的方法：<br>
（1）先对**带宽进行从小到大排序**；<br>
（2）**枚举法**（因为二维数组需要最大的空间为100*100，可以接受，且可以通过一些判断剪掉一些不必要的计算，程序中会有显示）<br>
（3）**通过比较得到最优解**.<br>

**遇到的问题：**<br>
（1）我用的是vector，对这个了解不是很透彻，在对这个进行排序的时候发现没办法改变其中的值，即没法交换位置。后来又用一个动态数组b1，将其复制过来进行排序，但是总会出现run-time error，堆错误（应该是内存泄露，但是不清楚哪里出错）。<br>
   **解决：**用了头文件algorithm里面对vector排序的函数sort（vec.begin(),vec.end() )。<br>
（2）还有就是输入和输出理解不透彻的问题。<br>
（3）记得释放内存。<br>

**不足：**<br>
（1）里面有3层for循环，虽然剪掉一些不必要的计算，但是觉得还是会比较慢，不过提交上去是Accepted。<br>
