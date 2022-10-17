#include<stdio.h>

struct NodeBinaryTree {
    int info;
    struct NodeBinaryTree* left;
    struct NodeBinaryTree* right;
};
typedef struct NodeBinaryTree* NODE;


void initTree(NODE &pRoot) {
    pRoot = NULL;
}

bool isEmptyTree (NODE pRoot) {
    return (pRoot == NULL);
}

NODE createNode (int info) {
    NODE node = new NodeBinaryTree;
    node->info = info;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert (NODE &pRoot, int info) {
    if( !isEmptyTree(pRoot) ){
        if(pRoot->info< info)
            insert(pRoot->right, info);
        else if(pRoot->info > info)
            insert(pRoot->left, info);
    }else{
        pRoot = createNode(info);
    }
}

void remove (NODE &pRoot, int info) {
    if (pRoot == NULL)
        delete pRoot;
    if(pRoot->info > x )
        return remove(pRoot->left, info);
    else if(pRoot->info < x)
        return remove(pRoot->right, info);
    else
        NODE p = pRoot;
        if(pRoot->left == NULL)   // NODE left is empty
            pRoot = pRoot->right;
        else if(pRoot->right == NULL)   //NODE right is empty
            pRoot = pRoot->left;
        else{   //NODE have two NODE
            NODE t = p;
            NODE rp = p->left; // Bắt đầu bên trái
            while(rp != NULL){
                rp = rp->right;
            }

        }
        

}

//Printf the tree
void BinaryTreeNLR(NODE pRoot) {

    // if( !isEmptyTree(pRoot) ){
        
    //     NLR(pRoot->left);
    //     NLR(pRoot->right);
    // }

 
}

void turnLeft (NODE &pRoot) {
    NODE ya = pRoot;
    NODE x = ya->right;
    ya->right = x->left;
    x->left = ya;
    pRoot = x;
}

void turnRight (NODE &pRoot) {
    NODE ya = pRoot;
    NODE x = ya->left;
    ya->left = x->right;
    x->right = ya;
    pRoot = x;
}

void NLR (NODE pRoot){
    if( !isEmptyTree(pRoot) ){
        printf("%d ", pRoot->info);
        NLR(pRoot->left);
        NLR(pRoot->right);
    }
}

void LNR (NODE pRoot){
    if( !isEmptyTree(pRoot) ){
        LNR(pRoot->left);
        printf("%d ", pRoot->info);
        LNR(pRoot->right);
    }
}

void LRN (NODE pRoot){
    if( !isEmptyTree(pRoot) ){
        LRN(pRoot->left);
        LRN(pRoot->right);
        printf("%d ", pRoot->info);
    }
}

void menu () {
    printf("\n\n0.Exit\n");
    printf("1.Addition an element. \n");
    printf("2.PreOrder. \n");
    printf("3.InOrder. \n");
    printf("4.PostOrder. \n");
    printf("5.Turn Right. \n");
    printf("6.Turn Left \n");
    printf("Please enter options: ");
}

int main () {
    NODE pRoot;
    initTree(pRoot);
    int info;
    int choice;

    do{ 
        menu();
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 0:
                break;
            case 1:
                printf("-----------------Addition an element------------------\n");
                printf("Please enter an element: ");
                scanf("%d", &info);
                insert(pRoot, info);
                break;
            case 2:
                printf("-----------------PreOrder------------------\n");
                NLR(pRoot);
                break;
            case 3:
                printf("-----------------InOrder------------------\n");
                LNR(pRoot);
                break;
            case 4:
                printf("-----------------PostOrder------------------\n");
                LRN(pRoot);
                break;
            case 5:
                printf("-----------------Turn Right------------------\n");
                turnRight(pRoot);
                break;
            case 6:
                printf("-----------------Turn Left------------------\n");
                turnLeft(pRoot);
                break;
            default:
                choice = 0;
        }
    }while(choice != 0);

    return 0;
}