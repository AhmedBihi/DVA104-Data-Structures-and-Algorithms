#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

int main()
{
    Tree *tree = createTree();
    FILE *fp;
    clock_t tstart, tend;
	time_t t;
    srand((unsigned) time(&t));
	double favg;
    int data = 0, menu = 0, i = 0;

    if(tree == NULL)
        printf("Memory allocation failed...");

    system("color 6");

    while(1){
        printf("Menu\n#1 Insert\n#2 Remove\n#3 Find node\n#4 Print \n");
        printf("#5 Tree height\n#6 Theoretical min. height\n#7 Tree node count\n");
        printf("#8 Balance tree\n#9 Clear tree\n#10 End session\n");
        printf("#11 Insert million\n#12 Insert 500 grand\n#13 50 grand\n> ");
        scanf("%d", &menu);
        switch(menu)
        {
        case 1:
            while(1)
            {
                printf("insert data: ");
                scanf("%d", &data);
                if(data == -1)
                    break;
                insert(tree, data);
            }
            break;
        case 2:
            printf("Remove: ");
            scanf("%d", &data);
            tree_remove(tree, data);
            break;
        case 3:
            tstart = clock(); // start
            find_tree(tree);
            tend = clock(); // end
            /* compute average execution time */
            favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
            printf("Avg. execution time: %g sec\n",favg);
            break;
        case 4:
            printf("Preorder:  ");
            tree_preorder(tree);

            printf("\nInorder:   ");
            tree_inorder(tree);

            printf("\nPostorder: ");
            tree_postorder(tree);
            printf("\n");
            break;
        case 5:
            i = tree_height(tree);
            printf("Tree height: %d\n", i);
            break;
        case 6:
            i = theoretical_min(tree);
            printf("Theoretical min. height = %d\n", i);
            break;
        case 7:
            i = tree_size(tree);
            printf("Tree size: %d\n", i);
            break;
        case 8:
            tree_to_arr(tree);
            break;
        case 9:
            clear_tree(tree);
            printf("Tree is now empty!\n");
            break;
        case 10:
            destroyTree(tree);
            printf("See ya...");
            return 0;
            break;
        case 11:
            fp = fopen("5mil.txt", "r");
            if(fp == NULL)
            {
                fprintf(stderr, "error\n");
                return 1;
            }
            tstart = clock(); // start
            for(i = 0; i < 5000000; ++i){
                fscanf(fp,"%d\n", &data);
                insert(tree, data);
            }
            tend = clock(); // end

            /* compute average execution time */
            favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
            printf("Avg. execution time: %g sec\n",favg);
            break;
        case 12:
            fp = fopen("500tus.txt", "r");
            if(fp == NULL)
            {
                fprintf(stderr, "error\n");
                return 1;
            }
            tstart = clock(); // start
            for(i = 0; i < 500000; ++i){
                fscanf(fp,"%d\n", &data);
                insert(tree, data);
            }
            tend = clock(); // end

            /* compute average execution time */
            favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
            printf("Avg. execution time: %g sec\n",favg);
            break;
        case 13:
            fp = fopen("50tus.txt", "r");
            if(fp == NULL)
            {
                fprintf(stderr, "error\n");
                return 1;
            }
            tstart = clock(); // start
            for(i = 0; i < 50000; ++i){
                fscanf(fp,"%d\n", &data);
                insert(tree, data);
            }
            tend = clock(); // end

            /* compute average execution time */
            favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
            printf("Avg. execution time: %g sec\n",favg);
            break;
        default:
            printf("Not a menu choice!\n");
            break;
        }
        i = 0;
        fflush(stdin);
    }

    destroyTree(tree);
    return 0;
}
