#include<stdio.h>

int main() {
    int n_frames = 3;  // number of page frames
    int page_ref[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};  // page reference sequence
    int n_ref = sizeof(page_ref) / sizeof(page_ref[0]);  // number of page references
    int frames[n_frames];  // page frames
    int faults = 0;  // number of page faults
    int lru[n_frames];  // least recently used
    
    // Initialize frames to -1
    for(int i=0; i<n_frames; i++) {
        frames[i] = -1;
    }
    
    for(int i=0; i<n_ref; i++) {
        int page = page_ref[i];
        int hit = 0;
        
        // Check if page is already in frame
        for(int j=0; j<n_frames; j++) {
            if(frames[j] == page) {
                hit = 1;
                break;
            }
        }
        
        // If page is not in frame, find the least recently used page and replace it
        if(hit == 0) {
            faults++;
            
            // Find the least recently used page
            for(int j=0; j<n_frames; j++) {
                int k;
                for(k=i-1; k>=0; k--) {
                    if(frames[j] == page_ref[k]) {
                        break;
                    }
                }
                lru[j] = k;
            }
            
            int min = lru[0];
            int min_idx = 0;
            for(int j=1; j<n_frames; j++) {
                if(lru[j] < min) {
                    min = lru[j];
                    min_idx = j;
                }
            }
            
            // Replace least recently used page with current page
            frames[min_idx] = page;
        }
        
        // Print current frame
        printf("Page Reference: %d, Frame: ", page);
        for(int j=0; j<n_frames; j++) {
            if(frames[j] == -1) {
                printf(" ");
            }
            else {
                printf("%d", frames[j]);
            }
            printf(" ");
        }
        printf("\n");
    }
    
    printf("Total Page Faults = %d\n", faults);
    
    return 0;
}
