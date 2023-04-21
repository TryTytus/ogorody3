// Adam Tyton

class BRANCH_CLASS;
class GARDEN_CLASS;

class TREE_CLASS {
    private:

    GARDEN_CLASS* parent;

    unsigned int treeID;
    unsigned int tHeight;

    /** fruits count */
    unsigned int fNum;
    unsigned int weight;

    /** branches count */
    unsigned int bNum;
    BRANCH_CLASS* head;
    BRANCH_CLASS* last;

    TREE_CLASS* prev;
    TREE_CLASS* next;

public:

    // CONSTRUCTOR

    TREE_CLASS();

    TREE_CLASS(
            unsigned int treeID,
            unsigned int tHeight,
            TREE_CLASS* prev,
            TREE_CLASS* next,
            GARDEN_CLASS* parent
            );

    void CONSTRUCTOR(
            unsigned int treeID,
            unsigned int tHeight,
            TREE_CLASS* prev,
            TREE_CLASS* next,
            GARDEN_CLASS* parent
            );

    // DESTRUCTOR

    ~TREE_CLASS();

    // ------- GETTERS -------

    unsigned int getBranchesTotal ();
    unsigned int getFruitsTotal ();
    unsigned int getWeightsTotal ();

    unsigned int getNumber ();
    unsigned int getHeight ();

    GARDEN_CLASS* getGardenPointer ();
    BRANCH_CLASS* getBranchPointer (unsigned int height);

    // ------- SETTERS -------

    void growthTree ();
    void fadeTree ();
    void harvestTree (unsigned int weightMax);
    void cutTree (unsigned int cutTo);
    void cloneBranch (BRANCH_CLASS* pBranch);


        // OTHER METHODS

    void decFWeight(unsigned int x);
    void addFWeight(unsigned int x);

    void decFNum(unsigned int x);
    void addFNum(unsigned int x);

    void decBNum(unsigned int x);
    void addBNum(unsigned int x);

    void pushBranch(BRANCH_CLASS* pBranch);
    void popBranch();


        TREE_CLASS* getPrev();
        TREE_CLASS* getNext();

        void setPrev(TREE_CLASS* pTree);
        void setNext(TREE_CLASS* pTree);
};