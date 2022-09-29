#pragma once
#include "Node.h"

class Tree {
private:

    // Корень.
    Node* m_root;

    // Количество узлов.
    unsigned int m_size;

public:
    Tree();
    ~Tree();
    Node* GetRoot() const; // Получить корень.    
    void Insert(Node* node); // Вставка узла.   
    Node* Max(Node* node) const;  // Максимальное значение от указанного узла.  
    Node* Min(Node* node) const;  // Минимальное значение от указанного узла.
    Node* Next(const Node* node) const;  // Следующий узел для указанного узла.  
    Node* Previous(const Node* node) const; // Предыдущий узел для указанного узла.
    void Print(const Node* node) const;
    void Remove(Node* node);
    Node* Search(Node* node, const char* key) const;
    Node* Edit(Node* node);  
    Node* SaveFile();
};

