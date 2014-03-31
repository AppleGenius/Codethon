# region using ....
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
# endregion 

// 静态构造函数在C#中的应用
// 在调用B类型的代码之前先执行B的静态构造函数，静态构造函数先初始化类型的静态变量，
// 再执行函数体内的语句。因此先打印a1再打印a3，接下来执行B b = new B(); 即调用B
// 的普通构造函数，构造函数先初始化成员变量，在执行函数体内的语句，因此先后打印出
// a2,a4


namespace StaticConstructor
{
    class A
    {
        public A(string text)
        {
            Console.WriteLine(text);
        }
    }

    class B
    {
        static A a1 = new A("a1");
        A a2 = new A("a2");

        static B()
        {
            a1 = new A("a3");
        }

        public B()
        {
            a2 = new A("a4");
        }
    }
    
    class Program
    {
        static void Main(string[] args)
        {
            B b = new B();
        }
    }
}
