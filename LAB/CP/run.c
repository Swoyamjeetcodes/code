#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void print_process_details(const char *label) {
    printf("%s: Process ID = %d, Parent ID = %d\n", label, getpid(), getppid());
}

int main() {
    print_process_details("Parent");

    pid_t fork1 = fork(); // First fork
    if (fork1 == 0) {
        // In child of first fork
        print_process_details("Child 1");

        pid_t fork2 = fork(); // Second fork from Child 1
        if (fork2 == 0) {
            // In child of second fork
            print_process_details("Child 1.1");
        } else if (fork2 > 0) {
            // In Child 1 after creating its own child
            print_process_details("Child 1 (After Fork 1.1)");
        }
    } else if (fork1 > 0) {
        // In parent after creating Child 1
        pid_t fork3 = fork(); // Third fork from Parent
        if (fork3 == 0) {
            // In child of third fork
            print_process_details("Child 2");
        } else if (fork3 > 0) {
            // In Parent after all forks
            print_process_details("Parent (After all forks)");
        }
    }
    return 0;
}
