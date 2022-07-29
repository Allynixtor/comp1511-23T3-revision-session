#include "testlib.h"
#include <cassert>
#include <set>
using namespace std;

int N, answer, when;
int child[100005][2];
int label[100005], upto;

void label_inorder(int u) {
    if (u == 0) return;
    label_inorder(child[u][0]);
    if (u == when) upto += answer;
    else upto += answer + rnd.next(1,10); 
    label[u] = upto;
    label_inorder(child[u][1]);
}

void print_preorder(int u) {
    if (u == 0) return;
    printf("%d", label[u]);
    if (label[u] != N) printf(" "); 
    print_preorder(child[u][0]);
    print_preorder(child[u][1]);
}

int main(int argc, char** argv) {
	registerGen(argc, argv, 1);
	assert(argc == 4);
    double a = stod(argv[1]);
	double b = stod(argv[2]);
    N = atoi(argv[3]);
    answer = rnd.next(1, 10000);
    when = rnd.next(2, N);
	for (int v = 2; v <= N; v++) {
        int u, dir;
        do {
            u = rnd.next((int)(1+(v-2)*a), (int)(1+(v-2)*b));
            dir = rnd.next(0, 1);
        } while (child[u][dir] != 0);
		child[u][dir] = v;
	}
	
    label_inorder(1);
    print_preorder(1);
}