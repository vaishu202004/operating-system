#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int pages[MAX_PAGES] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};

int main() {
    int frames[MAX_FRAMES], future[MAX_FRAMES], faults = 0, count = 0;

    for(int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
        future[i] = MAX_PAGES;
    }

    for(int i = 0; i < MAX_PAGES; i++) {
        int page = pages[i], max_future = -1, max_future_index = -1, j;

        for(j = 0; j < MAX_FRAMES; j++) {
            if(frames[j] == page) {
                break;
            }

            if(future[j] > max_future) {
                max_future = future[j];
                max_future_index = j;
            }
        }

        if(j == MAX_FRAMES) {
            frames[max_future_index] = page;
            future[max_future_index] = i;
            faults++;
        } else {
            future[j] = i;
        }

        printf("After page %d : ", page);
        for(int j = 0; j < MAX_FRAMES; j++) {
            if(frames[j] == -1) {
                printf(" - ");
            } else {
                printf("%2d ", frames[j]);
            }
        }
        printf("\n");
    }

    printf("\nNumber of Page Faults = %d\n", faults);
    return 0;
}
