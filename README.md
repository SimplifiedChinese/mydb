# mydb
A DBMS, the most complex Manage System I've created,in my view

mydb是一个非常简单的关系型数据库管理系统，支持数据查询语言DQL，数据操纵语言DML，数据定义语言DDL三种常见的SQL语句。包括SQL语句解析模块、数据查询操纵模块、数据结构定义模块、数据持久化支持模块四个主要组成部分。下面是每个模块的详细介绍部分：

## SQL语句解析模块

SQL 语句的解析利用 FLex/Bison 根据词法、语法规则自动解析 SQL 命令。程序会从标准输入读取信息。SQL 的词法和语法分析参考了开源项目的实现。语法分析的过程会建立抽象语法树，在结束一条语句的处理后会释放抽象语法树的内存。整个解析模块在 sql_parser目录中。该目录还包含解析器和数据库管理系统的接口定义。

表达式计算是在处理查询语句是一个可能需要的操作，我们实现了一个 expression 类用于保存计算结果。在 iterate 函数中，每遍历到一个记录就会将其内容加入到一个缓存中。之后根据语法分析树计算表达式的值的时候如果需要读取对某个列的引用就会在缓存中进行读取。

针对表达式的计算，我们采取了LALR（1）分析的策略，通俗来讲，就是向右多看一个词儿，当然值得注意的是，这些表达式的计算会影响到select的效率。

## 数据查询操纵模块

数据库支持的基本类型有：
• 整型（INT）
• 浮点型（FLOAT）
• 字符串型（VARCHAR），上限为256
• 日期型（DATE），日期格式为 “YYYY-MM-dd”。
日期类型的字面值和字符串相同，在实现中如果必要可以转换为字符串，但是这里并没有完成

实现了五种聚集查询函数 COUNT、SUM、AVG、MIN 和 MAX。其中 COUNT 不支持DISTINCT 关键字。

注意select语句，其只能实现往下一条一条翻页，判断是否完成

## 数据结构定义模块

其实本来是要做B+树索引支持的，试试失败了，索引结构告一段落

表结构方面。每个表分为两个部分存储，表头单独存储为一个文件，表项和索引通过页式文件系统存储为一个文件。表头主要包含各个列的信息，以及完整性约束的信息。特别需要注意的是 CHECK 约束的表达式信息被转换为波兰式存储以及解析。列的信息包含列名、列类型、列长度、列在对应记录中的存储偏移量以及列是否有索引等约束信息。

## 数据持久化支持模块

页式文件系统是最基本的结构，依赖于操作系统的文件管理。一个页的大小为 4KB，一个文件的读写均按照页为单位。为了读写的效率，我们采用缓存机制，每次访问页后会缓存在内存中，并且写操作不会马上写入文件。缓存的替换方法为当其填满后会将最少访问的一个写回文件。属于典型的LRU算法。

本人还尝试实现时钟算法，但是考虑到其带来的好处不值一提，最后放弃了。

2020.5.16

这个星期以来写了很多东西，主要是多线程一块的，在我眼里，使用C++实现多线程其实并不复杂，但是在运行的却屡屡碰壁，究其原因，我发现其实很简单，我所上的锁并不是以真正的表，这个东西实现多线程的最好方法，就是吧数据块所在的页进行加锁，这样介于表和行之间，相比起来应该更好。但是，我发现更不妙的事，那就是：死锁了！！！