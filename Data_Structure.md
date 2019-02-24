# Data Structure  
## 基础课程

#### 基数排序
桶排序的一种扩展，从低位到高位进行排序.
  >- maxbits()   
  > 返回排序数组中数字的最大位数  
  >- radixSort()  
  > count[10] 每一位的变化范围  
  > bucket[size] 辅助数组，与待排序数组一样大  
 
依次遍历待排序数组数字的每一位, 记录每一位中不同数值的出现次数, 以累加形式保存在count中, 相当于此数值在整体数组中的位置, **倒叙遍历待排数组**以位的大小进行数值的排放, 保存到排序数组.  

---
#### 荷兰国旗问题  
给定一个数组arr, 和一个数num, 请把小于num的数放在数组的左边，等于num的数放在数组的中间， 大于num的数放在数组的右边。  
要求额外空间复杂度O(1), 时间复杂度O(N)  
* 一次遍历，两个边界参数less, more  

#### 比较器  
当对结构进行排序的时候，如果没有比较器，则以内存地址的前后进行排序，没有意义。  
比较器中，如果返回正，第一个数将放在后面；负数, 第一个数放在前面； 0， 两个值相等。  
过段时间用C++来写  

#### 最大间隔  
给定一个数组，求如果排序之后，相邻两数的最大差值，要求时间复杂度O(N), 且要求不能用非基于比较的排序。

1. 计算数组中的最大值和最小值； 最大值==最小值， 返回0；
2. 3个桶：有无， 最小值， 最大值  
3. 求相邻有数值桶中的 后桶最小值 - 前桶最大值  

#### 小和问题  
给定一个数组中，每一个数左边比当前数小的数累加起来，叫做这个数组的小和。求一个数组的小和。  
1. 小和问题思想在于归并排序中，两个数组合并时，出现小于则小于那个数组的后面所有的数。  

#### KMP算法  
字符串source, 匹配字符串match, 求解match出现在字符串source中的第一个位置下标。  
1. KMP算法实现了O(source.length)的时间复杂度。  
2. 重点在构造辅助数组help[]上，不包含当前位置及后续的前段字符串， 字符串前缀和后缀的公共最大长度  
3. 其意义在于当souce[posi] != match[cn]时，可以通过cn = help[cn], 继续比较source[posi] 与 match[cn]，直到比较cn = 0后。  

#### Array to Stack Queue   
用数组结构实现大小固定的队列和栈
1. 栈一个index, 注意index是指向下一个该填写的位置  
2. 队列需要first, last, 还有数组当前存储数量的变量(signal), last： push的位置；first: pop的位置； 两者都递增  

#### GetMinStack  
实现一个特殊的栈，在实现栈的基础功能的基础上，再实现返回栈中最小元素的操作  
[要求]  
1. pop, push, getMin操作的时间复杂度都是O(1)  
2. 设计的栈类型可以使用现成的栈结构  

#### Code_StackAndQueueConvert  
如何仅用队列实现栈结构  
如何仅用栈实现队列结构  

#### DogCatQueue  
猫狗队列，宠物，狗，猫的类如下：
> - public class Pet { 
>        private String type;  
>        public Pet(String type) {  
>             this.type = type;  
>        }  
>        public String getPetType() {  
>              return this.type;
>        }
>   }  
> - public class Dog extends Pet {  
          public Dog() {
              super("dog");
          }
    }
> - public class Cat extends Pet {  
          public Cat() {  
              super("cat");
          }
    }  
[要求]：  
1. add 方法将cat类或dog类的实例放入队列中；  
2. 调用pollAll方法，将队列中所有的实例按照进队列的先后顺序依次弹出；  
3. 调用pollDog方法，将队列中dog类的实例按照进队列的先后顺序依次弹出；  
4. 调用pollCat方法，将队列中cat类的实例按照进队列的先后顺序依次弹出；  
5. 调用isEmpty方法，检查队列中是否还有dog或cat的实例；  
6. 用户可以调用isDogEmpty方法， 检查队列中是否有dog类的实例；  
7. 用户可以调用isCatEmpty方法， 检查队列中是否有cat类的实例；