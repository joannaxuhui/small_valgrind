#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mini_valgrind.h"

#undef malloc
#undef free

/*
 * Replace normal malloc, this malloc will also create meta data info
 * and insert it to the head of the list.
 * You have to malloc enough size to hold both the size of your allocated
 * and the meta_data structure.
 *
 * @param size
 *	Size of the memory block, in bytes.
 * @param file
 *	Name of the file that uses mini_valgrind to detect memory leak.
 * @param line
 *	Line in the file that causes memory leak
 *
 * @return
 *	On success, return a pointer to the memory block allocated by
 *	the function. Note that this pointer should return the actual
 *	address the pointer starts and not the meta_data.
 *
 *	If the function fails to allocate the requested block of memory,
 *	return a null pointer.
 */
<<<<<<< .mine
void *mini_malloc(size_t size, const char *file, size_t line) {



  // your code here
  return NULL;
=======
void *mini_malloc(size_t size, const char *file, size_t line){

	meta_data* md = malloc(sizeof(meta_data)+size);
	md->size = size;
	strncpy(md->file_name, file, MAX_FILENAME_LENGTH);
	md->line_num = line;
	md->address = md+1;
	total_usage += size;
	insert_meta_data(md, size, file,  line);
	return md->address;
>>>>>>> .r21572
}

/*
 * Replace normal free, this free will also delete the node in the list.
 *
 * @param ptr
 *	Pointer to a memory block previously allocated. If a null pointer is
 *	passed, no action occurs.
 */
void remove_meta_data(void *ptr) {
	//remove_meta_data(ptr);
  // your code here
   ptr=NULL;
}

/*
 * Helper function to insert the malloc ptr node to the list.
 * Accumulate total_usage here.
 *
 * @param md
 * 	Pointer to the meta_data
 * @param size
 *	Size of the memory block, in bytes.
 * @param file
 *	Name of the file that uses mini_valgrind to detect memory leak.
 * @param line
 *	Line in the file that causes memory leak
 */
void insert_meta_data(meta_data *md, size_t size, const char *file, size_t line) {
	//md = (meta_data*)mini_malloc(size, file, line)-1;
	(void) file;
	(void) size;
	(void) line;

	md->next=head;
	head=md;



  
  /* set value for malloc_info*/
}

/*
 * Helper function to remove the free ptr node from the list.
 * Add to total_free here.
 *
 * @param ptr
 *	Pointer to a memory block previously allocated.
 */
void mini_free(void *ptr) {

if(head == NULL  && ptr!= NULL)
	{
		bad_frees += 1;
		return;
	}
if( ptr == NULL)
	{
		return;
	}

if(head-> address == ptr)
{
	meta_data * p=head;
	head = head ->next;
	total_free += p->size;
	free(p);
	return;
}

meta_data * temp = head;
while( temp -> next !=NULL)
{
	if(temp ->next ->address == ptr)
	{
		meta_data* temp1 = temp->next;
		temp -> next = temp1->next;
		total_free += temp1->size;
		free(temp1);
		return;
	}
	temp=temp->next;
}
	if(temp == NULL)
	bad_frees +=1;
	return;
}

/*
 * Deletes all nodes from the list. Called when the program exits so make sure
 * to not count these blocks as freed.
 */
void destroy() {

	meta_data* track = head;
	while(head != NULL) {
		head=head->next;
		free (track);
		track=head;
	}

	head=NULL;
	total_usage=0;
	total_free=0;
	bad_frees=0;
  // your code here
}

/*
 * Print mini_valgrind leak report. DO NOT TOUCH THIS. You risk failing the
 * autograder if you do.
 */
void print_report() {
  meta_data *leak_info;

  FILE *fp_write = fopen("result.txt", "wt");

  size_t total_leak = 0;

  if (fp_write != NULL) {
    fprintf(fp_write, "Heap report:\n\n");
    leak_info = head;
 
   while (leak_info != NULL) {
      total_leak += leak_info->size;
      fprintf(fp_write, "\tLeak file %s : line %zu\n", leak_info->file_name, leak_info->line_num);
      fprintf(fp_write, "\tLeak size : %zu bytes\n", leak_info->size);
      fprintf(fp_write, "\tLeak memory address : %p\n", leak_info->address);
      fputs("\n", fp_write);
      leak_info = leak_info->next;
    }

    fprintf(fp_write, "\nProgram made %zu bad call(s) to free.\n", bad_frees);
    fprintf(fp_write, "\nHeap summary:\n\n");
    fprintf(fp_write, "\tTotal memory usage: %zu bytes, Total memory free: %zu bytes\n", total_usage, total_free);
    if (total_leak != 0) {
      fprintf(fp_write, "\tTotal leak: %zu bytes\n", total_leak);
    } else {
      fprintf(fp_write, "\tNo leak, all memory are freed, Congratulations!\n");
    }
    fclose(fp_write);
  }
  destroy();
}
