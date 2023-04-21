// Adam Tyton

class FRUIT_CLASS;
class TREE_CLASS;

class BRANCH_CLASS {

private:
        /** branch length */
        unsigned int bLen;
        unsigned int weight;

        /** fruits count */
        unsigned int fNum;
        // DBL fruits
        FRUIT_CLASS* head;
        FRUIT_CLASS* last;

        BRANCH_CLASS* prev;
        BRANCH_CLASS* next;

        TREE_CLASS *parent;
        /** tree height */
        unsigned int tHeight;

public:

        // CONSTRUCTOR

        BRANCH_CLASS();


        BRANCH_CLASS(
                TREE_CLASS* parent,
                BRANCH_CLASS* prev,
                BRANCH_CLASS* next
        );

        void CONSTRUCTOR(
                TREE_CLASS *parent,
                BRANCH_CLASS *prev,
                BRANCH_CLASS *next
                );

        // DESTRUCTOR

        ~BRANCH_CLASS();


        // GETTERS

        unsigned int getFruitsTotal();
        unsigned int getWeightsTotal();

        unsigned int getHeight();
        unsigned int getLength();

        FRUIT_CLASS* getFruitPointer(unsigned int inArea);
        TREE_CLASS* getTreePointer();

        // SETTERS

        void growthBranch();
        void fadeBranch();
        void harvestBranch(unsigned int weightMax);
        void cutBranch(unsigned int cutTo);


        // OTHER METHODS

        void decFWeight(unsigned int x);
        void addFWeight(unsigned int x);

        void decFNum(unsigned int x);
        void addFNum(unsigned int x);

        void pushFruit(FRUIT_CLASS* pFruit);
        void popFruit();

        BRANCH_CLASS* getPrev();
        BRANCH_CLASS* getNext();

        void setPrev(BRANCH_CLASS* pBranch);
        void setNext(BRANCH_CLASS* pBranch);

};