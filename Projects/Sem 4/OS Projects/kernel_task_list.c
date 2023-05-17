#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Linux Kernel Module for Listing Tasks");

static int __init task_list_init(void) {
    struct task_struct *task;
    printk(KERN_INFO "Task List Module Initialized\n");
    
    // Traverse the task list
    for_each_process(task) {
        printk(KERN_INFO "PID: %d, Name: %s, State: %ld\n", task->pid, task->comm, task->state);
    }
    
    return 0;
}

static void __exit task_list_exit(void) {
    printk(KERN_INFO "Task List Module Terminated\n");
}

module_init(task_list_init);
module_exit(task_list_exit);
