// Alex Prior
// U54686687

#ifndef __MYBST_H__
#define __MYBST_H__

#include <vector>
#include "BST.h"

class MyBST : public BST
{
    using BST::BST;

public:
    vector<Rotation> transform(MyBST target);
    Node *searchBST(Node *, int);

private:
    void rotateRight(Node *Q);
    void rotateLeft(Node *P);
};

#endif /* __MYBST_H__*/