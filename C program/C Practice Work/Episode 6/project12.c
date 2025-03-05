#include <stdio.h>
#include <string.h>

// 定义8个任务函数
void task0() { printf("task0 is called!\n"); }
void task1() { printf("task1 is called!\n"); }
void task2() { printf("task2 is called!\n"); }
void task3() { printf("task3 is called!\n"); }
void task4() { printf("task4 is called!\n"); }
void task5() { printf("task5 is called!\n"); }
void task6() { printf("task6 is called!\n"); }
void task7() { printf("task7 is called!\n"); }

// 定义函数指针类型
typedef void (*TaskFunc)();

// schedule函数，返回函数指针数组和数组大小
void schedule(TaskFunc** tasks, int* size) {
    static TaskFunc taskArray[] = { task0, task1, task2, task3, task4, task5, task6, task7 };
    *tasks = taskArray;
    *size = sizeof(taskArray) / sizeof(taskArray[0]);
}

// execute函数，调用schedule函数并按用户输入的序列顺序执行函数
void execute(const char* sequence) {
    TaskFunc* tasks;
    int size;
    schedule(&tasks, &size);
    int len = strlen(sequence);
    for (int i = 0; i < len; ++i) {
        int taskIndex = sequence[i] - '0'; // 将字符转换为对应的任务索引
        if (taskIndex >= 0 && taskIndex < size) {
            tasks[taskIndex]();
        }
    }
}

int main() {
    char sequence[100]; // 假设用户输入的序列长度不会超过100
    scanf("%s", sequence); // 使用scanf获取用户输入的序列
    execute(sequence);
    return 0;
}