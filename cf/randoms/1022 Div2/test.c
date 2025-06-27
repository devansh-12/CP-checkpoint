#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define PAGE_SIZE 4096
#define PHYS_MEM_SIZE 65536  // 64KB physical memory
#define DISK_SIZE 131072     // 128KB disk space

// Memory structures
uint8_t physical_mem[PHYS_MEM_SIZE];
uint8_t disk[DISK_SIZE];

// Paging structures
typedef struct {
    uint32_t frame;
    uint8_t valid;
} PageTableEntry;

PageTableEntry page_table[1024];  // 4KB pages in 32-bit space

// Segmentation structures
typedef struct {
    uint32_t base;
    uint32_t limit;
    uint8_t valid;
} SegmentTableEntry;

SegmentTableEntry seg_table[4];  // 4 segments

void init_memory_systems() {
    for(int i=0; i<1024; i++) page_table[i].valid = 0;
    for(int i=0; i<4; i++) seg_table[i].valid = 0;
}

void handle_paging(uint32_t virtual_addr) {
    uint32_t page_num = virtual_addr / PAGE_SIZE;
    uint32_t offset = virtual_addr % PAGE_SIZE;
    
    printf("\n\033[1;34m=== Paging Translation ===\033[0m\n");
    printf("Virtual Address: %u\n", virtual_addr);
    printf("Calculation:\n");
    printf("Page Number = Virtual Address / Page Size\n");
    printf("            = %u / %u = %u\n", virtual_addr, PAGE_SIZE, page_num);
    printf("Offset      = Virtual Address %% Page Size\n");
    printf("            = %u %% %u = %u\n\n", virtual_addr, PAGE_SIZE, offset);
    
    if(page_table[page_num].valid) {
        uint32_t phys_addr = (page_table[page_num].frame * PAGE_SIZE) + offset;
        printf("Page Table Entry:\n");
        printf("Frame Number: %u (Valid: %s)\n", page_table[page_num].frame,
               page_table[page_num].valid ? "Yes" : "No");
        printf("Physical Address = Frame * Page Size + Offset\n");
        printf("                 = %u * %u + %u\n", 
               page_table[page_num].frame, PAGE_SIZE, offset);
        printf("\033[1;32mPhysical Address: %u\033[0m\n", phys_addr);
    } else {
        printf("\033[1;31mPage Fault: Page %u not in memory\033[0m\n", page_num);
    }
}

void handle_segmentation(uint32_t virtual_addr, uint8_t seg_num) {
    printf("\n\033[1;34m=== Segmentation Translation ===\033[0m\n");
    printf("Segment Number: %u\n", seg_num);
    
    if(seg_num >= 4 || !seg_table[seg_num].valid) {
        printf("\033[1;31mSegmentation Fault: Invalid segment %u\033[0m\n", seg_num);
        return;
    }
    
    uint32_t offset = virtual_addr;
    printf("Segment Limit Check:\n");
    printf("Offset: %u, Segment Limit: %u\n", offset, seg_table[seg_num].limit);
    
    if(offset > seg_table[seg_num].limit) {
        printf("\033[1;31mSegment Overflow: Offset exceeds limit by %u bytes\033[0m\n",
               offset - seg_table[seg_num].limit);
        return;
    }
    
    uint32_t phys_addr = seg_table[seg_num].base + offset;
    printf("Physical Address = Base + Offset\n");
    printf("                 = %u + %u\n", seg_table[seg_num].base, offset);
    printf("\033[1;32mPhysical Address: %u\033[0m\n", phys_addr);
}

void demonstrate_fragmentation() {
    printf("\n\033[1;34m=== Fragmentation Analysis ===\033[0m\n");
    
    // Internal fragmentation example
    uint32_t small_allocation = 100;
    uint32_t pages_needed = (small_allocation + PAGE_SIZE - 1) / PAGE_SIZE;
    uint32_t wasted = (pages_needed * PAGE_SIZE) - small_allocation;
    printf("Internal Fragmentation Example:\n");
    printf("Process needs %u bytes (%.1f KB)\n", small_allocation, small_allocation/1024.0);
    printf("Pages required: %u (%u KB each)\n", pages_needed, PAGE_SIZE/1024);
    printf("Wasted space = (Pages * Page Size) - Process Size\n");
    printf("             = (%u * %u) - %u = %u bytes\n\n", 
           pages_needed, PAGE_SIZE, small_allocation, wasted);
    
    // External fragmentation simulation
    printf("External Fragmentation Example:\n");
    printf("Initial free memory: %u bytes\n", PHYS_MEM_SIZE);
    printf("Allocating 2KB block...\n");
    uint32_t free_mem = PHYS_MEM_SIZE - 2048;
    printf("Allocating 4KB block...\n");
    free_mem -= 4096;
    printf("Remaining free memory: %u bytes\n", free_mem);
    printf("Memory layout: [2KB|4KB|...%uKB free (non-contiguous)...]\n", free_mem/1024);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <virtual_address>\n", argv[0]);
        return 1;
    }

    init_memory_systems();
    uint32_t virtual_addr = atoi(argv[1]);
    
    // Configure sample entries
    page_table[4].valid = 1;
    page_table[4].frame = 2;
    seg_table[0].valid = 1;
    seg_table[0].base = 0;
    seg_table[0].limit = 4096;
    
    printf("\033[1;36m\nInitial Memory Configuration:\033[0m");
    printf("\n- Page 4 mapped to Frame 2");
    printf("\n- Segment 0: Base=0, Limit=4096\n");
    
    handle_paging(virtual_addr);
    handle_segmentation(virtual_addr % 4096, 0);
    demonstrate_fragmentation();
    
    return 0;
}
