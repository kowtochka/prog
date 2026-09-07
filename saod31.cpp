#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
struct tree
{
    int data;
    tree *left;
    tree *right;
};
void Rlr(tree *rt);
void LRr(tree *rt);
void LrR(tree *rt);
int size(tree *rt);
int sum(tree *rt);
int Height(tree *rt);
int SumLenWay(tree *rt, int l);

int main(int argc, char const *argv[])
{
    srand(time(0));
    tree *root = new tree();
    root->data = rand() % 20 + 1;
    root->left = new tree();
    root->right = nullptr;
    root->left->data = rand() % 20 + 1;
    root->left->right = new tree();
    root->left->left = nullptr;
    root->left->right->data = rand() % 20 + 1;
    root->left->right->left = new tree();
    root->left->right->right = nullptr;
    root->left->right->left->data = rand() % 20 + 1;
    root->left->right->left->right = new tree();
    root->left->right->left->left = nullptr;
    root->left->right->left->right->data = rand() % 20 + 1;
    root->left->right->left->right->right = new tree();
    root->left->right->left->right->left = nullptr;
    root->left->right->left->right->right->data = rand() % 20 + 1;
    root->left->right->left->right->right->right = nullptr;
    root->left->right->left->right->right->left = nullptr;

    printf("\nКЛП:\n");
    Rlr(root);
    printf("\nЛКП:\n");
    LRr(root);
    printf("\nЛПК\n");
    LrR(root);
    printf("\nРазмер дерева:\n");
    printf("%d\n", size(root));
    printf("\nКС дерева:\n");
    printf("%d\n", sum(root));
    printf("\nВысота дерева:\n");
    printf("%d\n", Height(root));
    printf("\nСР Высота дерева:\n");
    printf("%.2f\n", float(SumLenWay(root, 1)) / size(root));
    return 0;
}
void Rlr(tree *rt)
{
    if (rt == NULL)
    {
        return;
    }

    printf("%d \n", rt->data);
    Rlr(rt->left);
    Rlr(rt->right);
}
void LRr(tree *rt)
{
    if (rt == NULL)
    {

        return;
    }
    LRr(rt->left);
    printf("%d \n", rt->data);
    LRr(rt->right);
}
void LrR(tree *rt)
{
    if (rt == NULL)
        return;
    LrR(rt->left);
    LrR(rt->right);
    printf("%d \n", rt->data);
}
int size(tree *rt)
{
    int n = 0;
    if (rt == nullptr)
        n = 0;
    else
    {
        n = 1 + size(rt->left) + size(rt->right);
    }
    return n;
}
int sum(tree *rt)
{
    int n = 0;
    if (rt == nullptr)
        n = 0;
    else
    {
        n = rt->data + sum(rt->left) + sum(rt->right);
    }
    return n;
}
int Height(tree *rt)
{
    int n = 0;
    if (rt == nullptr)
        n = 0;
    else
    {
        n = 1 + std::max((Height(rt->left)), Height(rt->right));
    }
    return n;
}
int SumLenWay(tree *rt, int l)
{
    int n = 0;
    if (rt == nullptr)
        n = 0;
    else
    {
        n = l + SumLenWay(rt->left, l + 1) + SumLenWay(rt->right, l + 1);
    }
    return n;
}
