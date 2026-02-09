#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_solution(int *nums, int *selected, int size)
{
	int first = 1;

	for (int i = 0; i < size; i++)
	{
		if (selected[i])
		{
			if (!first)
				printf(" ");
			printf("%d", nums[i]);
			first = 0;
		}

	}
	printf("\n");
}

void find_combi(int *nums, int *selected, int target, int size, int idx, int current_sum)
{
	if (size == idx)
	{
		if (target == current_sum)
			print_solution(nums, selected, size);
		return;
	}

	selected[idx] = 0;
	find_combi(nums, selected, target, size,idx +1, current_sum);
	selected[idx] = 1;
	find_combi(nums, selected, target, size, idx+1, current_sum + nums[idx]); 
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return 1;
	int size = argc - 2;
	int nums[size];
	int selected[size];
	int target = atoi(argv[1]);
	
	for (int i = 0; i < size; i++)
	{
		nums[i] = atoi(argv[2 +i]);
		selected[i] = 0;
	}
	find_combi(nums, selected, target, size, 0, 0);
	return 0;
}
