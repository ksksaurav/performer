
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100
 
struct node
{
    char data; 
    int freq;
    struct node *left;
    struct node *right; 
};
 
struct Heap
{
    int size;   
    int Limit;  
    struct node **array;
};
 
struct node* newNode(char data, int freq)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data=data;
    newNode->freq=freq;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
 
struct Heap* BuildHeap(int Limit)
{
    struct Heap* Heap = (struct Heap*) malloc(sizeof(struct Heap));
    Heap->size=0;  
    Heap->Limit=Limit;
    Heap->array=(struct node**)malloc(Heap->Limit * sizeof(struct node*));
    return Heap;
}
 
void swapnode(struct node** a, struct node** b)
{
    struct node* t = *a;
    *a = *b;
    *b = t;
}
 
void Heapify(struct Heap* Heap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
 
    if (left < Heap->size &&
        Heap->array[left]->freq < Heap->array[smallest]->freq)
      smallest = left;
 
    if (right < Heap->size &&
        Heap->array[right]->freq < Heap->array[smallest]->freq)
      smallest = right;
 
    if (smallest != idx)
    {
        swapnode(&Heap->array[smallest], &Heap->array[idx]);
        Heapify(Heap, smallest);
    }
}
 
int isSizeOne(struct Heap* Heap)
{
    return (Heap->size == 1);
}
 
struct node* extractMin(struct Heap* Heap)
{
    struct node* temp = Heap->array[0];
    Heap->array[0] = Heap->array[Heap->size - 1];
    --Heap->size;
    Heapify(Heap, 0);
    return temp;
}
 
void insertHeap(struct Heap* Heap, struct node* node)
{
    ++Heap->size;
    int i = Heap->size - 1;
    while (i && node->freq < Heap->array[(i - 1)/2]->freq)
    {
        Heap->array[i] = Heap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    Heap->array[i] = node;
}
 
void buildHeap(struct Heap* Heap)
{
    int n = Heap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        Heapify(Heap, i);
}
 
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}
 
int isLeaf(struct node* root)
{
    return !(root->left) && !(root->right) ;
}
 
struct Heap* createAndBuildHeap(char data[], int freq[], int size)
{
    int i;
    struct Heap* Heap = BuildHeap(size);
    for (i = 0; i < size; ++i)
        Heap->array[i] = newNode(data[i], freq[i]);
    Heap->size = size;
    buildHeap(Heap);
    return Heap;
}
 
// The main function that builds Huffman tree
struct node* buildHuffmanTree(char data[], int freq[], int size)
{
    struct node *left, *right, *top;
 
    // Step 1: Create a min heap of Limit equal to size.  Initially, there are
    // modes equal to size.
    struct Heap* Heap = createAndBuildHeap(data, freq, size);
 
    // Iterate while size of heap doesn't become 1
    while (!isSizeOne(Heap))
    {
        // Step 2: Extract the two minimum freq items from min heap
        left = extractMin(Heap);
        right = extractMin(Heap);
 
        // Step 3:  Create a new internal node with frequency equal to the
        // sum of the two nodes frequencies. Make the two extracted node as
        // left and right children of this new node. Add this node to the min heap
        // '$' is a special value for internal nodes, not used
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertHeap(Heap, top);
    }
 
    // Step 4: The remaining node is the root node and the tree is complete.
    return extractMin(Heap);
}
 
// Prints huffman codes from the root of Huffman Tree.  It uses arr[] to
// store codes
void printCodes(struct node* root, int arr[], int top)
{
    // Assign 0 to left edge and recur
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
 
    // Assign 1 to right edge and recur
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
 
    // If this is a leaf node, then it contains one of the input
    // characters, print the character and its code from arr[]
    if (isLeaf(root))
    {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}
 
// The main function that builds a Huffman Tree and print codes by traversing
// the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
   //  Construct Huffman Tree
   struct node* root = buildHuffmanTree(data, freq, size);
 
   // Print Huffman codes using the Huffman tree built above
   int arr[MAX_TREE_HT], top = 0;
   printCodes(root, arr, top);
}
 
// Driver program to test above functions
int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}