Name: Dhir Talati
Members: Richard Kumahia, Jonathan Vu
Class: EECE 4811
Professor: Michael Geiger


Part A:
    The Process for part B is a simple job, which we just called the fork()
    to duplicate the process. Here, what I implemented was an array of processids.
    This is an dynamic array and depends on the input of number of process,
    it will dynamically allocate the array.

    Interesting thing about fork() is, there are certain values it returns
    when it is called, and they are -1, 0, and ceratin id.

    0 basically means, creation of child process is successful and -1 means
    unsuccessful child process creation. If a number greater than 0 is 
    returned, it means, it's in the parent process.

    Normally, when we call fork(), the amount of child process created grows
    exponentially, 2^n to be excet, where n is how may times we call fork().
    It an huge mistake and it can destory the operating system.

    In order to protect that, we check the return id of the fork(), and if 
    the process is child, we come back or break the call of fork(), and return
    to main branch. 



    The regualr code without the loop is going be 
        int main(int argc, char* argv[]) {
            printf("Parent pid is %d\n", getpid());
            pid_t _child = fork();
            
            if(_child == 0){
                printf("Started child with pid %d\n", getpid());
            }
            if(wait(NULL)==-1){
                printf("Child (PID %d) finished.\n", getpid());
            }
            return 0;
        }

Part B:
    This is same process and Part A, but rather writing the fork() twice, we
    use loop to create child process twice.

    Since the array is allocated dynamically, we have to free the allocated 
    memory, and this must be in the main branch. So we check for it, and free
    the allocated memory.

    Code for the Part B:
        int main(int argc, char* argv[]) {
            pid_t pids[2];
            int stat = 0;
            printf("Parent pid is %d\n", getpid());

            int i;
            for(i = 0; i < 2; i++){
                pids[i] = fork();
                if(pids[i] == -1){
                printf("Error Creating Processes\n");
                return 1;
                }
            
                if(pids[i] == 0){
                int j = i + 1;
                printf("Started child %d with pid %d\n", j, getpid()); 
                exit(0);
                }
                
            }
            for(i = 0; i < 2; i++){
                wait(NULL);
                if(pids[i] == 0){
                    free(pids);
                }
                int st = waitpid(pids[i], &stat, 0);
                if( st != 0){
                int j = i + 1;
                printf("Child %d (PID %d) finished.\n", j, pids[i]);
                }
            }

            return 0;
        }

PartC:
    In the part, we just take the argument from the user by cmd prompt or terminal.
    The given value from the terminal is passed as sting to we use the atoi() function
    to covert string to int, so we can use for both pids array size and number of
    processes.

    From here the code can be seen in main.c.

Part D:
    So, when created multiple children process, we saved their id in pids array.
    From the array index, we can track which child was created first and which child
    was terminated first.

Part E & F:
    For these parts, it's just running with the given tests from 1 to 5.
    For convenience, I used those test 1 to 5 code as test1 to 5 functions.
    But I modified by adding passing pids[i], the process id.

    Part E can be run any number of process. You can un-comment the code in 
    main.c and run. If you wish to run Part E, please un-comment part E and 
    comment out Part F. This will give clear results.

    Part F, it works for 6 processes only, if you created more than 6, 
    the child with return some useless values.
    If you tried running part E, please comment out part E and un-comment
    part F, then run.
