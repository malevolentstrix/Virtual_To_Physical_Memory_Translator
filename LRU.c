#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

struct PageTable
{
  int frame_no;
  int last_time_of_access;
  bool valid;
};

bool isPagePresent(struct PageTable PT[], int page)
{
  if (PT[page].valid == 1)
    return true;
  return false;
}

void updatePageTable(struct PageTable PT[], int page, int fr_no, int status, int access_time)
{
  PT[page].valid = status;
  if (status == 1)
  {
    PT[page].last_time_of_access = access_time;
    PT[page].frame_no = fr_no;
  }
}

void printFrameContents(int frame[], int no_of_frames)
{
  for (int i = 0; i < no_of_frames; i++)
    printf("%d ", frame[i]);
  printf("\n");
}

void searchLRUPage(struct PageTable PT[], int frame[], int no_of_frames, int *LRU_page_index)
{
  int min = INT_MAX;
  for (int i = 0; i < no_of_frames; i++)
  {
    if (PT[frame[i]].last_time_of_access < min)
    {
      min = PT[frame[i]].last_time_of_access;
      *LRU_page_index = i;
    }
  }
}

int main()
{
  int i, n, no_of_frames, page_fault = 0, current = 0;
  bool flag = false;
  printf("\n Enter the no. of pages:\n");
  scanf("%d", &n);

  int reference_string[n];
  printf("\n Enter the reference string(different page numbers) :\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &reference_string[i]);
  printf("\n Enter the no. of frames you want to give to the process :");
  scanf("%d", &no_of_frames);

  int frame[no_of_frames];
  memset(frame, -1, no_of_frames * sizeof(int));
  struct PageTable PT[50];
  for (int i = 0; i < 50; i++)
    PT[i].valid = 0;

  printf("\n****The Contents inside the Frame array at different time:****\n");
  for (int i = 0; i < n; i++)
  {

    if (!(isPagePresent(PT, reference_string[i])))
    {
      page_fault++;
      if (flag == false && current < no_of_frames)
      {

        frame[current] = reference_string[i];
        printFrameContents(frame, no_of_frames);
        updatePageTable(PT, reference_string[i], current, 1, i);

        current = current + 1;
        if (current == no_of_frames)
        {

          flag = true;
        }
      }

      else
      {

        int LRU_page_index;
        searchLRUPage(PT, frame, no_of_frames, &LRU_page_index);
        updatePageTable(PT, frame[LRU_page_index], -1, 0, i);

        frame[LRU_page_index] = reference_string[i];
        printFrameContents(frame, no_of_frames);

        updatePageTable(PT, reference_string[i], LRU_page_index, 1, i);
      }
    }

    PT[reference_string[i]].last_time_of_access = i;
  }

  printf("\nTotal No. of Page Faults = %d\n", page_fault);
  printf("\nPage Fault ratio = %.2f\n", (float)page_fault / n);
  printf("\nPage Hit Ratio = %.2f\n", (float)(n - page_fault) / n);
  return 0;
}