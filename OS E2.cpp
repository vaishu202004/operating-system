#include <stdio.h> 
int main() 
{ 
int page_frames = 3; 
int page_reference_seq[] = {4, 1, 2, 4, 3, 2, 1, 5}; 
int num_pages = sizeof(page_reference_seq) / sizeof(int); 
int page_table[page_frames]; 
int page_faults = 0; 
int i, j, k; 
// Initialize page table with -1 
for (i = 0; i < page_frames; i++) 
{ 
page_table[i] = -1; 
} 
// Iterate over each page in the reference sequence 
for (i = 0; i < num_pages; i++) 
{ 
int page = page_reference_seq[i]; 
int page_found = 0; 
// Check if the page is already in the page table 
for (j = 0; j < page_frames; j++) 
{ 
if (page_table[j] == page) 
{ 
page_found = 1;
 break; 
} 
} 
// If the page is not in the page table, replace the oldest page 
if (!page_found) 
{
page_table[page_faults % page_frames] = page;
page_faults++; 
} 
// Print the current state of the page table 
for (k = 0; k < page_frames; k++) 
{ 
printf("%d ", page_table[k]); 
} 
printf("\n"); 
} 
printf("Total number of page faults: %d\n", page_faults); 
return 0; 
}
