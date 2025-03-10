# C++11有两种方式来等待线程结束：

## **detach方式:**
启动的线程自主在后台运行，当前的代码继续往下执行，不等待新线程结束。前面代码所使用的就是这种方式。

调用detach表示thread对象和其表示的线程完全分离；

分离之后的线程是不在受约束和管制，会单独执行，直到执行完毕释放资源，可以看做是一个daemon线程；
分离之后thread对象不再表示任何线程；
分离之后joinable() == false，即使还在执行；



## **join方式:**
等待启动的线程完成，才会继续往下执行。假如前面的代码使用这种方式，其输出就会0,1,2,3，因为每次都是前一个线程输出完成了才会进行下一个循环，启动下一个新线程。

只有处于活动状态线程才能调用join，可以通过joinable()函数检查;

joinable() == true表示当前线程是活动线程，才可以调用join函数；
默认构造函数创建的对象是joinable() == false;
join只能被调用一次，之后joinable就会变为false，表示线程执行完毕；
调用 ternimate()的线程必须是 joinable() == false;
如果线程不调用join()函数，即使执行完毕也是一个活动线程，即joinable() == true，依然可以调用join()函数