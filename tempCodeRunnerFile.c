         while (seconds > 0) {
             //printf("%d...\n", seconds);

            printf("\r");  // move cursor to position 0
            printf("%d Minutes %d Seconds", minute, seconds);
            fflush(stdout);  // flush the output of stdout
            

            sleep(1);
            seconds--;
         }