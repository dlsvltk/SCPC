/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>

struct stack {
	char p[1000001];
	int index[1000001];
	int top = 0;
};
struct stack_p {
	int f[1000001];
	int l[1000001];
	int top = 0;
};
stack s;
stack_p prev;
char p[1000001];

int Answer;

int main(void)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using scanf function.
	You may remove the comment symbols(//) in the below statement and use it.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
	// freopen("input.txt", "r", stdin);

	/*
	If you remove the statement below, your program's output may not be rocorded
	when your program is terminated after the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%s", p);
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		int cur_f = -2, cur_l = -2;
		s.top = 0;
		prev.top = 0;
		Answer = 0;
		for (int i = 0; p[i] != 0; i++) {
			if (p[i] == '(') {
				//push
				if (cur_l == i - 1) {
					prev.f[prev.top] = cur_f;
					prev.l[prev.top] = cur_l;
					prev.top++;
				}
				s.p[s.top] = 1;
				s.index[s.top] = i;
				s.top++;
			}
			else if (p[i] == '{') {
				//push
				if (cur_l == i - 1) {
					prev.f[prev.top] = cur_f;
					prev.l[prev.top] = cur_l;
					prev.top++;
				}
				s.p[s.top] = 2;
				s.index[s.top] = i;
				s.top++;
			}
			else if (p[i] == '[') {
				//push
				if (cur_l == i - 1) {
					prev.f[prev.top] = cur_f;
					prev.l[prev.top] = cur_l;
					prev.top++;
				}
				s.p[s.top] = 3;
				s.index[s.top] = i;
				s.top++;
			}
			else if (p[i] == ')') {
				//pop
				if (s.top != 0) {
					if (s.p[s.top-1] == 1) {
						s.top--; 
						cur_f = s.index[s.top];
						cur_l = i;
						//prev
						while (prev.top != 0 && prev.l[prev.top-1]+1 == cur_f ) {
							prev.top--;
							cur_f = prev.f[prev.top];
						}
						if (Answer < cur_l - cur_f + 1) Answer = cur_l - cur_f + 1;
						
					}
					else {
						if (cur_l == i - 1) {
							prev.f[prev.top] = cur_f;
							prev.l[prev.top] = cur_l;
							prev.top++;
						}
						s.top = 0;
					}
				}
			}
			else if (p[i] == '}') {
				if (s.top != 0) {
					if (s.p[s.top-1] == 2) {
						s.top--;
						cur_f = s.index[s.top];
						cur_l = i;
						//prev
						while (prev.top != 0 && prev.l[prev.top-1] + 1 == cur_f) {
							prev.top--;
							cur_f = prev.f[prev.top];
						}
						if (Answer < cur_l - cur_f + 1) Answer = cur_l - cur_f + 1;
					}
					else {
						if (cur_l == i - 1) {
							prev.f[prev.top] = cur_f;
							prev.l[prev.top] = cur_l;
							prev.top++;
						}
						s.top = 0;
					}
				}
			}
			else {
				if (s.top != 0) {
					if (s.p[s.top-1] == 3) {
						s.top--;
						cur_f = s.index[s.top];
						cur_l = i;
						//prev
						while (prev.top != 0 && prev.l[prev.top-1] + 1 == cur_f) {
							prev.top--;
							cur_f = prev.f[prev.top];
						}
						if (Answer < cur_l - cur_f + 1) Answer = cur_l - cur_f + 1;
					}
					else {
						if (cur_l == i - 1) {
							prev.f[prev.top] = cur_f;
							prev.l[prev.top] = cur_l;
							prev.top++;
						}
						s.top = 0;
					}
				}
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}
