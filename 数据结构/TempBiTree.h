#pragma once
typedef struct BiTNode               // 定义二叉树节点结构
{
char data;                       // 数据域
struct BiTNode* LChild, * RChild;  // 左右孩子指针域
}BiTNode, * BiTree;
