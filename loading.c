#include <stdio.h>
// #include <time.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void cross_platform_sleep(unsigned int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds); // Windows uses Sleep in ms
#else
    usleep(milliseconds * 1000); // usleep takes microseconds
#endif
}

// clock_t start, end;

void loading_screen(const char *loading_text, int seconds) {
    // start = clock();
    int i,j,temp, pos = 0, dir = 1;
    int len = strlen(loading_text);
    int steps = seconds * 8.4; // 10 steps per second (each step is 0.1s)

    printf("\033[?25l");         // Hide cursor

    for ( j = 0; j < steps; j++) {
        printf("\r");
        for (i = 0; i < len; i++) {
            if (i == pos) {
                printf("\033[%dm%c\033[0m", 41 + j % 7, loading_text[i]); // Highlight moving char
            } else {
                printf("%c", loading_text[i]);
            }
        }

        // Show percentage at specific steps (optional pattern preserved)
        int percent = (j * 100) / steps;

        if (percent < 14 || (percent > 20 && percent < 38) || 
            (percent > 49 && percent < 66) || (percent > 77 && percent < 87) || 
            percent > 92) {
            temp=percent;
            printf(" %d%%", percent);
        }
        else printf(" %d%%", temp);

        fflush(stdout);
        pos += dir;
        if (pos > len - 2 || pos < 1) dir *= -1;
        cross_platform_sleep(100);  // 0.1 second delay
    }

    printf("\r\033[32m%s 100%%\033[0m",loading_text);
    fflush(stdout);
    cross_platform_sleep(500);  // 0.5 second delay
    printf("\033[?25h\033[2K\r"); // Show cursor again
    // end = clock();
}

int main() {
    int a,b,sum;
    printf("Enter two intiger: ");
    scanf("%d%d", &a,&b);
    sum=a+b;
    loading_screen("Calculating...",20);
    printf("Sum of %d & %d is %d",a,b,sum);
    // printf("\nTime taken: %.2f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}