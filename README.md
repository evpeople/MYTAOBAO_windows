# MYTAOBAO_windows

A cpp homework of Bupt 

## 设计V1
1. 使用文件存取用户数据。用户数据包括用户id，用户姓名，用户密码，用户类型，用户登录与否，对密码进行哈希处理。
    1.1 不同类型的用户用不同的文件存储信息。 
2. 修改密码，修改密码前需要做身份验证
3. 人物分为用户，商家和未登录用户。
    3.1 也就是说登录操作只是注销当前用户，登录新用户。
4. 商品与商家绑定，首页每次使用随机数选择商家的商品展示（考虑拓展性）
5. 购物与消费者绑定，不同的消费者不同的的文件，不同的商家不同的文件

## 设计V2
1. 商品新增冻结属性

## 设计V3
（商家是特别的用户，多了商品管理）

（q退出当前所在的目录（也就是当前的死循环））

1. 事件驱动型服务（展示商品不是一个事件，而是在任何情况下都有的一段输出）
2. 初始界面的事件是注册，登录
3. 注册界面的事件是输入用户名，密码，用户类型。
4. 登录界面的事件（通用的是展示商品和更改密码，消费）
   1.   对于用户，有个人信息和购物
   2.   个人信息是查询余额，充值
   3.   购物是查看商品，搜索商品，购买商品。
   4.   搜索商品则要求输入不同的商品类别。
   5.   购买商品，则输入商品的数量。
5. 商家而言
    1. 除了上面的所有的，还有商品信息管理系统
    2. 进入之后，输入要更改什么，是数量还是价格，还是下架。
6. 更改BaseUsr，目前的实现不满足要求

仍需要一个默认的用户。（其实不需要，就是一个某默认的指针就行

| 方法                         | 基类           | 用户                       | 商家                 | 默认用户 |
| ---------------------------- | -------------- | -------------------------- | -------------------- | -------- |
| 构造                         | 添加名字，密码 | 添加id，类型，文件夹       | 添加id，类型。文件夹 |          |
| 登录=0(确权)                 |                | 不同的文件里搜索相应的信息 |                      |          |
| getType=0                    |                |                            |                      |          |
| 加密                         | 基类实现       |                            |                      |          |
| 存储=0                       |                | 子类实现                   | 子类实现             |          |
| 改密（改完之后要再次存储）=0 | 子类实现       |                            |                      |          |
| 余额查询（虚函数             |                | 实现                       |                      |          |
| 添加商品（虚函数             |                |                            | 实现                 |          |
| 搜索Server实现               |                |                            |                      |          |
| 商品消息管理（虚函数         |                |                            | 商人的对象数组       |          |
| 打折（虚函数                 |                |                            | 实现                 |          |

商品

| 方法               | 基类                   | 子类                                 |
| ------------------ | ---------------------- | ------------------------------------ |
| 构造器             | 价格，名字，序号，个数 | 添加静态的货物类型，静态的折扣，描述 |
| 设置折扣（静态     |                        |                                      |
| 计算价钱=0         |                        |                                      |
| get原价（virtual） |                        |                                      |

