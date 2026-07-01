#include <iostream>
#include <string>
using namespace std;

// أقصى عدد حروف يمكن التعامل معهم = 256 (كل قيم char الممكنة في ASCII)
const int MAX_CHARS = 256;

// هيكل العقدة (node) في شجرة هافمان
struct Node 
{
    char ch;          // الحرف (بيتحدد بس لو العقدة ورق)
    int freq;         // عدد مرات ظهور الحرف
    Node* left;       // العقدة اللي على الشمال
    Node* right;      // العقدة اللي على اليمين
};

// دالة بسيطة جداً: تعمل عقدة جديدة وترجع عنوانها
// left و right يتم ضبطهم على nullptr تلقائياً
Node* createNode(char c, int f) 
{
    Node* node = new Node;
    node->ch = c;
    node->freq = f;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// دالة بتقول إذا كانت العقدة ورق (ملهاش أبناء) ولا لأ
bool isLeaf(Node* n)
{
    if (n == nullptr)
    {
        return false;
    }

    return n->left == nullptr && n->right == nullptr;
}

// دالة تمسح الشجرة كلها عشان ما تبقاش ذاكرة معلقة
void deleteTree(Node* node) 
{
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left);   // امسح الشمال أولاً
    deleteTree(node->right);  // امسح اليمين تاني
    delete node;              // امسح العقدة نفسها
}

// جداول عامة عشان نخزن فيها المعلومات
int freqTable[MAX_CHARS];        // تكرار كل حرف
string codeTable[MAX_CHARS];     // الكود بتاع كل حرف
bool used[MAX_CHARS];            // الحرف ظهر في النص ولا لأ

// الخطوة 1: نحسب عدد مرات ظهور كل حرف في النص
void calculateFrequencies(const string& text) 
{
    // نمسح أي قيم قديمة
    for (int i = 0; i < MAX_CHARS; i++) 
    {
        freqTable[i] = 0;
        used[i] = false;
    }

    // نلف على كل حرف في النص ونزود العداد
    int length = text.size();
    for (int i = 0; i < length; i++) 
    {
        int index = (unsigned char)text[i];   // نحول الحرف لرقم عشان نستخدمه كفهرس
        freqTable[index]++;
        used[index] = true;
    }
}

// الخطوة 2 و 3: بناء شجرة هافمان
Node* buildHuffmanTree() 
{
    // قائمة (مصفوفة) تحتوي كل العقد اللي لسه موجودة
    Node* nodes[MAX_CHARS];
    int nodeCount = 0;

    // نعمل عقدة ورق لكل حرف ظهر في النص
    for (int i = 0; i < MAX_CHARS; i++) 
    {
        if (used[i]) 
        {
            Node* leaf = createNode((char)i, freqTable[i]);
            nodes[nodeCount] = leaf;
            nodeCount++;
        }
    }

    // لو في حرف واحد بس، نضيف أب وهمي عشان الشجرة تبقى شجرة
    if (nodeCount == 1) 
    {
        Node* root = createNode('\0', nodes[0]->freq);
        root->left = nodes[0];
        return root;
    }

    // نكرر لحد ما يبقى عندنا عقدة واحدة (الجذر)
    while (nodeCount > 1) 
    {
        // 1- ندور على أصغر عقدة (أقل تكرار)
        int min1 = 0;
        for (int i = 1; i < nodeCount; i++) 
        {
            if (nodes[i]->freq < nodes[min1]->freq)
            {
                min1 = i;
            }
        }
        Node* first = nodes[min1];
        // نشيلها من المصفوفة: نضع آخر عنصر مكانها ونقلل العدد
        nodes[min1] = nodes[nodeCount - 1];
        nodeCount--;

        // 2- ندور على تاني أصغر عقدة
        int min2 = 0;
        for (int i = 1; i < nodeCount; i++) 
        {
            if (nodes[i]->freq < nodes[min2]->freq) 
            {
                min2 = i;
            }
        }
        Node* second = nodes[min2];
        nodes[min2] = nodes[nodeCount - 1];
        nodeCount--;

        // 3- ندمج العقدتين في عقدة أب جديدة (مجموع التكرارات)
        Node* parent = createNode('\0', first->freq + second->freq);
        parent->left = first;
        parent->right = second;

        // 4- نضيف العقدة الجديدة للقائمة
        nodes[nodeCount] = parent;
        nodeCount++;
    }

    // آخر عقدة متبقية هي جذر الشجرة
    return nodes[0];
}

// الخطوة 4: نطلع الكود بتاع كل حرف عن طريق السير في الشجرة (باستخدام الـ recursion)
void generateCodes(Node* node, string path) 
{
    if (node == nullptr) 
    {
        return;
    }

    // لو وصلنا لورقة، خزن الكود بتاع الحرف
    if (isLeaf(node)) 
    {
        // لو النص كان حرف واحد بس، المسار هيكون فاضي، فخلّيه "0"
        if (path == "") 
        {
            path = "0";
        }
        int index = (unsigned char)node->ch;
        codeTable[index] = path;
        return;
    }

    // روح شمال (ضيف 0)
    string leftPath = path;
    leftPath += "0";
    generateCodes(node->left, leftPath);

    // روح يمين (ضيف 1)
    string rightPath = path;
    rightPath += "1";
    generateCodes(node->right, rightPath);
}

// الخطوة 5: تشفير النص باستخدام جدول الأكواد
string encode(const string& text) 
{
    string result = "";
    int length = text.size();
    for (int i = 0; i < length; i++) 
    {
        int index = (unsigned char)text[i];
        result += codeTable[index];
    }
    return result;
}

// الخطوة 6: فك التشفير (نرجع النص الأصلي من البتات)
string decode(const string& encodedText, Node* root) 
{
    string result = "";
    Node* temp = root;   // نبدأ من الجذر

    // حالة خاصة: لو الشجرة كلها ورق واحد (حرف واحد)
    if (isLeaf(root)) 
    {
        // كل بت بيمثل نفس الحرف، نرجع الحرف ده عدد البتات
        int length = encodedText.size();
        for (int i = 0; i < length; i++) 
        {
            result += root->ch;
        }
        return result;
    }

    // نمشي على كل بت في النص المشفر
    int length = encodedText.size();
    for (int i = 0; i < length; i++) 
    {
        if (encodedText[i] == '0') 
        {
            temp = temp->left;     // بت 0 → روح شمال
        }
        else 
        {
            temp = temp->right;    // بت 1 → روح يمين
        }

        // لو وصلنا لورقة، نضيف الحرف ونرجع للجذر تاني
        if (isLeaf(temp)) 
        {
            result += temp->ch;
            temp = root;
        }
    }
    return result;
}

// دالة تطبع جدول الحروف وتكراراتها وأكوادها
void printTable() 
{
    cout << "Character | Frequency | Huffman Code" << endl;
    cout << "-----------|-----------|--------------" << endl;
    for (int i = 0; i < MAX_CHARS; i++) 
    {
        if (used[i]) 
        {
            string display;
            if (i == ' ') 
            {
                display = "' '";
            }
            else if (i == '\n') 
            {
                display = "\\n";
            }
            else 
            {
                display = "";
                display += (char)i;
            }
            cout << "   " << display << "   |    " << freqTable[i] << "     | " << codeTable[i] << "\n";
        }
    }
}

// الدالة الرئيسية
int main() 
{ string text; cout << "Enter text to compress: "; 
    getline(cin, text);
    if (text.size() == 0)
    { 
        cout << "Empty input, nothing to encode." << endl;
        return 0; 
    }

    // 1- حساب التكرارات
    calculateFrequencies(text);

    // 2- بناء الشجرة
    Node* root = buildHuffmanTree();

    // 3- استخراج الأكواد
    generateCodes(root, "");

    // 4- تشفير النص
    string encoded = encode(text);

    // 5- فك التشفير للتحقق
    string decoded = decode(encoded, root);

    // طباعة النتائج
    printTable();

    cout << "Original text : " << text << endl;
    cout << "Encoded bits : " << encoded << endl;
    cout << "Decoded text : " << decoded << endl;

    if (decoded == text) 
    {
     cout << "Decoding correct? YES" << endl; 
    } 
    else 
    { 
        cout << "Decoding correct? NO" << endl; 
    }

    // إحصائيات الضغط
    int originalBits = (int)text.size() * 8;
    int compressedBits = (int)encoded.size();

    cout << "--- Compression Stats ---" << endl;
    cout << "Original size : " << originalBits << " bits" << endl;
    cout << "Compressed size : " << compressedBits << " bits" << endl;

    if (originalBits > 0) 
    {
        double ratio = (double)compressedBits / originalBits;
        double savings = (1 - ratio) * 100;
        cout << "Space saved       : " << savings << "%";
    }

    // تنظيف الذاكرة
    deleteTree(root);

    return 0;
}